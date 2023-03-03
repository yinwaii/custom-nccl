/*
 * @Author: yinwai
 * @Date:   2023-03-03 09:55:15
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:39:04
 */

#pragma once
#include "common.h"
#include "fileutils.h"
#include "node.h"

namespace nccl {
	namespace xml {
		class PCI: public XmlNode {
			private:
				string busId;
				string path;
				string classId;
				string vendor;
				string device;
				string subVendor;
				string subDevice;
				float speed;
				int width;

			public:
				string loadClassId() { return fromSys(path, "class"); }
				string loadVendor() { return fromSys(path, "vendor"); }
				string loadDevice() { return fromSys(path, "device"); }
				string loadSubVendor() { return fromSys(path, "subsystem_vendor"); }
				string loadSubDevice() { return fromSys(path, "subsystem_device"); }
				float loadSpeed();
				int loadWidth();
		};
	}
}