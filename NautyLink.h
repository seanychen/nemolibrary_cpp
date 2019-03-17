/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NautyLink.h
 * Author: Wooyoung
 *
 * Created on October 27, 2017, 11:36 AM
 */
#ifndef NEMOLIBRARY_C_NAUTYLINK_H
#define NEMOLIBRARY_C_NAUTYLINK_H

#define MAXN 64

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "nauty/nauty.h"
#include "graph64.hpp"
#include "Subgraph.h"
#include "nauty/nautinv.h"

typedef uint64 graph64; //Nauty label

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::domain_error;
using std::string;
using std::unordered_map;


class NautyLink {
public:
    NautyLink(const int &, const unordered_map<edge, edgetype> &);

    NautyLink(const int &, const unordered_map<edge, edgetype> &, bool);

    virtual ~NautyLink();

    void nautyinit();

    int get_G_N();

    int get_G_M();

    graph64 nautylabel(Subgraph &);

private:
    bool directed;

    graph64 getLabel(graph *, set *, const int &, const int &);

    int G_N; // subgraphsize
    int G_M;
    graph canon[MAXN * MAXM];
    graph nautyGraph[MAXN * MAXM];
    int lab[MAXN];
    int ptn[MAXN];
    int orbits[MAXN];
    setword workspace[160 * MAXM];
    set *gv = NULL;

    /* ADDED
     * TODO: GO BACK TO HERE, AND REVIEW THEM*/
    DEFAULTOPTIONS(options);
    statsblk(stats);
    unordered_map<edge, edgetype> edges; // get the edges when initialize it
};


#endif //NEMOLIBRARY_C_NAUTYLINK_H
