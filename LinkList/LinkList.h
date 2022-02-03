//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_LINKLIST_H
#define CS8_FINALPROJECT_LINKLIST_H
#include <iostream>
#include "Node.h"
#include "Node_Iterator.h"

template <class T>
class Linklist {
public:
    Linklist();
    ~Linklist();

    typedef Node_Iterator<T> iterator;

    iterator begin();
    iterator end();
    iterator begin() const;
    iterator end() const;
    iterator endValue();


    void insertTail(T input); // inset in the end
    void insertHead(T input); // insert in the beginning
    void insertBefore(T insertThis, T beforeThat);
    void insertAfter(T insertThis, T afterThat);
    void clear();

    // remove functions
    void removeTail();
    void removeHead();
    void removeAt(int index);

    T getHead() const;
    T getTail() const;

    Node<T>* getHeadPtr() const;
    Node<T>* getTailPtr() const;

    bool empty() const;

    int size() const;

    Linklist<T>& operator=(const Linklist<T>& list);
    void operator+=(const T& input);
    T operator[](unsigned int index);

    template<class S>
    friend std::ostream& operator <<(std::ostream& out, const Linklist<S>& list);
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};

#include "LinkList.cpp"
#endif //CS8_FINALPROJECT_LINKLIST_H
