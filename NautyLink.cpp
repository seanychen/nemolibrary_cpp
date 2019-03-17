/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NautyLink.cpp
 * Author: Wooyoung
 *
 * Created on October 27, 2017, 11:36 AM
 */

#include "NautyLink.h"

NautyLink::NautyLink(const int &subgraphsize, const unordered_map<edge, edgetype> &edgeset)
        : NautyLink(subgraphsize, edgeset, false) {}

NautyLink::NautyLink(const int &subgraphsize, const unordered_map<edge, edgetype> &edgeset, bool dir)
        : G_N(subgraphsize), directed(dir), edges(edgeset) {
    nautyinit();
}

NautyLink::~NautyLink() {

}

void NautyLink::nautyinit() {
    G_M = (G_N + WORDSIZE - 1) / WORDSIZE; //#define WORDSIZE 64

    options.writeautoms = FALSE;
    options.getcanon = TRUE;

    if (directed) {
        options.digraph = TRUE;
        options.invarproc = adjacencies;
        options.mininvarlevel = 1;
        options.maxinvarlevel = 10;
    }

    // Initialize nautyGraph
    for (int i = 0; i != G_N; ++i) {

        EMPTYSET(GRAPHROW(nautyGraph, i, G_M), G_M);
    }

    nauty_check(WORDSIZE, G_M, G_N, NAUTYVERSIONID);
}

int NautyLink::get_G_N() {
    return G_N;
}

int NautyLink::get_G_M() {
    return G_M;
}

graph64 NautyLink::nautylabel(Subgraph &subgraph) {
    // get the node(index) list from subgraph
    int subsize = subgraph.getSize();

    // get the adjacencylists of the nede(index) list from subgraph
    // key = node id. value = the adjacencylist of the node (key)

    // go through each pair from nodes and connect if there is an edge.
    int i = 0;
    int j = 0;
    for (auto itr1 = subgraph.getNodes().begin(); itr1 != subgraph.getNodes().end(); ++itr1, ++i) {
        j = 0;
        for (auto itr2 = subgraph.getNodes().begin(); itr2 != subgraph.getNodes().end(); ++itr2, ++j) {
            if (itr1 != itr2) {
                // todo; probably unnecesary vertex uc uv
                const vertex &uc = *itr1;
                const vertex &vc = *itr2;
                const edge &e_check = edge_code(uc, vc);

                //if there is an edge between nodes[itr1] and nodes[itr2], connect i and j
                if (edges.find(e_check) != edges.end()) {
                    const edgetype &ec = edges[e_check];
                    if (((uc < vc) && (ec == DIR_U_T_V)) || ((uc > vc) && (ec == DIR_V_T_U))) {

                    } /*else if (((uc < vc) && (ec == DIR_V_T_U)) || ((uc > vc) && (ec == DIR_U_T_V))) {
                         cout<<"2. connect "<<vc<<" and "<<uc<<endl;
                        DELELEMENT(GRAPHROW(nautyGraph, j, G_M), i);
                        gv = GRAPHROW(nautyGraph, j, G_M);
                        ADDELEMENT(gv, i);
                    }*/ else if (ec == UNDIR_U_V) {
                        //    cout<<"3. connect "<<uc<<" and "<<vc<<endl;
                                DELELEMENT(GRAPHROW(nautyGraph, i, G_M), j);
                        gv = GRAPHROW(nautyGraph, i, G_M);
                                ADDELEMENT(gv, j);
                    }
                }
            }
        }
    }

    nauty(nautyGraph, lab, ptn, NILSET, orbits, &options, &stats, workspace, 160 * MAXM, G_M, G_N, canon);

    // get the cannonical label
    graph64 res_gr = getLabel(canon, gv, G_N, G_M);

    // then initialize the graph
    for (int i = 0; i != G_N; ++i) {

        EMPTYSET(GRAPHROW(nautyGraph, i, G_M), G_M);
    }

    return res_gr;
}

graph64 NautyLink::getLabel(graph *, set *, const int &, const int &) {
    //Fanmod code to retrieve canon data
    graph64 res_gr = 0ULL;
    for (int a = 0; a < G_N; ++a) {
        gv = GRAPHROW(canon, a, G_M);
        for (int b = 0; b < G_N; ++b) {
            res_gr <<= 1;
            if (ISELEMENT(gv, b)) {
                res_gr |= 1;
            }
        }
    }
    return res_gr;
}




