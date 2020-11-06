
#ifndef DOUBLENODE_H
#define DOUBLENODE_H
#include <iostream>
using namespace std;

template <typename ItemType>
class DoubleNode
{
private:
    ItemType item_;
    DoubleNode<ItemType> *next_;
    DoubleNode<ItemType> *prev_;

public:

    //constructors
    DoubleNode(); 
    DoubleNode(const ItemType& an_item); 
    DoubleNode(const ItemType& an_item, DoubleNode<ItemType>* next_node_ptr, DoubleNode<ItemType>* prev_node_ptr);
    
    // Setter Functions
    void setItem(const ItemType &anItem);
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);
    void setNext(DoubleNode<ItemType> *nextNodePtr);

    // Getter Functions
    ItemType getItem() const;
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrevious() const;
};
#include "DoubleNode.cpp"
#endif