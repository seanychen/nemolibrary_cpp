/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ESU.h
 * Author: Wooyoung
 *
 * Created on October 25, 2017, 1:06 PM
 */

#ifndef ESU_H
#define ESU_H
#include "RandESU.h"
using std::cout;
using std::ostream;






/**
 * ESU is a static class used for executing the Enumerate Subgraphs algorithm
 * on a network graph.
 */
class ESU {
public:
   /**
	 * Enumerates Subgraphs using the ESU algorithm. Requires user to specify
	 * return type(s) and provide the accompanying data structures.
	 *
	 * @param graph the graph on which to execute ESU
	 * @param subgraphs the SubgraphEnumerationResult into which to enumerated
	 *                  Subgraphs will be stored.
	 * @param subgraphSize the size of the target Subgraphs
	 */
    static void enumerate(Graph&, SubgraphEnumerationResult&, int);
   /**
	 * Enumerates Subgraphs for one branch of the ESU tree starting at the
	 * given node. Allows for more control over the order the order of 
	 * execution, but does not perform a full enumeration.
	 *
	 * @param graph the graph on which to execute ESU
	 * @param subgraphs the data structure to which results are written
	 * @param subgraphSize the target subgraph size to enumerate
	 * @param vertex the graph vertex at which to execute
         * @param nautylink after initialize from the previous
	 */
    static void enumerate(Graph&, SubgraphEnumerationResult&, int, vertex, NautyLink&);
    
            
private:
    
    
 

};

#endif /* ESU_H */

