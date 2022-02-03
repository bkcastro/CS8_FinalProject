//
// Created by Brandon Castro on 12/9/21.
//
#ifndef SFMLTEXTPROJECT_LINKLIST_CPP
#define SFMLTEXTPROJECT_LINKLIST_CPP
#include "LinkList.h"

template <class T>
Linklist<T>::Linklist() = default;

template <class T>
Linklist<T>::~Linklist()
{
    this->clear();
}

template <class T>
T Linklist<T>::getHead() const
{
    return head->data;
}

template <class T>
T Linklist<T>::getTail() const
{
    return tail->data;
}

/*
template <class T>
Node<T>* Linklist<T>::search(T input)
{
    Node<T>* walker = head;

    while(walker!= nullptr)
    {
        if (walker->data == input)
        {
            return walker;
        }

        walker = walker->next;
    }

    return nullptr;
}
*/


template <class T>
void Linklist<T>::insertTail(T input)
{
    auto* temp = new Node<T>;
    temp->data = input;

    if (head == nullptr)
    {
        // when size = 0;
        insertHead(input);
    }
    else
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

template <class T>
void Linklist<T>::insertHead(T input)
{
    auto* temp = new Node<T>;
    temp->data = input;

    if (head == nullptr)
    {
        // when size = 0;
        tail = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

template <class T>
void Linklist<T>::insertBefore(T insertThis, T beforeThat)
{
    Node<T>* before = search(beforeThat);

    if (before == head)
    {
        insertHead(insertThis);
    }
    else if (before != nullptr)
    {
        Node<T>* after = before->previous;
        auto* temp = new Node<T>;
        temp->data = insertThis;

        temp->previous = after;
        temp->next = before;
        before->previous = temp;
        after->next = temp;
    }
}

template <class T>
void Linklist<T>::insertAfter(T insertThis, T afterThat)
{
    Node<T>* after = search(afterThat);

    if (after == tail)
    {
        insertTail(insertThis);
    }
    else
    {
        auto* temp = new Node<T>;
        temp->data = insertThis;

        Node<T>* before = after->next;

        temp->previous = after;
        temp->next = before;
        after->next = temp;

        if (before != nullptr)
        {
            before->previous = temp;
        }

    }
}

template <class T>
void Linklist<T>::clear()
{
    iterator iter = begin();

    while (iter != end())
    {
        ++iter;
        removeHead();
    }
    std::cout << "Linklist has been cleared." << std::endl;
}

/*
template <class T>
bool Linklist<T>::remove(T input)
{
    Node<T>* n = search(input);

    if (n != nullptr)
    {
        // then delete that node;
        Node<T> *after = n->previous;
        Node<T> *before = n->next;

        // if n is a head or the size is 1
        if (n == head) // this is a head
        {
            head = before;

            if (n == tail) // also a tail
            {
                tail = after; // which is null
            }
            else // size of the list is not 1
            {
                head->previous = nullptr;
            }

            delete n;
        }
        else if (n == tail) // this is a tail and the size is not 1
        {
            // we know that n has a previous node
            tail = after;
            tail->next = nullptr;

            delete n;
        }
        else // not a head or tail 3 or more nodes
        {
            after->next = before;
            before->previous = after;

            delete n;
        }
    }
    else
    {
        return false;
    }

    return true;
}
 */

template <class T>
bool Linklist<T>::empty() const
{
    if (head == nullptr)
    {
        return true;
    }

    return false;
}

template <class T>
int Linklist<T>::size() const
{
    Node<T>* walker = head;
    int amount = 0;

    while (walker != nullptr)
    {
        walker = walker->next;
        amount++;
    }

    return amount;
}

template <class T>
void Linklist<T>::removeTail()
{
    Node<T>* hold = tail;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = hold->previous;
        tail->next = nullptr;
    }

    delete hold;
}

template <class T>
void Linklist<T>::removeHead()
{
    Node<T>* hold = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = hold->next;
        head->previous = nullptr;
    }

    delete hold;
}

template <class T>
Linklist<T>& Linklist<T>::operator=(const Linklist<T>& list)
{
    this->clear();
    Node<T>* walker = list.head;

    while (walker != nullptr)
    {
        this->insertTail(walker->data);
        walker = walker->next;
    }

    return *this;
}

template <class T>
void Linklist<T>::operator+=(const T& input)
{
    this->insertTail(input);
}

template<class T>
std::ostream& operator <<(std::ostream& out, const Linklist<T>& list)
{
    std::cout << "Link List: ";

    Node<T>* walker = list.head;

    while (walker != nullptr)
    {
        std::cout << walker->data << " ";
        walker = walker->next;
    }

    return out;
}

template<class T>

T Linklist<T>::operator[](unsigned int index)
{
    Node<T>* walker = head;

    if (index < this->size())
    {
        for (int i = 1; i < index; i++)
        {
            walker = walker->next;
        }

        return walker->data;
    }
    else
    {
        std::cout << "Index is out of bounds" << std::endl;
        return 0;
    }
}


template<class T>
typename Linklist<T>::iterator Linklist<T>::begin() {
    return Node_Iterator<T>(head);
}

template<class T>
typename Linklist<T>::iterator Linklist<T>::end() {
    return Node_Iterator<T>();
}

template<class T>
typename Linklist<T>::iterator Linklist<T>::endValue()
{
    return Node_Iterator<T>(tail);
}

template<class T>
typename Linklist<T>::iterator Linklist<T>::begin() const
{
    return Node_Iterator<T>(head);
}

template<class T>
typename Linklist<T>::iterator Linklist<T>::end() const
{
    return Node_Iterator<T>();
}

template<class T>
Node<T>* Linklist<T>::getHeadPtr() const
{
    return head;
}

template<class T>
Node<T>* Linklist<T>::getTailPtr() const
{
    return tail;
}
#endif