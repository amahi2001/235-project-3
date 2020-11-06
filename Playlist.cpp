#include "Playlist.hpp"

Playlist::Playlist() : DoublyLinkedList()
{
}

double Playlist::getTotalTime() const
{
    double sum =0.0; 
    int size = this->getSize();
    for (int i = 1; i <= size; i++) //loop throuuugh the array
    {
        sum += this->getAtPos(i)->getItem()->getLength(); //increment the sum
    }
    return sum;
}

void Playlist::operator+=(Playlist rhs)
{
    int thisItemCount = this->itemCount;
    int rhsItemCount = rhs.itemCount;

    for (int i = 1; i <= rhsItemCount; i++)
    {
        this->insert(rhs.getAtPos(i)->getItem(), thisItemCount + i); //loop through the callee and add its items to the caller
    }
}

void Playlist::operator-=(Playlist rhs)
{
    int thisItemCount = this->itemCount;
    int rhsItemCount = rhs.itemCount;
    for (int i = 1; i < thisItemCount; i++)
    {
        for (int j = 1; j < rhsItemCount; j++) //loop through the caller then the callee
        {
            bool flag = (this->getAtPos(i)->getItem()) == (rhs.getAtPos(j)->getItem()); 

            switch (flag)
            {
            case true: //if they have matching items
                this->remove(i); //remove the items
                break;
            }
        }
    }
}

void Playlist::skip()
{

    int thisSize = this->getSize();
    this->insert(this->getHeadPtr()->getItem(), thisSize + 1); //headptr points to the tail
    this->remove(1); //remove the head
}

void Playlist::rewind()
{
    int thisSize = this->getSize();
    this->insert(this->getAtPos(thisSize)->getItem(), 1); //tail points to the head
    this->remove(thisSize + 1); //remove the tail
}

void Playlist::display()
{
    int thisCount = this->getSize();
    for (int i = 1; i <= thisCount; i++) //loop through caller
    {
        bool flag = (this->getAtPos(i)->getItem() != nullptr); 
        switch (flag)
        {
        case true: //if items not null
            this->getAtPos(i)->getItem()->display(); //display them
            break;
        }
    }
}
