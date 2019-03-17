/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Subgraph.cpp
 * Author: Wooyoung
 *
 * Created on October 23, 2017, 2:34 PM
 */

#include "Subgraph.h"

/**
 * Constructor a graph of a specific order (i.e. number of nodes)
 * @param order the order of this subgraphs
 */
Subgraph::Subgraph(const int &order) : order(order) {}

/**
 * Get the current size of this Subgraph.
 * @return
 */
int Subgraph::getSize() {
    return nodes.size();
}

/**
 * Get number of possible nodes in this Subgraph
 * @return the maximum order of this Subgraph
 */
int Subgraph::getOrder() {
    return order;
}

bool Subgraph::isComplete() {
    return (nodes.size() == order);
}

/**
 * Get the id number of the first vertex added to this Subgraph
 * @return the id of the root
 */
int Subgraph::root() {
    if (nodes.empty()) {
        cerr << "It is currently empty" << endl;
        return -1;
    }

    return static_cast<int>(nodes.front());
}

/**
 * Check whether a vertex exists in this Subgraph
 * @param vertex the target vertex
 * @return true if this subgraph contains the specific vertex, false otherwise
 */
bool Subgraph::contains(const vertex &v) {
    return find(nodes.begin(), nodes.end(), v) != nodes.end();
}

/**
 * Add a vertex to this Subgraph
 * @param v the vertex to add to this subgraph.
 * @pre cannot add if the subgraph is complete
 * @return whether vertex add is success.
 */
bool Subgraph::add(const vertex &v) {
    if (isComplete()) {
        cerr << "The subgraph is full:: Cannot add more" << endl;
        return false;
    }

    nodes.push_back(v);
    return true;
}

/**
 * Get the nth node added to this subgraph
 *
 * @param n nth node
 * @return the nth node that added to this Subgraph.
 */
int Subgraph::get(const int &n) {
    int nodeSize = nodes.size();
    if ((nodeSize - 1) < n || nodes.empty()) {
        cerr << n << "th index is not available" << endl;
        return -1;
    }

    return static_cast<int>(nodes.at(n));
}

/**
 * Get all the nodes in this Subgraph
 * @return this subgraph's nodes (reference)
 */
vector<vertex> &Subgraph::getNodes() {
    return nodes;
}

/**
 * Return a string representation of this Subgraph. Should display in the format [x, y, z] where x, y, z represent
 * vertices in this subgraph.
 * @param out
 * @param sgraph
 * @return a string representation of this subgraph.
 */
ostream &operator<<(ostream &out, const Subgraph &sgraph) {
    string s = "[";
    if (sgraph.nodes.empty()) {
        out << "empty";
        return out;
    }

    stringstream ss;
    for (auto itr = sgraph.nodes.begin(); itr != (sgraph.nodes.end() - 1); ++itr) {
        ss << *itr;
        s = s + ss.str() + ",";
    }
    ss << *(sgraph.nodes.end() - 1);
    s = s + ss.str() + "]";

    out << s;

    return out;
}



