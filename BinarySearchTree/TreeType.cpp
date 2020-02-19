/*
    Kyle Timmermans
    CISC2200
    Lab 3
    TreeType.cpp
*/

#include "TreeType.h"
#include <new>

TreeType::TreeType()
{
   root = NULL;

   preQue = NULL;
   postQue = NULL;
   inQue = NULL;
}

TreeType::TreeType(const TreeType& originalTree)
{
   CopyTree(root, originalTree.root);
}

void TreeType::operator=(const TreeType& originalTree)
{
    if (&originalTree == this)
       return;

    Destroy(root);
    CopyTree(root, originalTree.root);
}


void TreeType::CopyTree(TreeNode *&copy, const TreeNode* originalTree)
{

    if (originalTree == NULL)
        copy = NULL;
    else
    {
      copy = new TreeNode;
      copy->info = originalTree->info;
      CopyTree(copy->left, originalTree->left);
      CopyTree(copy->right, originalTree->right);
    }
}


TreeType::~TreeType()
{
   MakeEmpty();

   if (preQue !=NULL)  delete preQue;
   if (postQue != NULL) delete postQue;
   if (inQue != NULL) delete inQue;
}

void TreeType::Destroy(TreeNode *& tree)
{
   if (tree!= NULL)
   {
     Destroy(tree->left);
     Destroy(tree->right);
     delete tree;
   }
}

void TreeType::MakeEmpty()
{
   Destroy(root);
   root = NULL;
}



bool TreeType::IsFull() const
{

  TreeNode * location;
  try{
     location = new TreeNode;
     delete location;
     return false;
  }catch( std::bad_alloc e){
    return true;
  }
}


bool TreeType::IsEmpty() const
{
   return root == NULL;

}

int TreeType::GetLength() const
{
    return Count(root);
}

int TreeType::Count(TreeNode * tree) const
{
   if (tree == NULL)
       return 0;
   else
       return Count(tree->left) + Count(tree->right) +1;
}



void TreeType::RetrieveItem(ItemType & item, bool & found) const
{
    Retrieve(root, item, found);
}


void TreeType::Retrieve(TreeNode* tree,
              ItemType& item, bool& found) const
{
  if (tree == NULL)   found = false;

  else if (item.ComparedTo(tree->info) == LESS)
    Retrieve(tree->left, item, found);
  else if (item.ComparedTo(tree->info) == GREATER)
    Retrieve(tree->right, item, found);
  else
  {
    item = tree->info;
    found = true;
  }
}


void TreeType::InsertItem(ItemType item)
{
   Insert(root, item);
}

void TreeType::Insert(TreeNode* & tree, ItemType item)
{
  if (tree == NULL)
  { // Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item.ComparedTo(tree->info) == LESS)
    Insert(tree->left, item);
  else
    Insert(tree->right, item);
}


void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}


// first, find which node should be deleted.
void TreeType::Delete(TreeNode*& tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
     Delete(tree->left, item);
  else if (item.ComparedTo(tree->info) == GREATER)
     Delete(tree->right, item);
  else
     DeleteNode(tree);  // Node found
}

void TreeType::DeleteNode(TreeNode*&  tree) {

       ItemType data;
       TreeNode* tempPtr;

        tempPtr = tree;

        if ( tree->left == NULL) {
              tree = tree->right;
              delete tempPtr;
       } else if (tree->right == NULL){
              tree = tree->left;
              delete tempPtr;
       }else{
              GetPredecessor(tree->left, data);
               tree->info = data;
               Delete(tree->left, data);
        }
}

void TreeType::GetPredecessor( TreeNode* tree,
                               ItemType& data)
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void TreeType::Print(ofstream & output) const
{
   PrintTree(root, output);
}

void TreeType::Print() const
{
   std::cout<<"Binary Search Tree: (in-order)"<<endl;
   PrintTree(root, std::cout);
   std::cout<<endl;
}

void TreeType::PrintTree(TreeNode* tree, ostream& output) const
{

  if (tree != NULL)
  {
    PrintTree(tree->left, output);
    output <<tree->info<<"  ";
    PrintTree(tree->right, output);
  }
}



void TreeType::PreOrder(TreeNode * tree, queue<ItemType>* & preQue)
{

   if (tree != NULL)
   {
      preQue->push(tree->info);
      PreOrder(tree->left, preQue);
      PreOrder(tree->right, preQue);
   }
}



void TreeType::InOrder(TreeNode * tree, queue<ItemType>*& inQue)
{

   if (tree != NULL)
   {
      InOrder(tree->left, inQue);
      inQue->push(tree->info);
      InOrder(tree->right, inQue);
   }
}



void TreeType::PostOrder(TreeNode * tree, queue<ItemType>* & postQue)
{

   if (tree != NULL)
   {
      PostOrder(tree->left, postQue);
      PostOrder(tree->right, postQue);
      postQue->push(tree->info);
   }
}

