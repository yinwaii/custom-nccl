/*
 * @Author: yinwai
 * @Date:   2023-03-02 11:20:56
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:50:54
 */

#pragma once

#include "common.h"

namespace nccl {
	namespace xml {
		class XmlNode;
		using XmlNodePtr = shared_ptr<XmlNode>;
		using XmlNodeViewPtr = weak_ptr<XmlNode>;
		
		class XmlNode {
		private:
			template <typename T>
			struct Attr {
				constexpr string name;
				T value;
				void loadValue() {
					value = parseStr<T>(attrs.at(name));
				}
				void loadStrValue() {
					attrs.at(name) = to_string(value);
				}
			};
			enum class Type { NONE, OPEN, CLOSE, SINGLE };
			string name;
			Type type;
			unordered_map<string, string> attrs;
			XmlNodeViewPtr parent;
			vector<XmlNodeViewPtr> subs;

		public:
			XmlNode() = default;
			template <typename T>
			T getAttr(const string &attrName);
			template <typename T>
			T getAttr(const string &attrName, const T &defaultValue);
			XmlNodeViewPtr getSub(const string &subName);
			template <typename T>
			XmlNodeViewPtr getSub(const string &subName, const string &attrName, const T &attrValue);
			template <typename T>
			void setAttr(const string &attrName, const T &value);
			template <typename T>
			void setAttrIfUnset(const string &attrName, const T &value);
			~XmlNode();
			friend class Xml;
		};
	}
}