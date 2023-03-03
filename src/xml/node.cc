/*
 * @Author: yinwai
 * @Date:   2023-03-02 11:22:41
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:34:21
 */

#include "node.h"
#include "strutils.h"

namespace nccl {
	namespace xml {
		template <typename T>
		T XmlNode::getAttr(const string &attrName) {
			return parseStr<T>(attrs.at(attrName));
		}
		template <typename T>
		T XmlNode::getAttr(const string &attrName, const T &defaultValue) {
			if (!attrs.count(attrName)) {
				return defaultValue;
			}
			return parseStr<T>(attrs.at(attrName));
		}
		XmlNodeViewPtr XmlNode::getSub(const string &subName) {
			for (int i = 0; i < subs.size(); i++) {
				if (subs[i].lock()->name == subName) {
					return subs[i];
				}
			}
			return XmlNodeViewPtr();
		}
		template <typename T>
		XmlNodeViewPtr XmlNode::getSub(const string &subName, const string &attrName, const T &attrValue) {
			for (int i = 0; i < subs.size(); i++) {
				auto sub = subs[i].lock();
				if (sub && sub->name == subName && sub->getAttr<T>(attrName) == attrValue) {
					return subs[i];
				}
			}
			return XmlNodeViewPtr();
		}
		template <typename T>
		void XmlNode::setAttr(const string &attrName, const T &value) {
			attrs[attrName] = to_string(value);
		}
		template <typename T>
		void XmlNode::setAttrIfUnset(const string &attrName, const T &value) {
			if (!attrs.count(attrName)) {
				attrs[attrName] = to_string(value);
			}
		}
		XmlNode::~XmlNode() {
			subs.clear();
		}
	}
}