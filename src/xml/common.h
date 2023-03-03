/*
 * @Author: yinwai
 * @Date:   2023-03-02 10:12:09
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-03 11:30:10
 */

#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <unordered_map>

namespace nccl {
	using string = std::string;
	template <typename T>
	using vector = std::vector<T>;
	using stringstream = std::stringstream;
	template <typename T>
	using shared_ptr = std::shared_ptr<T>;
	template <typename T>
	using weak_ptr = std::weak_ptr<T>;
	template <typename T>
	using make_shared = std::make_shared<T>;
	template <typename K, typename V>
	using unordered_map = std::unordered_map<K, V>;
}