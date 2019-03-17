/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Graph.h
 * Author: Wooyoung
 *
 * Created on October 12, 2017, 1:51 PM
 */

#ifndef NEMOLIBRARY_C_GRAPH_H
#define NEMOLIBRARY_C_GRAPH_H

#define MIB 1048576

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <algorithm>

#include "graph64.hpp"

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;
using std::make_pair;
using std::ifstream;
using std::ostream;
using std::vector;
using std::domain_error;
using std::invalid_argument;
using std::random_shuffle;
using std::default_random_engine;

class Graph {
    // todo: implement the ostream.
//    friend ostream &operator<<(ostream &, const Graph &);

public:
    Graph();

    explicit Graph(const bool &);

    explicit Graph(const string &);

    Graph(const string &, const bool &);

    virtual ~Graph();

    bool addVertex(const string &);

    int addVertex();

    bool addEdge(const vertex &, const vertex &);

    int getSize();

    bool isDirected();

    unordered_set<vertex> &getAdjacencyList(const vertex &);

    unordered_map<string, vertex> &getNametoIndex();

    unordered_map<vertex, string> getIndextoName();

    unordered_map<edge, edgetype> getEdges();

private:
    vector<unordered_set<vertex> > adjacencyLists;
    bool directed;

    // Helper maps
    unordered_map<string, vertex> name2Index;
    unordered_map<edge, edgetype> edges;

    // Helper functions
    vertex getOrCreateIndex(const string &, unordered_map<string, vertex> &);

    bool parse(const string &);



//    // Does the matrix form of graph better?
//    /*This is a set of adjacencylist of a graph (directed or undirected)*/
//    // todo: upgrade this part so that the graph can have better performance.
//    vector<unordered_set<vertex>> adjacencyLists;
////    unordered_map<key, adjacencyLists>            // Possible modification
//
//    // todo: think about this comment
//    /*For directed graph, editing nauty graph is different from undirected graph. Therefore, it needs a separate structure*/
//    //  vector<unordered_set <vertex> > dir_adjacencyLists; // this is only for directed graph (might not need)
//
//
//    /**
//     * name2Index as a hashmap so key is a node name (string) and value is its index. Will be used when graph is read from file
//     */
//    unordered_map<string, vertex> name2Index;
//    bool directed; // added by WK (10/18/2017)
//    unordered_map<edge, edgetype> edges; // added by following the original ESU program
};


#endif //NEMOLIBRARY_C_GRAPH_H
