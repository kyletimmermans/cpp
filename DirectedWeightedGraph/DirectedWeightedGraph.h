/*
   Kyle Timmermans
   Lab 4
   DirectedWeightedGraph.h
   11/17/19
*/

#ifndef DIRECTWEIGHTEDGRAPH_H
#define DIRECTWEIGHTEDGRAPH_H

#include <iostream>
#include "ItemType.h"
#include "VertexType.h"
#include <queue>
using namespace std;

// Functions necessary for this ADT
class DirectedWeightedGraph{
        public:
                //Constructors
                DirectedWeightedGraph();
                DirectedWeightedGraph(int maxV);
                //Destructor
                ~DirectedWeightedGraph();
                bool IsEmpty() const;
                bool IsFull() const;
                void DeleteVertex(VertexType v);
                bool deleteEdge(VertexType v1, VertexType v2);
                void GetNeighbors(VertexType v, queue<VertexType>& nq);
                void AddEdge(VertexType v1, VertexType v2, int w);
                int GetWeight(VertexType v1, VertexType v2);
                bool EdgeExists(VertexType v1, VertexType v2);
                bool VertexExists(VertexType v);
                void AddVertex(VertexType v);
                void BreadthFirstTraversal(VertexType first);

              // Data and functions necessary for this ADT
              private:
                              int numberOfVertices;
                              int maxVertices;
                              int edges[50][50];
                              VertexType * vertices;
                              int IndexIs(VertexType v);
                              queue<VertexType> nq;
              };
#endif

