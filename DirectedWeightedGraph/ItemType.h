/*
   Kyle Timmermans
   Lab 4
   ItemType.h
   11/15/19
*/

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

const int  MAX_ITEM = 50;
enum  RelationType { LESS, EQUAL, GREATER };

class ItemType          // declares class data type
{
        public :                        // 4 public member functions

                //default constructor
                ItemType() {}

                RelationType ComparedTo(ItemType  otherItem) const
                {
                        if ( value  <  otherItem.value )
                                return  LESS;
                        else if ( value  > otherItem.value )
                                return  GREATER;
                        else  return  EQUAL;
                }
                void Print() const
                {
                        cout  <<  value << " ";
                }

                void Initialize(int value)
                {
                        this->value  =  value;
                }


        private :                       // 1 private data member
                int  value;             // could be any type
} ;
#endif
