/*
 * @Author: yinwai
 * @Date:   2023-03-02 10:36:50
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-02 14:41:15
 */

#include "xml.h"

namespace nccl {
	namespace xml {
		Xml::Xml() {
			root = make_shared<XmlNode>();
			maxIndex = 0;
		}
		XmlNodeViewPtr Xml::findTag(const string& tagName) {
			return root->getSub(tagName);
		}
		XmlNodeViewPtr Xml::findTag(const string& tagName, const string& attrName, const string& attrValue) {
			return root->getSub(tagName, attrName, attrValue);
		}
		Xml::~Xml() {
			root.reset();
		}
	}
}