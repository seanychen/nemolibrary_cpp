/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Wooyoung
 *
 * Created on October 10, 2017, 10:48 AM
 */

//#include <cstdlib>
//#include <sparsehash/sparse_hash_map>


#include "Graph.h"
#include "SubgraphCount.h"
#include "ESU.h"
#include "RandomGraphAnalysis.h"
#include "StatisticalAnalysis.h"


using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::domain_error;
using std::string;

#include <cstring>

template<typename map_key, typename map_val>
void printmap(const unordered_map<map_key, map_val> &_map) {
    for (const auto &p : _map)
        cout << p.first << " => " << p.second << endl;

}

int main(int argc, char **argv) {

    if (argc != 5) {
        cerr << "usage: NetworkMotifDetector path_to_data motif_size, random_graph_count" << endl;
        exit(0);
    };

    string filename = argv[1];
    int motifSize = atoi(argv[2]);
    int randomCount = atoi(argv[3]);
    bool directed = atoi(argv[4]);

    std::clock_t begin = std::clock();
    double duration = 0.0;


    Graph targetg(filename, directed);


    cout << "Analyzing target graph..." << endl;
//    SubgraphProfile subc(targetg.getSize());
    SubgraphCount subc;

    ESU::enumerate(targetg, subc, motifSize);

    unordered_map<graph64, double> targetLabelRelFreqMap =
            subc.getRelativeFrequencies();

    printmap(targetLabelRelFreqMap);


    vector<double> probs;
    for (int i = 0; i < motifSize - 2; i++) {
        probs.push_back(1.0);
    }
    probs.push_back(0.5);
    probs.push_back(0.5);

    cout << "Analyzing random graphs..." << endl;

    unordered_map<graph64, vector<double>> randLabelRelFreqsMap = RandomGraphAnalysis::analyze(targetg, randomCount,
                                                                                               motifSize, probs);

    cout << "Comparing target graph to random graphs" << endl;

    StatisticalAnalysis stat(targetLabelRelFreqMap, randLabelRelFreqsMap, randomCount);

    cout << stat << endl;

    duration = (std::clock() - begin) / (double) CLOCKS_PER_SEC;

    cout << "Time = " << duration * 1000 << "ms" << endl;


    return 0;
}

