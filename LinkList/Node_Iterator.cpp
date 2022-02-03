//
// Created by Brandon Castro on 12/9/21.
//
#ifndef SFMLTEXTPROJECT_NODE_ITERATOR_CPP
#define SFMLTEXTPROJECT_NODE_ITERATOR_CPP
#include "Node_Iterator.h"

template<class T>
Node_Iterator<T>::Node_Iterator() : Node_Iterator(nullptr) {}

template<class T>
Node_Iterator<T>::Node_Iterator(Node<T>* initial) : current(initial){}

template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator --()
{
    current = current->previous;
    return *this;
}

template<class T>
const Node_Iterator<T> Node_Iterator<T>::operator --(int)
{
    Node_Iterator<T> hold(current);
    current = current->previous;
    return hold;
}

template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator ++()
{
    current = current->next;
    return *this;
}

template<class T>
const Node_Iterator<T> Node_Iterator<T>::operator ++(int)
{
    Node_Iterator<T> hold(current);
    current = current->next;
    return hold;
}

template<class T>
const T& Node_Iterator<T>::operator*() const
{
    return current->data;
}

template<class T>
T& Node_Iterator<T>::operator*()
{
    return current->data;
}

template<class S>
bool operator ==(const Node_Iterator<S>& left, const Node_Iterator<S>& right)
{
    return left.current == right.current;
}


template<class S>
bool operator !=(const Node_Iterator<S>& left, const Node_Iterator<S>& right)
{
    return left.current != right.current;
}

#endif