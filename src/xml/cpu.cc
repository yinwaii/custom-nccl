/*
 * @Author: yinwai
 * @Date:   2023-03-02 16:06:03
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 10:45:20
 */

#include "cpu.h"
#include "fileutils.h"

namespace nccl {
	namespace xml {
		float CPU::getInterCpuBw() {
			switch (arch) {
				case Arch::POWER:
					return Bandwidth::P9;
				case Arch::ARM:
					return Bandwidth::ARM;
				case Arch::X86:
					switch(vendor) {
						case Vendor::INTEL:
							switch(model) {
								case Model::SKL:
									return Bandwidth::SKL_QPI;
								default:
									return Bandwidth::QPI;
							}
						case Vendor::ZHAOXIN:
							switch(model) {
								case Model::YONGFENG:
									return Bandwidth::YONGFENG_ZPI;
								default:
									return Bandwidth::ZPI;
							}
					}
				default:
					return Bandwidth::LOC;
			}
		}
		CPU::Arch CPU::loadArch() {
			// Fill CPU type / vendor / model
#if defined(__PPC__)
			return Arch::POWER;
#elif defined(__aarch64__)
			return Arch::ARM;
#elif defined(__x86_64__)
			return Arch::X86;
#else
			return Arch::OTHER;
#endif
		}
		CPU::Vendor CPU::loadVendor() {
			union {
				struct {
					// CPUID 0 String register order
					uint32_t ebx;
					uint32_t edx;
					uint32_t ecx;
				};
				char vendor[12];
			} cpuid0;
			asm volatile("cpuid" : "=b" (cpuid0.ebx), "=c" (cpuid0.ecx), "=d" (cpuid0.edx) : "a" (0) : "memory");
			if (strncmp(cpuid0.vendor, "GenuineIntel", 12) == 0) return Vendor::INTEL;
			if (strncmp(cpuid0.vendor, "AuthenticAMD", 12) == 0) return Vendor::AMD;
			if (strncmp(cpuid0.vendor, "ZHAOXIN", 12) == 0) return Vendor::ZHAOXIN;
			return Vendor::OTHER;
		}
		CPU::Model CPU::loadModel() {
			union {
				struct {
					unsigned steppingId:4;
					unsigned modelId:4;
					unsigned familyId:4;
					unsigned processorType:2;
					unsigned resv0:2;
					unsigned extModelId:4;
					unsigned extFamilyId:8;
					unsigned resv1:4;
				};
				uint32_t val;
			} cpuid1;
			asm volatile("cpuid" : "=a" (cpuid1.val) : "a" (1) : "memory");
			familyId = cpuid1.familyId + (cpuid1.extFamilyId << 4);
			modelId = cpuid1.modelId + (cpuid1.extModelId << 4);
			switch (familyId) {
				case 6:
					switch (modelId) {
						case 0x5E:
							return Model::SKL;
						case 0x5C:
							return Model::YONGFENG;
						default:
							return Model::BDW;
					}
				default:
					return Model::BDW;
			}
		}
	}
}