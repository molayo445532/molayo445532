#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO 
      if(isEmpty()){
        root = new Node<KeyType, ItemType>;
        root->key = key;
        root->data = item;
        return true;

    }else{
        Node<KeyType, ItemType> *node = root;

        
        while(node != NULL && key != node->key){
            if(key < node->key){
                if(node->left == NULL){
                    node->left = new Node<KeyType, ItemType>;
                    node = node->left;

                    if(node->key == key){
                        return false;
                    }

                    node->data = item;
                    node->key = key;

                    return true;
                }
                node = node->left;
            }
            
            
            if(key > node->key){
                if(node->right == NULL){
                    node->right = new Node<KeyType, ItemType>;

                    node = node->right;

                    if(node->key == key){
                        return false;
                    }

                    node->data = item;
                    node->key = key;

                    return true;
                }
                node = node->right;
            }
        }
    }
    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
   if (isEmpty())
        return false; // empty tree

    // TODO
    
Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key,curr,curr_parent);
    // case one thing in the tree
    if(root->right==0&&root->left==0){
        destroy();
        return true;
    }
    // case, found deleted item at leaf
    else if(curr->right==0&&curr->left==0){
        curr=0;
        key=0;
        return true;
    }
    // case, item to delete has only a right child
    else if(curr->left==0&&curr->right!=0){
        curr=curr->right;
        curr->right=0;
        key=0;
        return true;
    }
    // case, item to delete has only a left child
    else if(root->left!=0&&root->right==0){
        curr=curr->left;
        curr->left=0;
         key=0;
        return true;
    }

    // case, item to delete has two children
    else if(root->left!=0&&root->right!=0){
        curr=curr->left;
        curr->left=curr->right;
        curr->right=0;
        key=0;
        return true;
    }

    return false; // default should never get here

    
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO 
    // move right once
    // move left as far as possible
   in = curr->right;
    parent = curr;

    while(in->left != NULL){
        in = in->left;
        parent = parent->left;
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // TODO: check for duplicate items in the input array
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
    if(arr[i]==arr[j]){
        std::cout<<"no duplicates"<<std::endl;
        return;
    }
}
}
    // TODO: use the tree to sort the array items


    // TODO: overwrite input array values with sorted values
}
