/*
   Kyle Timmermans
   Lab 4
   VertexType.h
   11/15/19
*/

#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H

#include <iostream>
#include <queue>
#include "ItemType.h"
using namespace std;

// MARK States
enum  MARK { DEFAULT, VISITED, QUEUED };

struct VertexType{

        // Constructors
        VertexType()
        {
                item.Initialize(0);
                mark = DEFAULT;
        }

        VertexType(int v)
        {
                item.Initialize(v);
                mark = DEFAULT;
        }

        // Apply mark
        void markVertex(MARK m)
        {
                mark = m;
        }

        ItemType item;
        MARK mark;
};
#endif
