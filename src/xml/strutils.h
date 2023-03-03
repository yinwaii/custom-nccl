/*
 * @Author: yinwai
 * @Date:   2023-03-02 10:58:29
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:04:16
 */

#pragma once

#include "common.h"

namespace nccl {
	namespace xml {
		vector<string> split(const string &str, char delim) {
			vector<string> result;
			stringstream ss(str);
			string item;
			while (getline(ss, item, delim)) {
				result.push_back(item);
			}
			return result;
		}

		template <typename T>
		inline T parseStr(const string &str) { return T(str); }

		template <>
		inline int parseStr<int>(const string &str) { return stoi(str); }

		template <>
		inline float parseStr<float>(const string &str) { return stof(str); }

		template <>
		inline double parseStr<double>(const string &str) { return stod(str); }

		template <>
		inline bool parseStr<bool>(const string &str) { return str == "true"; }

		template <>
		inline string parseStr<string>(const string &str) { return str; }
		
		// template <typename T>
		// inline vector<T> parseStr<vector<T>>(const string &str) {
		// 	vector<T> result;
		// 	vector<string> strs = split(str, ',');
		// 	for (int i = 0; i < strs.size(); i++) {
		// 		result.push_back(parseStr<T>(strs[i]));
		// 	}
		// 	return result;
		// }
	}
}