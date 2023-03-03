/*
 * @Author: yinwai
 * @Date:   2023-03-02 15:15:44
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 14:56:48
 */

#include "common.h"
#include "node.h"

namespace nccl {
	namespace xml {
		class GPU: public XmlNode {
			private:
				int dev; // NVML dev number
				int rank;
				int cudaCompCap;
				int gdrSupport;
			public:
				int loadDev() const;
				int loadRank() const;
				int loadCudaCompCap() const;
				int loadGdrSupport() const;
		};
	}
}