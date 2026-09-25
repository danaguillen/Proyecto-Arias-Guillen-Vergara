#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    bool removeAt(int index) {
        if (index < 0 || index >= size || head == nullptr) return false;
        Node<T>* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return false;
        Node<T>* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
        size--;
        return true;
    }

    T get(int index) const {
        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) return temp->data;
            count++;
            temp = temp->next;
        }
        return nullptr;
    }

    int getSize() const { return size; }
    bool isEmpty() const { return head == nullptr; }
};

#endif