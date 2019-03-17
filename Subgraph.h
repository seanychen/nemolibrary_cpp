/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Subgraph.h
 * Author: Wooyoung
 *
 * Created on October 23, 2017, 2:34 PM
 * Note that this Subgraph class is different from Java version, where the adjacentmatrix is necessary
 * It will inherit most of the functions from Graph
 *
 */

#ifndef NEMOLIBRARY_C_SUBGRAPH_H
#define NEMOLIBRARY_C_SUBGRAPH_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "graph64.hpp"

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::find;

class Subgraph {
    friend ostream &operator<<(ostream &, const Subgraph &);

public:
    Subgraph(const int &);

    int getSize();

    int getOrder();

    int root();

    bool contains(const vertex &);

    bool add(const vertex &);

    int get(const int &);

    vector<vertex> &getNodes();

    bool isComplete();

private:
    vector<vertex> nodes;
    int order;
};


#endif //NEMOLIBRARY_C_SUBGRAPH_H
