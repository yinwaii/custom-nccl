/*
 * @Author: yinwai
 * @Date:   2023-03-03 10:46:34
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:18:32
 */

#include "pci.h"
#include "strutils.h"

namespace nccl {
	namespace xml {
		float PCI::loadSpeed() {
			float deviceSpeed = parseStr<float>(fromSys(path, "max_link_speed"));
			float portSpeed = parseStr<float>(fromSys(path, "../max_link_speed"));
			return std::min(deviceSpeed, portSpeed);
		}
		int PCI::loadWidth() {
			int deviceWidth = parseStr<int>(fromSys(path, "max_link_width"));
			int portWidth = parseStr<int>(fromSys(path, "../max_link_width"));
			return std::min(deviceWidth, portWidth);
		}
	}
}