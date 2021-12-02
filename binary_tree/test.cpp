#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("B");
    BinaryTree<ItemType, FunctionType> T2("C");
    BinaryTree<ItemType, FunctionType> T3("D");
    BinaryTree<ItemType, FunctionType> T4("E");
    BinaryTree<ItemType, FunctionType> T5("F");
    BinaryTree<ItemType, FunctionType> T6("G");

    BinaryTree<ItemType, FunctionType> T7("A");
   
    T1.attachLeftSubtree(T2);
    T1.attachRightSubtree(T3);
    T4.attachLeftSubtree(T5);
    T4.attachRightSubtree(T6);
    T7.attachLeftSubtree(T1);
    T7.attachRightSubtree(T4);
    T7.postorderTraverse(&PrintNode);
    T7.preorderTraverse(&PrintNode);
    T7.inorderTraverse(&PrintNode);

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
