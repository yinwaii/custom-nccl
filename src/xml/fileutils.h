/*
 * @Author: yinwai
 * @Date:   2023-03-02 16:48:12
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 10:38:40
 */

#pragma once

#include "common.h"
#include <fstream>

namespace nccl
{
	namespace xml
	{
		string fromSys(const string &path, const string &filename) {
			string result;
			std::ifstream ifs(path + "/" + filename);
			if (ifs.is_open()) {
				getline(ifs, result);
				ifs.close();
			}
			return result;
		}
	}
}