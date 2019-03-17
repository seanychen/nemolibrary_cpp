/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Graph.cpp
 * Author: Wooyoung
 *
 * Created on October 12, 2017, 1:51 PM
 */

#include "Graph.h"

Graph::Graph() : Graph(false) {}

Graph::Graph(const bool &dir) : directed(dir) {}

Graph::Graph(const string &filename) : Graph(filename, false) {}

Graph::Graph(const string &filename, const bool &dir) : directed(dir) {
    parse(filename);
}

Graph::~Graph() {}

/**
 * Add a vertex to this Graph
 *
 * @return the ID number assigned to the new vertex
 */
int Graph::addVertex() {

    adjacencyLists.push_back(unordered_set<vertex>());

    return adjacencyLists.size();
}

bool Graph::addVertex(const string &nodeName) {

    if (name2Index.find(nodeName) != name2Index.end()) {
        cerr << "Same node already exists" << endl;
        return -1;
    }

    name2Index.insert(make_pair(nodeName, adjacencyLists.size()));
    adjacencyLists.push_back(unordered_set<vertex>());

    return adjacencyLists.size() - 1;
}

bool Graph::addEdge(const vertex &vertexA, const vertex &vertexB) {
    int adjacencyListSize = adjacencyLists.size();

    if ((adjacencyListSize) < vertexA || (adjacencyListSize) < vertexB || vertexA == vertexB) {
        return false;
    }

    adjacencyLists.at(vertexA).insert(vertexB);
    adjacencyLists.at(vertexB).insert(vertexA);

    edge e = 0;
    vertexA < vertexB ? e = new_edge(vertexA, vertexB) : e = new_edge(vertexB, vertexA);
    directed ? edges.insert(make_pair(e, DIR_U_T_V)) : edges.insert(make_pair(e, UNDIR_U_V));

    return true;
}

int Graph::getSize() {
    return adjacencyLists.size();
}

bool Graph::isDirected() {
    return directed;
}

unordered_set<vertex> &Graph::getAdjacencyList(const vertex &index) {
    return adjacencyLists.at(index);
}

unordered_map<string, vertex> &Graph::getNametoIndex() {
    return name2Index;
}

unordered_map<vertex, string> Graph::getIndextoName() {
    unordered_map<vertex, string> Index2name;
    for (auto v : name2Index) {
        auto test = Index2name.insert(make_pair(v.second, v.first));
    }

    return Index2name;
}

unordered_map<edge, edgetype> Graph::getEdges() {
    return edges;
}

vertex Graph::getOrCreateIndex(const string &nodeName, unordered_map<string, vertex> &nameToIndex) {
    if (nameToIndex.find(nodeName) == nameToIndex.end()) {
        // if the key does not exists
        nameToIndex.insert(make_pair(nodeName, adjacencyLists.size()));
        adjacencyLists.push_back(unordered_set<vertex>());
    }

    return nameToIndex[nodeName];
}

bool Graph::parse(const string &filename) {
    unordered_map<string, vertex> nameToIndex;

    // we read in all the data at once only, so we can easil randomize it
    // with suffle
    char buf[MIB];
    ifstream in(filename);
    in.rdbuf()->pubsetbuf(buf, MIB);
//    in.rdbuf()->pubsetbuf(buf, sizeof buf);
//    in.open(filename);


    if (!in) {
        throw invalid_argument("Cannot find an input file");
    }

    vector<string> lines;
    string currentLine;
    while (in) {
        getline(in, currentLine); // read each line
        if (!currentLine.empty()) {
            lines.push_back(currentLine);
        }
    }

    in.close();

    // shuffling the line
    shuffle(lines.begin(), lines.end(), default_random_engine{});

    for (string line : lines) {
        string from, to;
        stringstream linesplits(line);
        linesplits >> from >> to;
        vertex fromIndex = getOrCreateIndex(from, nameToIndex);
        vertex toIndex = getOrCreateIndex(to, nameToIndex);

        addEdge(fromIndex, toIndex);
    }

    name2Index = nameToIndex;
    return true;
}

