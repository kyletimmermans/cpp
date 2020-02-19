/*
    Kyle Timmermans
    CISC2200
    Lab 3
    lab3.cpp
*/

// class files
#include "ItemType.h"
#include "TreeType.h"

int main(){

    TreeType firstTree;
    TreeType newTree;

    ItemType x;
    ItemType test;

    test.Initialize('F');
    firstTree.InsertItem(test);
    if (firstTree.IsEmpty() == false)
       cout<<"The first item is inserted"<<endl;

    cout << endl;

    cout<<"After inserting the first item " << test << " into the tree: " << endl;
    firstTree.Print();
    cout << endl;

    // Insert Nodes into Tree
    x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);
    x.Initialize('B');
    firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);
    x.Initialize('K');
    firstTree.InsertItem(x);
    x.Initialize('P');
    firstTree.InsertItem(x);
    x.Initialize('G');
    firstTree.InsertItem(x);
    x.Initialize('D');
    firstTree.InsertItem(x);

    cout<<"After inserting nine items into the tree: "<<endl;
    firstTree.Print();
    cout << endl;

    // Test LeafCount()
    cout << "Leaf Count Test:" << endl;
    int leaves = firstTree.LeafCount();
    cout << "The tree has " << leaves << " leaves" << endl;
    cout << endl;
    int count = firstTree.GetLength();
    cout<<"The tree has "<<count<<" elements"<<endl;
    cout << endl;
    
    // Test Ancestors()
    cout << "Ancestor Test:" << endl;
    firstTree.Ancestors(test);
    cout << endl;

    if (count !=0)
    {
        cout<<"Show the tree in Post_order"<<endl;
        firstTree.ResetTree(POST_ORDER);
        bool finished = false;

        while(finished == false)
       {
         ItemType thisItem;
         firstTree.GetNextItem(thisItem, POST_ORDER, finished);
         cout<<thisItem<<"  ";
       }
       cout<<endl;
	
        cout << endl;
        cout<<"Show the tree in Pre_order"<<endl;
        firstTree.ResetTree(PRE_ORDER);
        finished = false;
        while(finished == false)
        {

         ItemType thisItem;
         firstTree.GetNextItem(thisItem, PRE_ORDER, finished);
         cout<<thisItem<<"  ";
        }
        cout<<endl;

        cout<<"Delete an item: " << x <<endl;
	cout << endl;

        bool find = false;
        firstTree.RetrieveItem(x,find);
        if ( find == true)
            firstTree.DeleteItem(x);

        cout<<"After deleting " << x << " from the tree,";
        count = firstTree.GetLength();
        cout<<" the tree has " << count << " elements"<<endl;

        firstTree.Print();
    }

    cout << endl;
    firstTree.MakeEmpty();
    cout<<"After emptying the tree: " << endl;
    firstTree.Print();

    return 0;
}
