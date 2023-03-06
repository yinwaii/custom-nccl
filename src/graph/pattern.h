/*
 * @Author: yinwai
 * @Date:   2023-03-06 14:53:10
 * @Last Modified by:   yinwai
 * @Last Modified time: 2023-03-06 15:18:53
 */

#ifndef NCCL_PATTERN_H_
#define NCCL_PATTERN_H_

#include "devcomm.h"

template <int algo>
struct Algo {
	static constexpr int id = algo;
	static constexpr bool standard = true;
};

template <>
struct Algo<NCCL_ALGO_RING> {
	static constexpr int id = NCCL_ALGO_RING;
	static constexpr bool standard = true;
};

template <>
struct Algo<NCCL_ALGO_TREE> {
	static constexpr int id = NCCL_ALGO_TREE;
	static constexpr bool standard = true;
};

template <>
struct Algo<NCCL_ALGO_COLLNET_CHAIN> {
	static constexpr int id = NCCL_ALGO_COLLNET_CHAIN;
	static constexpr bool standard = false;
};

template <>
struct Algo<NCCL_ALGO_COLLNET_DIRECT> {
	static constexpr int id = NCCL_ALGO_COLLNET_DIRECT;
	static constexpr bool standard = false;
};

template <>
struct Algo<NCCL_ALGO_NVLS> {
	static constexpr int id = NCCL_ALGO_NVLS;
	static constexpr bool standard = false;
};

template <int proto>
struct Proto {
	static constexpr int id = proto;
	static constexpr int maxThreads = 512;
	static constexpr int minThreads = 2 * WARP_SIZE;
	static constexpr int nonStandardThreads = maxThreads;
};

template <>
struct Proto<NCCL_PROTO_SIMPLE> {
	static constexpr int id = NCCL_PROTO_SIMPLE;
	static constexpr int maxThreads = 512;
	static constexpr int minThreads = 2 * WARP_SIZE;
	static constexpr int nonStandardThreads = maxThreads;
};

template <>
struct Proto<NCCL_PROTO_LL> {
	static constexpr int id = NCCL_PROTO_LL;
	static constexpr int maxThreads = 512;
	static constexpr int minThreads = 2 * WARP_SIZE;
	static constexpr int nonStandardThreads = 0;
};

template <>
struct Proto<NCCL_PROTO_LL128> {
	static constexpr int id = NCCL_PROTO_LL128;
	static constexpr int maxThreads = 640;
	static constexpr int minThreads = maxThreads / 4;
	static constexpr int nonStandardThreads = 0;
};


#endif