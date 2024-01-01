#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

// from class
template <typename T>
class TreeNode{
public:
    TreeNode(T d);
    virtual ~TreeNode();
    T getData();

    template <typename S>
    friend class LazyBST;

private:
    T m_data;
    TreeNode<T>* m_left;
    TreeNode<T>* m_right;
    int depth = 1;

    int getMaxDepth();

};

template<typename T>
int TreeNode<T>::getMaxDepth() {
    int rightDepth = m_right == NULL ? 0 : m_right->depth;
    int leftDepth = m_left == NULL ? 0 : m_left->depth;
    return max(rightDepth, leftDepth);
}

template <typename T>
TreeNode<T>::TreeNode(T d){
    m_data = d;
    m_left = NULL;
    m_right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode(){
    if(m_left != NULL){
        delete m_left;
    }
    if(m_right != NULL){
        delete m_right;
    }
}

template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}

#endif