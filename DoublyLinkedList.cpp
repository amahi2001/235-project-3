#include "DoublyLinkedList.hpp"
using namespace std;

template <typename ItemType> //default constructor
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
    itemCount = 0;
    headPtr = nullptr;
}

template <typename ItemType> //copy construcor
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &a_bag)
{
    itemCount = a_bag.itemCount;
    DoubleNode<ItemType> *orig_chain_ptr = a_bag.headPtr; //Points to nodes in original chain
    if (orig_chain_ptr == nullptr)
        headPtr = nullptr; // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new DoubleNode<ItemType>();
        headPtr->setItem(orig_chain_ptr->getItem());
        // Copy remaining nodes
        DoubleNode<ItemType> *new_chain_ptr = headPtr; //Points to last node in new chain
        orig_chain_ptr = orig_chain_ptr->getNext();    //Advance original-chain pointer
        while (orig_chain_ptr != nullptr)
        { // Get next item from original chain
            ItemType next_item = orig_chain_ptr->getItem();
            // Create a new node containing the next item
            DoubleNode<ItemType> *new_node_ptr = new DoubleNode<ItemType>(next_item);
            // Link new node to end of new chain
            new_chain_ptr->setNext(new_node_ptr);
            // Advance pointer to new last node
            new_chain_ptr = new_chain_ptr->getNext();
            // Advance original-chain pointer
            orig_chain_ptr = orig_chain_ptr->getNext();
        } // end while
        new_chain_ptr->setNext(nullptr);
    }
}

template <typename ItemType> //destructor
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        DoubleNode<ItemType> *newNodePtr = new DoubleNode<ItemType>(item);
        // Attach new node to chain
        if (position == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            DoubleNode<ItemType> *prevPtr = getAtPos(position - 1);
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }            // end if
        itemCount++; // Increase count of entries
    }
    return ableToInsert; // end if
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        DoubleNode<ItemType> *curPtr = nullptr;
        switch (position)
        {
        case 1:
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
            break;
        default:
            // Find node that is before the one to remove
            DoubleNode<ItemType> *prevPtr = getAtPos(position - 1);
            // Point to node to remove
            curPtr = prevPtr->getNext();
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--; // Decrease count of entries
    }                // end if
    return ableToRemove;
}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const //getter itemcount
{
    return itemCount;
}

template <typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const //getter hgeadptr
{
    return headPtr;
}

template <typename ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    // Debugging check of precondition
    assert((pos >= 1) && (pos <= itemCount));
    // Count from the beginning of the chain
    DoubleNode<ItemType> *curPtr = headPtr;
    for (int skip = 1; skip < pos; skip++)
        curPtr = curPtr->getNext();
    return curPtr;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    switch (itemCount)
    {
    case 0: //if item count is 0, is empty
        return true;
        break;
    default:
        return false; //else false
        break;
    }
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    while (!isEmpty())
    {
        remove(1); //while the function is not empty, keep[ removing the first item of the list
    }
}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const
{
    DoubleNode<ItemType> *pos_ptr = getPointerTo(item);

    bool flag = (pos_ptr == nullptr);

    switch (flag)
    {
    case true: //iff position ptr is null
        throw(std::out_of_range("getItem called with empty list or invalid position"));
        break; //error
    default:
        return pos_ptr->getItem(); //else point to the item(s)
        break;
    }
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType> *ptr = getHeadPtr();
    int size = this->getSize();
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1) // if the items are not the last item, print and add a space
        {
            cout << ptr->getItem() << " ";
            ptr = ptr->getNext();
        }
        else if (i == (size - 1)) //if the item is the last one, print without a space
        {
            cout << ptr->getItem();
        }
    }
    cout << endl; 
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    int size = this->getSize();
    DoubleNode<ItemType> *ptr = getAtPos(size);

    for (int i = size; i >= 1; i--) //decrement from the tail pointer
    {
        bool flag = (i > 1);
        switch (flag)
        {
        case true: //if the item is not the last, print with a space
            cout << this->getAtPos(i)->getItem() << " ";
            break;
        default: //if the item is the last on the lis,t print without a space
            cout << this->getAtPos(i)->getItem();
            break;
        }
    }
    cout << endl;
}

template <typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list)
{
    DoublyLinkedList<ItemType> newList;
    //int total = thisSize + aSize;
    int i = 1; //incrementer

    DoubleNode<ItemType> *thisPtr = this->getHeadPtr(); //pointing to the callers headptr
    DoubleNode<ItemType> *aPtr = a_list.getHeadPtr();   //pointing to the callees headptr

    while (aPtr != nullptr || thisPtr != nullptr) // while atleast 1 isn't null
    {
        bool thisFlag = (thisPtr != nullptr);
        bool aFlag = (aPtr != nullptr);

        switch (thisFlag)
        {
        case true: //if the caller isn't null, add it to the lsit
            newList.insert(thisPtr->getItem(), i);
            i++;                          //increement
            thisPtr = thisPtr->getNext(); //point to the next item
            break;
        }

        switch (aFlag)
        {
        case true:                              // if the callee isn't null
            newList.insert(aPtr->getItem(), i); //add it to the list
            i++;                                //increment
            aPtr = aPtr->getNext();             //point to the next item in the list
            break;
        }
    }
    return newList; //return the list
}
