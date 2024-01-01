#ifndef BST_H
#define BST_H

#include "TreeNode.h"

template <typename T>
class LazyBST {
public:
    LazyBST();
    virtual ~LazyBST();
    bool iterContains(T d);
    bool contains(T d); // recursive version that uses recContainsHelper
    void printInOrder(); // least to greatest
    void printTreePostOrder(); // left tree then right tree then root
    // lecture 18
    void insert(T d);
    int size();

    T max(); // right most child
    T min(); // left most child
    T median(); // will only work if tree is balanced
    void remove(T d);

    friend class Database;

private:
    TreeNode<T> *m_root;
    int m_size;

    bool recContainsHelper(TreeNode<T> *n, T d);
    void printIOHelper(TreeNode<T> *n);
    void printTreePostOrderHelper(TreeNode<T> *subTreeRoot);

    void insertHelper(TreeNode<T> *&subTreeRoot, T &d);
    T getMaxHelper(TreeNode<T> *n);
    T getMinHelper(TreeNode<T> *n);

    void findTarget(T key, TreeNode<T> *&target, TreeNode<T> *&parent);
    TreeNode<T> *getSuccessor(TreeNode<T> *rightChild);
    void removeHelper(TreeNode<T> *target, TreeNode<T> *parent, T t);

    bool isBalanced();
    TreeNode<T>* rebalance(T* elements, int start, int end);
    T& find(T d);
    T* all();

    void getAllHelper(TreeNode<T> *n, T *t, int i);

};

template <typename T>
LazyBST<T>::LazyBST(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
LazyBST<T>::~LazyBST(){
}


// how do we find whether or not a tree contains a key?
// navigate through the tree until we find it
// well it's not linear and each node has a left and right child potentially so...

// let's say we are at the root and we assume the root is not null
// how do we know if the tree contains "d"?
// let's try iteratively
template <typename T>
bool LazyBST<T>::iterContains(T d){
    if (m_root == NULL){ // tree is empty
        return false;
    }
    if (m_root -> data == d){ // root is the key d
        return true;
    }

    // look for d
    bool found = false;
    TreeNode<T>* current = m_root;
    while (!found){
        // check if d is greater than current go right
        if (d > current -> m_data){
            current = current -> m_right;
        } else { // if d is less than/ == current go left
            current = current -> m_left;
        }
        // check if current node is NULL -> we've reached a leaf and d was not found
        if (current == NULL){
            found =  false;
            break;
        }

        // check if the current node's data is d -> we found d
        if (current -> m_data == d){
            found = true;
        }
    }
    return found;
}

// RECURSIVE CONTAINS
template <typename T>
bool LazyBST<T>::contains(T d){
    return recContainsHelper(m_root, d);
}

// RECURSIVE CONTAINS HELPER
template <typename T>
bool LazyBST<T>::recContainsHelper(TreeNode<T>* n, T d){
    if (n == NULL){ // if it is null then d is not in tree
        return false;
    }
    if (n -> m_data == d) { // if it is not null, is it here?
        return true;
    }
    if (d > n -> m_data){ // it's not null but it's also not here, check if it is > or <
        return recContainsHelper( n -> m_right, d);
    } else {
        return recContainsHelper( n -> m_left, d);
    }
}

template <typename T>
void LazyBST<T>::printInOrder(){
    printIOHelper(m_root);
}

template <typename T>
void LazyBST<T>::printIOHelper(TreeNode<T>* n){
    if (n != NULL){ // is the node null?
        printIOHelper(n -> m_left); // if not then print the left thing
        std::cout << n -> m_data << std::endl; // then print the key of the curr node
        printIOHelper(n -> m_right); // then print the right thing
    }
}

template <typename T>
void LazyBST<T>::printTreePostOrder(){
    printTreePostOrderHelper(m_root);
}

template <typename T>
void LazyBST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreePostOrderHelper(subTreeRoot->m_left);
        printTreePostOrderHelper(subTreeRoot->m_right);
        std::cout << subTreeRoot->m_data << std::endl;
    }
}

// INSERT RECURSIVETY
template <typename T>
void LazyBST<T>::insert(T d){
    insertHelper(m_root, d);
    ++m_size;

    if (!isBalanced()) {
        m_root = rebalance(all(), 0, size()-1);
    }
}

// INSERT HELPER SO WE DO NOT HAVE TO PASS IN ROOT
// pass in by reference so that you don't have to manually mess with pointers (r & l children)
template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot, T& d){
    if(subTreeRoot == NULL){
        subTreeRoot =  new TreeNode<T>(d); // insert here  & stop recursive call
    } else if(d > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, d);
    } else{ // Less than or = to so we will have repeats in this tree.
        // Some say duplicates are not allowed in trees but you can alternatively
        // choose whether to put them to leftDepth or rightDepth as long as you're consistent
        insertHelper(subTreeRoot->m_left, d);
    }

    subTreeRoot->depth = subTreeRoot->getMaxDepth() + 1;
}

// HELPER METHODS

// GET SIZE
template <typename T>
int LazyBST<T>::size(){
    return m_size;
}

// GET MAX
template <typename T>
T LazyBST<T>::max(){
    return getMaxHelper(m_root);
}

template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T>* n){
    if(n -> m_right == NULL){
        return n -> m_data;
    } else {
        return getMaxHelper(n -> m_right);
    }
}

// GET MIN
template <typename T>
T LazyBST<T>::min(){
    return getMinHelper(m_root);
}

template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T>* n){
    if(n -> m_left == NULL){
        return n -> m_data;
    } else {
        return getMinHelper(n -> m_left);
    }
}