void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree
// elements in the desired order.
//the queue should be deleted after using it.
{
  switch (order)
  {
    case PRE_ORDER : preQue = new queue<ItemType>;
                     PreOrder(root, preQue);
                     break;
    case IN_ORDER  : inQue = new queue<ItemType>;
                     InOrder(root, inQue);
                     break;
    case POST_ORDER: postQue = new queue<ItemType>;
                     PostOrder(root, postQue);
                     break;
  }
}


void TreeType::GetNextItem(ItemType & item, OrderType order, bool& finished)
{
   finished = false;
   switch(order)
   {
     case PRE_ORDER  : item = preQue->front();
                       preQue->pop( );
                      if (preQue->empty())
                       {
                         finished = true;
                         delete preQue;
                         preQue = NULL;
                       }
                      break;
    case IN_ORDER   : item = inQue->front();
                      inQue->pop();
                      if (inQue->empty())
                      {
                        finished = true;
                        delete inQue;
                        inQue = NULL;
                      }
                      break;
    case  POST_ORDER: item = postQue->front();
                      postQue->pop();
                      if (postQue->empty())
                      {
                        finished = true;
                         delete postQue;
                        postQue = NULL;
                      }
                      break;

   }
}

//
// Lab functions
//

// LeafCount
// Function: Return the number of leaf nodes in the tree
// Precondition: The tree has been initialized.
// Postcondition: The tree has not been changed.
int TreeType::LeafCount() const
{
        // initialize counter at 0
        int count = 0;
        if (root == NULL)
            return -1;

        TreeNode* current = root;
        TreeNode* pre;

        // begin count
        while (current != NULL)
        {
                if (current->left == NULL)
                {
                        current = current->right;
                }
                else
                {
                // Current inorder
                        pre = current->left;
                        while (pre->right != NULL && pre->right != current)
                        {
                                pre = pre->right;
                        }
                        // Turn current into right child of parent
                        if (pre->right == NULL)
                        {
                                pre->right = current;
                                current = current->left;
                                count++;
                        }
                        // Fix changes for right child if need be
                        else
                        {
                                 pre->right = NULL;
                                 current = current->right;
                        }
                }
        }
        // give final count
        return count;
}

// Ancestors
// Function: Search the tree and print the ancestors of a given node where item is stored.
// Precondition: The tree has been initialized. item is in the tree.
// Postcondition: The tree has not been changed. Do not print the node itself.
void TreeType::Ancestors(ItemType item)
{
        TreeNode* copy = new TreeNode;
        copy = root;
        // if empty
        if (copy == NULL)
                cout << "NULL" << endl;
        // if equal
        if(item.ComparedTo(copy->info) == EQUAL)
        {
                cout << item << " is the root." << endl;
        }
        else
        {
                // less vs greater
                while(item.ComparedTo(copy->info) != EQUAL)
                {
                        switch(item.ComparedTo(copy->info))
                        {
                                case LESS:
                                        cout << copy->info << " is an ancestor of " << item << endl;
                                        copy = copy->left;
                                        break;
                                case GREATER:
                                        cout << copy->info << " is an ancestor of " << item << endl;
                                        copy = copy->right;
                                        break;
                        }
                }
        }
}

// Swap (2 Parts) (Function Overloading)
// Function: Swap the left and the right children of every node of the node
// Precondition: These two trees have been initialized.
// Postcondition: The original tree is unchanged. The newTree is the mirror image of the original tree.
// Recursion Swap Idea based on Zelikovits @ CUNY
void TreeType::Swap(TreeType &newTree)
{
        Swap(root, newTree.root);
}

void TreeType::Swap(const TreeNode* originalTree, TreeNode*& copy)
{
        if (originalTree == NULL)
        {   
                copy = NULL;
        }   
        else
        {   
                copy = new TreeNode;
                copy->info = originalTree->info;
		// call earlier swap function
                Swap(originalTree->right, copy->left);
                Swap(originalTree->left, copy->right);
        }   

}

// MyDeleteNode
/* Function: Delete the node pointed to by treeNode. This function is
similar to the one we discussed in class with one difference,
the node has two children is replaced by its immediate
successor instead of its predecessor.

Precondition: The tree has been initialized. tree may have zero, one or two children.

Postcondition: treeNode is no longer in the binary search tree. If treeNode is
a leaf node or has only one non-NULL child node, treeNode
is deleted; otherwise, the info saved in treeNode is replaced
by its logical successor and the successor’s node is deleted.
*/
// Used for right side this time
void TreeType::MyDeleteNode(TreeNode *&treeNode)
{

       ItemType data;
       TreeNode* tempPtr;

        tempPtr = treeNode;
        // if left or right == NULL, delete
        if (treeNode->left == NULL) {
              treeNode = treeNode->right;
              delete tempPtr;
        }else if (treeNode->right == NULL){
              treeNode = treeNode->left;
              delete tempPtr;
       }else
       // if !NULL condition
       {
               GetPredecessor(treeNode->right, data);
               treeNode->info = data;
               Delete(treeNode->right, data);
        }
}
