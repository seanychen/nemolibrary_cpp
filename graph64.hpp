#ifndef GRAPH64_HPP
#define GRAPH64_HPP

#include <iostream>
using std::cout; using std::cerr; using std::endl;
#include <stdexcept>
using std::domain_error;
#include <vector>
using std::vector;
#include <string>
using std::string;


extern "C" {
#include <cstdio>
}

typedef uint_fast64_t uint64;
typedef uint64 graph64;
typedef uint64 edge;
typedef uint_fast64_t vertex;
typedef int edgetype;

const edgetype NOEDGE_UV = 0;
const edgetype DIR_U_T_V = 1;
const edgetype DIR_V_T_U = 2;
const edgetype UNDIR_U_V = 3;
const int INDEG = 0;
const int OUDEG = 1;
const vertex NILLVERTEX = 0xFFFFFFFFUL;

inline edge new_edge(vertex u, vertex v)
{
    return uint64(u) << 32 | uint64(v);
}

inline edge edge_code(vertex u, vertex v)
{
    if (u < v) {
	return uint64(u) << 32 | uint64(v);
    } else {
	return uint64(v) << 32 | uint64(u);
    }
}

inline vertex edge_get_u(edge e)
{
    return vertex(e >> 32);
}

inline vertex edge_get_v(edge e)
{
    return vertex(e & 0xFFFFFFFFULL);
}

inline edgetype reverse(edgetype et)
{
    return (et >> 1) | ((et << 1) & 2);
}

void adj(graph64 g);

inline void DEL(graph64 &g, long row, long col) {
	(g &= ~(1ULL << (63-(row*8+col))));
}

inline void SET(graph64 &g, long row, long col) {
	(g |=  (1ULL << (63-(row*8+col))));
}

#endif
