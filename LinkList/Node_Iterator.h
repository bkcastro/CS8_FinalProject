//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_NODE_ITERATOR_H
#define CS8_FINALPROJECT_NODE_ITERATOR_H
#include "Node.h"
#include <iterator>

template <class T>
class Node_Iterator {
private:
    Node<T>* current;

public:

    Node_Iterator();
    explicit Node_Iterator(Node<T>* initial);

    Node_Iterator& operator ++();
    const Node_Iterator operator ++(int);

    Node_Iterator& operator --();
    const Node_Iterator operator --(int);

    const T& operator*() const;
    T& operator*();

    template<class S>
    friend bool operator ==(const Node_Iterator<S>& left, const Node_Iterator<S>& right);

    template<class S>
    friend bool operator !=(const Node_Iterator<S>& left, const Node_Iterator<S>& right);

};

#include "Node_Iterator.cpp"
#endif //CS8_FINALPROJECT_NODE_ITERATOR_H
