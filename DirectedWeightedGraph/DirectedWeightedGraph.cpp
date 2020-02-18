/*
   Kyle Timmermans
   Lab 4
   DirectedWeightedGraph.h
   11/17/19
*/

#include <iostream>
#include <queue>
#include "DirectedWeightedGraph.h"

// Constructors required
DirectedWeightedGraph::DirectedWeightedGraph( )
{
        numberOfVertices=0;
        maxVertices= 50;
        vertices = new VertexType[50];
}

DirectedWeightedGraph::DirectedWeightedGraph(int maxV)
{
        numberOfVertices=0;
        maxVertices= maxV;
        vertices = new VertexType[maxVertices];
}

// Destructor required
DirectedWeightedGraph::~DirectedWeightedGraph( )
{
        numberOfVertices=0;
        delete [] vertices;
}


// Create and edge from one vertex to another and declare its weight
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w)
{
        // Find vertices
        int index1 = IndexIs(v1);
        int index2 = IndexIs(v2);

        // Add weight to edge
        edges[index1][index2] = w;
}

// Return true or false depending on if full
bool DirectedWeightedGraph::IsFull( ) const
{
        return (numberOfVertices == maxVertices);
}

// Create vertex (No edge)
void DirectedWeightedGraph::AddVertex(VertexType v)
{
        // Add to last index
        vertices[numberOfVertices] = v;

        // Edges = 0
        for (int i=0; i < numberOfVertices; i++)
        {
                edges[numberOfVertices][i] = 0;
                edges[i][numberOfVertices] = 0;
        }

        numberOfVertices++;
}

// Return true/false if nothing found
bool DirectedWeightedGraph::IsEmpty( ) const
{
        return (numberOfVertices == 0);
}

// Return true if found and deleted
bool DirectedWeightedGraph::deleteEdge(VertexType v1, VertexType v2)
{
        if (EdgeExists(v1, v2)){
                int index1 = IndexIs(v1);
                int index2 = IndexIs(v2);

                edges[index1][index2] = 0;
                return true;
        }
        return false;
}

// Return weight
int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
        int index1 = IndexIs(v1);
        int index2 = IndexIs(v2);

        return (edges[index1][index2]);
}

// Return true if edge found
bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
        int index1 = IndexIs(v1);
        int index2 = IndexIs(v2);

        if (edges[index1][index2] != 0)
        {
                return true;
        }
        return false;
}

// Return true if edge found
bool DirectedWeightedGraph::VertexExists(VertexType v)
{
        for (int i=0; i < numberOfVertices; i++)
        {
                if (vertices[i].item.ComparedTo(v.item))
                {
                        return true;
                }
        }
        return false;
}

// Delete vertex
void DirectedWeightedGraph::DeleteVertex(VertexType v)
{
        int index = IndexIs(v);
        int last_index = numberOfVertices-1;
        int weight;

        // if not last element
        if (index != last_index){
                VertexType temp;
                for (int i=0; i < numberOfVertices; i++)
                {
                        //delete edges
                        deleteEdge(vertices[i], vertices[index]);
                        deleteEdge(vertices[index], vertices[i]);

                        if (i != index)
                        {
                                if (EdgeExists(vertices[last_index],vertices[i]))
                                {
                                        //getweight
                                        weight = GetWeight(vertices[last_index], vertices[i]);
                                        //add edge to new spot
                                        AddEdge(vertices[index], vertices[i], weight);
                                }

                                if (EdgeExists(vertices[i], vertices[last_index]))
                                {
                                        // getweight
                                        weight = GetWeight(vertices[i], vertices[last_index]);
                                        AddEdge(vertices[i], vertices[index], weight);
                                }

                        }
                }
                //swap vertices
                temp = vertices[last_index];
                vertices[index] = temp;
        }
        numberOfVertices--;
}

//if index exists, return its int value
int DirectedWeightedGraph::IndexIs(VertexType v)
{
        for (int i=0; i < numberOfVertices; i++)
        {
                if (vertices[i].item.ComparedTo(v.item) == EQUAL)
                        return i;
        }
        //if not found
        return -1;
}

//Non visited neighbors
void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)
{
        int index1 = IndexIs(v);

        for (int i=0; i < numberOfVertices; i++)
        {
                if (edges[index1][i] != 0 && vertices[i].mark != QUEUED && vertices[i].mark != VISITED)
                {
                        nq.push(vertices[i]);
                        vertices[i].markVertex(QUEUED);
                }
        }
}


// Learned in class, traverse level by level
void DirectedWeightedGraph::BreadthFirstTraversal(VertexType v)
{
        // Index of vertex
        int index = IndexIs(v);

        vertices[index].item.Print();

        // MARK vertex
        vertices[index].markVertex(VISITED);

        // Place neighbors in queue
        GetNeighbors(v, nq);

        // Until queue != empty
        while(!nq.empty())
        {
                VertexType next = nq.front();
                next.item.Print();
                next.markVertex(VISITED);
                GetNeighbors(next, nq);
                nq.pop();
        }

        // Reset
        for (int i=0 ; i < numberOfVertices; i++)
        {
                vertices[i].markVertex(DEFAULT);
        }
}