// GET MEDIAN - ONTY WORKS IF TREE IS BALANCED!
template <typename T>
T LazyBST<T>::median(){
    if (m_root != NULL) {
        return m_root->m_data;
    } else {
        return new T;
    }
}

// HELPER METHODS
template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    // FIND THE NODE WE WANT TO DELETE AND ITS PARENT NODE
    while (target != NULL && target -> m_data != key){ // while target still has children and it is not our actual target
        parent = target;
        if (key < target -> m_data){ // if the key is less than the current target node, keep going left
            target = target -> m_left;
        } else {
            target = target -> m_right;
        }
    }
}

template <typename T>
TreeNode<T>* LazyBST<T>::getSuccessor (TreeNode<T>* rightChild){
    while (rightChild -> m_left != NULL){ // If the node coming in (rightChild) doesn't have a left child then this is our successor and we're done, else:
        rightChild = rightChild -> m_left;
    }
    return rightChild; // not really (necessarily) a right child, this is the successor!
}

template <typename T>
void LazyBST<T>::remove(T d){
    removeHelper(m_root, NULL,d);

    if (!isBalanced()) {
        m_root = rebalance(all(), 0, size() - 1);
    }
}

template <typename T>
void LazyBST<T>::removeHelper(TreeNode<T>* target, TreeNode<T>* parent, T t){
    if (target == NULL) return;

    // We found the right node to remove
    if (target->m_data == t) {
        // SCENARIO 1: TARGET IS A LEAF (INCLUDING ROOT)
        if (target -> m_left == NULL && target -> m_right == NULL){
            if (target == m_root){
                m_root = NULL;
            } else { // if it's a leaf but not the root
                // check if target is its parent's left or right child
                if (target == parent -> m_left){ // if target is a left child
                    parent -> m_left = NULL;
                } else { // target is a right child
                    parent -> m_right = NULL;
                }
            }
            delete target;
            -- m_size;
        }

        // SCENARIO 3: TARGET HAS TWO CHILDREN
        else if (target -> m_left != NULL && target -> m_right != NULL){  // both children pointers are not null
            TreeNode<T>* suc = getSuccessor(target -> m_right);
            T value = suc -> m_data;
            remove(value); // goes in the LazyBST remove method and removes the node w/ d = value
            target -> m_data = value;
        }

        // SCENARIO 2: TARGET HAS 1 CHILD
        else {
            TreeNode<T>* child;
            // check whether target has a left or right child
            if (target -> m_left != NULL){ // target has a left child
                child = target -> m_left;
            } else{                        // target has a right child
                child = target -> m_right;
            }

            if (target == m_root){
                m_root = child;
            } else {
                if (target == parent -> m_left){ // our target is a left child
                    parent -> m_left = child; // make the parent's left child the target's child
                } else {                       // our target is a right child
                    parent -> m_right = child; // make the parent's right child the target's child
                }
            }
            target -> m_left = NULL;
            target -> m_right = NULL;

            delete target;
            -- m_size;
        }
        return;

    // Binary search on the right subtree
    } else if (target->getData() < t) {
        removeHelper(target->m_right, target, t);
    // Binary search on the left subtree
    } else {
        removeHelper(target->m_left, target, t);
    }

    // As we are coming out of the recursion, keep the subtree depth up to date.
    target->depth = target->getMaxDepth() + 1;
}

// NEW METHODS
template<typename T>
T& LazyBST<T>::find(T d) {
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d, target, parent);

    if (target != NULL) {
        return target->m_data;
    } else {
        return d;
    }
}

template<typename T>
T* LazyBST<T>::all() {
    T* result = new T[size()];
    getAllHelper(m_root, result, 0);
    return result;
}

template <typename T>
void LazyBST<T>::getAllHelper(TreeNode<T>* n, T* t, int i) {
    if (n == NULL) return;

    // In-order traversal of the binary tree
    getAllHelper(n -> m_left, t, i);
    t[i++] = n->m_data;
    getAllHelper(n -> m_right, t, i);
}

template <typename T>
bool LazyBST<T>::isBalanced() {
    if (m_root == NULL) return true;

    int rightDepth = m_root->m_right == NULL ? 0 : m_root->m_right->depth;
    int leftDepth = m_root->m_left == NULL ? 0 : m_root->m_left->depth;
    int heightDiff = abs(rightDepth - leftDepth);

    // Special cases:
    // - A one level difference is natural in a BST and cannot be optimized.
    // - Zero-depths throw off the formula and need to be handled separately.
    if (heightDiff <= 1) {
        return true;
    } else if (rightDepth == 0 || leftDepth == 0) {
        return false;
    }

    // The node (and tree in general) is not balanced if its left subtree is 50% taller
    // than the right subtree, or vice-versa, its right subtree is 50% taller than the left subtree.
    // 1.5h < diff + h => 1.5h - h < diff => 0.5h < diff
    return 0.5 * rightDepth <= heightDiff && 0.5 * leftDepth <= heightDiff;
}

// Recursive rebalance of a subtree.
template <typename T>
TreeNode<T>* LazyBST<T>::rebalance(T* elements, int start, int end) {
    if (start > end) {
        return NULL;
    }

    if (start == end) {
        return new TreeNode<T>(elements[start]);
    }

    // The median value of the collection is chosen and inserted into a new LB-BST as the root
    // of the new subtree.
    int median = (start + end) / 2;
    TreeNode<T>* result = new TreeNode<T>(elements[median]);

    // Rebalance the right and left subtrees recursively
    result->m_left = rebalance(elements, start, median - 1);
    result->m_right = rebalance(elements, median + 1, end);

    // Update the depth of each node in the subtree as we're coming out of the recursion,
    // after child nodes were rebalanced.
    result->depth = result->getMaxDepth() + 1;

    return result;
}

#endif