//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_NODE_H
#define CS8_FINALPROJECT_NODE_H
template<class T>
struct Node
{
    Node();
    explicit Node(T input);

    T data;
    Node<T>* next = nullptr;
    Node<T>* previous = nullptr;
};

template<class T>
Node<T>::Node(T input) {
    data = input;
}

template<class T>
Node<T>::Node() = default;

#endif //CS8_FINALPROJECT_NODE_H
