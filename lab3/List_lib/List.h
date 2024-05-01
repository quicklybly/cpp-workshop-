//
// Created by quicklybly on 5/1/24.
//

#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include <string>

namespace list {
    template<class T>
    class List {
    private:
        struct Node {
            Node* next;
            Node* prev;
            T data;

            explicit Node(const T& data) : data(data), next(nullptr), prev(nullptr) {};
        };

        Node* head;
        Node* tail;
        size_t size{};
    public:
        List();
        ~List();

        size_t getSize();
        T getFirst();
        T getLast();
        void removeAt(size_t index);
        void append(const T &data);
        T &operator[](size_t index);
    };

    template<class T>
    List<T>::~List() {
        while (head) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    template<class T>
    List<T>::List(): head(nullptr), tail(nullptr), size(0) {}

    template<class T>
    T List<T>::getFirst() {
        return head->data;
    }

    template<class T>
    T List<T>::getLast() {
        return tail->data;
    }

    template<class T>
    size_t List<T>::getSize() {
        return size;
    }

    template<class T>
    void List<T>::append(const T &data) {
        Node *node = new Node(data);
        if (!head) {
            head = node;
        } else {
            node->prev = tail;
            tail->next = node;
        }
        tail = node;
        ++size;
    }

    template<class T>
    void List<T>::removeAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* tmp = head;

        while(index--) {
            tmp = tmp->next;
        }

        if (tmp->prev) {
            tmp->prev->next = tmp->next;
        } else {
            head = tmp->next;
        }

        if (tmp->next) {
            tmp->next->prev = tmp->prev;
        } else {
            tail = tmp->prev;
        }

        delete tmp;
        --size;
    }

    template<class T>
    T &List<T>::operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node *tmp = head;
        while (index--) {
            tmp = tmp->next;
        }

        return tmp->data;
    }
}

#endif //LAB2_LIST_H
