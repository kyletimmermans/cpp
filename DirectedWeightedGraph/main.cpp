/*
   Kyle Timmermans
   Lab 4
   lab4.cpp
   11/17/19
*/

#include <iostream>
#include "DirectedWeightedGraph.h"
using namespace std;

int main(){

	// MyGraph is the graph in the homework assignment pdf
        DirectedWeightedGraph MyGraph;

        // Declare Vertices
        VertexType v1(1), v2(2), v3(3), v4(4), v5(5), v6(6), v7(7);

        // Add Vertices
        MyGraph.AddVertex(v1);
        MyGraph.AddVertex(v2);
        MyGraph.AddVertex(v3);
        MyGraph.AddVertex(v4);
        MyGraph.AddVertex(v5);
        MyGraph.AddVertex(v6);
        MyGraph.AddVertex(v7);


        // Declare edges and weights
        MyGraph.AddEdge(v1, v2, 100);
        MyGraph.AddEdge(v1, v4, 150);
        MyGraph.AddEdge(v4, v5, 200);
        MyGraph.AddEdge(v5, v6, 100);
        MyGraph.AddEdge(v4, v6, 100);
        MyGraph.AddEdge(v1, v3, 50);
        MyGraph.AddEdge(v3, v1, 10);
        MyGraph.AddEdge(v3, v7, 50);
        MyGraph.AddEdge(v7, v6, 30);

        // Edges and their weights
	cout << "___________________________________" << endl;
        cout << "Edge (v1, v2) has a weight of " << MyGraph.GetWeight(v1, v2) << endl;
        cout << "Edge (v1, v4) has a weight of " << MyGraph.GetWeight(v1, v4) << endl;
        cout << "Edge (v4, v5) has a weight of " << MyGraph.GetWeight(v4, v5) << endl;
        cout << "Edge (v5, v6) has a weight of " << MyGraph.GetWeight(v5, v6) << endl;
        cout << "Edge (v4, v6) has a weight of " << MyGraph.GetWeight(v4, v6) << endl;
        cout << "Edge (v1, v3) has a weight of " << MyGraph.GetWeight(v1, v3) << endl;
        cout << "Edge (v3, v1) has a weight of " << MyGraph.GetWeight(v3, v1) << endl;
        cout << "Edge (v3, v7) has a weight of " << MyGraph.GetWeight(v3, v7) << endl;
        cout << "Edge (v7, v6) has a weight of " << MyGraph.GetWeight(v7, v6) << endl;

        cout << endl;

        // Breadth-Frist Searches
	// Your program should show the Breadth-First Traversal starts from Vertex No.1. 
        cout << "Breadth First Traversals Starting From Each Vertex" <<endl;
        cout << "Starting at Vertex 1: ";
        MyGraph.BreadthFirstTraversal(v1);
        cout << endl;
        cout << "Starting at Vertex 2: ";
        MyGraph.BreadthFirstTraversal(v2);
        cout << endl;
        cout << "Starting at Vertex 3: ";
        MyGraph.BreadthFirstTraversal(v3);
        cout << endl;
        cout << "Starting at Vertex 4: ";
        MyGraph.BreadthFirstTraversal(v4);
        cout << endl;
        cout << "Starting at Vertex 5: ";
        MyGraph.BreadthFirstTraversal(v5);
        cout << endl;
        cout << "Starting at Vertex 6: ";
        MyGraph.BreadthFirstTraversal(v6);
        cout << endl;
        cout << "Starting at Vertex 7: ";
        MyGraph.BreadthFirstTraversal(v7);
        cout << endl;
	cout << "___________________________________" << endl;

        return 0;
}

