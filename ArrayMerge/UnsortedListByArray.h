/*
    Kyle Timmermans
    9/22/19
    CISC2200
    Lab 1 - Array Implementation
    UnsortedType.h
*/

// SPECIFICATION FILE		( UnsortedType.h )
#ifndef UNSORTEDLISTBYARRAY_H
#define UNSORTEDLISTBYARRAY_H

// include nodetype class
#include "ItemType.h"

class  UnsortedListByArray		// declares a class data type
{				
public : 			

  UnsortedListByArray();

  void MakeEmpty( );        // 8 public member functions
  void InsertItem( ItemType  item ); 	
  void DeleteItem( ItemType  item ); 	

  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  void RetrieveItem( ItemType &  item, bool&  found );

  void ResetList( );
  void GetNextItem( ItemType&  item ); 	
  // Lab 1 HW - SplitLists and MergeLists Functions
  void SplitList(ItemType item, UnsortedListByArray& listOne, UnsortedListByArray& listTwo);
  void MergeList(UnsortedListByArray& listOne, UnsortedListByArray& listTwo);
private :
   int length; 
   ItemType info[MAX_ITEM]; 
   int currentPos;
};


#endif
