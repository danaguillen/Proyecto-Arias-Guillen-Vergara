#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyNode {
public:
    T data;
    DoublyNode<T>* next;
    DoublyNode<T>* prev;
    DoublyNode(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        DoublyNode<T>* current = head;
        while (current != nullptr) {
            DoublyNode<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(T val) {
        DoublyNode<T>* newNode = new DoublyNode<T>(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void truncateAfter(DoublyNode<T>* node) {
        if (!node) return;
        DoublyNode<T>* current = node->next;
        node->next = nullptr;
        tail = node;

        while (current != nullptr) {
            DoublyNode<T>* temp = current->next;
            delete current;
            current = temp;
            size--;
        }
    }

    DoublyNode<T>* getHead() const { return head; }
    DoublyNode<T>* getTail() const { return tail; }
    int getSize() const { return size; }
};

#endif