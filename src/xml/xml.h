/*
 * @Author: yinwai
 * @Date:   2023-03-02 10:05:20
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-02 14:41:00
 */

#pragma once

#include "common.h"
#include "node.h"

namespace nccl {
	namespace xml {
		class Xml {
		private:
			shared_ptr<XmlNode> root;
			int maxIndex;
		public:
			Xml();
			XmlNodeViewPtr findTag(const string& tagName);
			XmlNodeViewPtr findTag(const string& tagName, const string& attrName, const string& attrValue);
			~Xml();
		};
	}
}