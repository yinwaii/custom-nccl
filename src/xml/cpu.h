/*
 * @Author: yinwai
 * @Date:   2023-03-02 15:04:25
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 10:45:29
 */

#pragma once
#include "common.h"
#include <sched.h>

namespace nccl {
	namespace xml {
		struct Bandwidth
		{
			static constexpr float LOC = 5000.0;
			static constexpr float SM60_NVLINK = 18.0;
			static constexpr float SM70_NVLINK = 22.0;
			static constexpr float SM80_NVLINK = 22.0;
			static constexpr float SM86_NVLINK = 12.0;
			static constexpr float PCI = 12.0;
			static constexpr float QPI = 6.0;
			static constexpr float SKL_QPI = 9.0;
			static constexpr float ZPI = 6.0;
			static constexpr float YONGFENG_ZPI = 9.0;
			static constexpr float P9 = 32.0;
			static constexpr float ARM = 6.0;
			static constexpr float NET = 12.0;
		};
		class CPU {
		private:
			enum class Arch { X86, POWER, ARM, OTHER } arch;
			enum class Vendor { INTEL, AMD, ZHAOXIN, OTHER } vendor;
			enum class Model { BDW, SKL, YONGFENG = BDW } model;
			int numaId;
			int familyId, modelId;
			float getInterCpuBw();
			Arch loadArch();
			Vendor loadVendor();
			Model loadModel();
		};
	}
}