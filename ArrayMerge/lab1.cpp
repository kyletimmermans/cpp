/*
   Kyle Timmermans
   CS2200
   9/22/19
   Lab 1 - Array Implementation
   lab1.cpp
*/

// include classes
#include "ItemType.h"
#include "UnsortedListByArray.h"

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.
// Post: Each component in list has been written.
// Resets list to make final location NULL
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

// start main
int main()
{
	// create lists to be used with SplitLists and MergeLists
	// Added "MergedLists" to prevent seg fault
	UnsortedListByArray listL, listOne, listTwo, MergedList;
	
	// fill listL
	// in order as assignment shows
	ItemType a;
        a.Initialize(1);
        listL.InsertItem(a);

	ItemType b;
	b.Initialize(3);
	listL.InsertItem(b);

	ItemType c;
	c.Initialize(5);
	listL.InsertItem(c);

	ItemType d;
	d.Initialize(2);
	listL.InsertItem(d);

	ItemType e;
	e.Initialize(10);
	listL.InsertItem(e);

	ItemType f;
	f.Initialize(12);
	listL.InsertItem(f);

	ItemType g;
	g.Initialize(0);
	listL.InsertItem(g);
	
	// print list before SplitLists
	std::cout << endl;
	std::cout << "Before the Split, UnsortedType List L is:" << endl;
	PrintList(listL);

	// set key to 4
	ItemType key;
	key.Initialize(4);
	
	// split lists into two, listOne < 4, and listTwo > 4
	listL.SplitList(key, listOne, listTwo);
	
	// print listOne and listTwo (split lists)
	std::cout << endl << endl;
	std::cout << "If ItemType item’s key is 4, after the split we get:" << endl;
	std::cout << endl;
	std::cout << "UnsortedType listOne: ";
	PrintList(listOne);
	cout << "     ";
	std::cout << "UnsortedType listTwo: ";
	PrintList(listTwo);
	
	// print merge list (listOne + listTwo = MergedList)
	std::cout << endl << endl;
	std::cout << "After merging, we get the original contents of List L:" << endl;
	MergedList.MergeList(listOne, listTwo);
	PrintList(listL);	

	// formatting
	std::cout << endl << endl;
	
// end main
return 0;
}
