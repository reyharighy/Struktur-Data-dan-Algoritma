#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <stdexcept>
#include <iostream>

// for Linked List and Doubly Linked List

namespace LinkedListImplementation {
    template <typename T>
    struct Node {
        T data;
        Node<T>* next{nullptr};
    };

    template <typename T>
    class LinkedList {
        protected:
            Node<T>* getNodePointer(size_t index) { // returns a pointer to a node at a given index
                Node<T>* currentNode = head;
                for (int i{0}; i < index; ++i) {
                    if (currentNode->next == nullptr) { // Checks if the next points to nullptr, before moving to it. 
                        throw std::out_of_range("Index out of bounds.");  
                    }
                    currentNode = currentNode->next;
                }
                return currentNode;
            }
            Node<T>* head{nullptr};
            // int size{0};
            // int maxsize{-1};
        public:
            LinkedList() {}
            LinkedList(const LinkedList& other) {
                Node<T>* prevNode{nullptr};
                for (Node<T>* otherNode{other.head}; otherNode != nullptr; otherNode = otherNode->next) {
                    auto* node = new Node<T>{*otherNode};

                    if (head == nullptr) {
                        head = node;
                    }
                    if (prevNode != nullptr) {
                        prevNode->next = node;
                    }
                    prevNode = node;
                }
            }
            void add(T value) { // appends node to the linkedlist.
                Node<T>* node = new Node<T>;
                node->data = value;

                if (head == nullptr) {
                    head = node;
                }
                else {
                    Node<T>* currentPtr = head;
                    while (currentPtr->next != nullptr) {
                        currentPtr = currentPtr->next;
                    }
                    currentPtr->next = node;
                }
            };
            void add(size_t index, T value) { // adds a node at a given index
                Node<T>* newNode = new Node<T>;
                newNode->data = value;

                if (index == 0) { // for insertion on the head.
                    newNode->next = head;
                    head = newNode;
                }
                else {
                    Node<T>* currentNode = head;
                    for (int i = 0; i < index - 1; ++i) {
                        if (currentNode->next == nullptr) {
                            throw std::out_of_range("Index out of bounds.");
                        }

                        currentNode = currentNode->next;
                    }
                    newNode->next = currentNode->next;
                    currentNode->next = newNode;
                }
            };
            void remove(size_t index) { // removes an element at a given index
                if (index == 0) { // for head deletion.
                    Node<T>* nodeToBeDeleted = head;
                    head = head->next;
                    delete nodeToBeDeleted;
                }
                else {
                    Node<T>* currentNode = head;
                    Node<T>* previousNode = nullptr;
                    for (int i = 0; i < index; ++i) {
                        if (currentNode->next == nullptr) {
                            throw std::out_of_range("Index out of bounds.");
                        }

                        previousNode = currentNode;
                        currentNode = currentNode->next;
                    }
                    previousNode->next = currentNode->next;
                    delete currentNode;
                }
            };
            T take(size_t index) { // removes the element at a given index and returns the element given. 
                T takenItem = get(index);
                remove(index);
                return takenItem;
            };
            T get(size_t index) { // returns data from a node at a given index.
                Node<T>* currentNode = head;
                for (int i = 0; i <= index; ++i) {
                    if (i == index) {
                        return currentNode->data;
                    }
                    if (currentNode->next == nullptr) {
                        break;
                    }
                    currentNode = currentNode->next;
                }
                throw std::out_of_range("Index out of bounds");
            };
            size_t length() { // returns the number of elements.
                int i{0};
                Node<T>* currentNode = head;
                if (head != nullptr) {
                    while (currentNode->next != nullptr) {
                        ++i;
                        currentNode = currentNode->next;
                    }
                    ++i;
                }
                return i;
            };
            void removeAll() { // removes all elements from the list.
                while(head) {
                    remove(0);
                };
            };
            void swap(size_t index1, size_t index2) { // swaps data of two nodes.
                Node<T>* first = getNodePointer(index1);
                Node<T>* second = getNodePointer(index2);
                
                T temp = first->data;
                first->data = second->data;
                second->data = temp;
            }
            ~LinkedList() { // destructor. 
                removeAll();
            };
    };

    template <typename T>
    class OrderedLinkedList : public LinkedList<T> {
        public:
            void add(std::string newNodeValue) {
                Node<std::string>* newNode = new Node<std::string>;
                newNode->data = newNodeValue;

                if (this->head == nullptr) {
                    this->head = newNode;
                }
                else {
                    // code's shitty but it seems to work best (?)
                    Node<std::string>* currentNode{this->head};
                    Node<std::string>* prevNode{nullptr};
                    while (newNodeValue.compare(currentNode->data) > 0 && currentNode->next != nullptr) { 
                        /* traverse until the new value is less than the current value
                        or the current value's next is a nullptr
                        */
                        prevNode = currentNode;
                        currentNode = currentNode->next;
                    }
                    if (prevNode == nullptr) { // runs if there's only one node: the while breaks when next is nullptr
                        if (newNodeValue.compare(currentNode->data) <= 0) { // checks if the new node is smaller or equal to the only member
                            this->head = newNode;
                            newNode->next = currentNode;
                        }
                        else {
                            currentNode->next = newNode;
                        }
                    }
                    else if (newNodeValue.compare(currentNode->data) <= 0) { // checks if the new value is less than the current value
                        prevNode->next = newNode;
                        newNode->next = currentNode;
                    }
                    else { // checks if the next value of the current node points to nothing
                        currentNode->next = newNode;
                    }
                    
                }
            }
            T get(size_t index) {
                return LinkedList<T>::get(index);
            }
            size_t length() {
                return LinkedList<T>::length();
            }
            void remove(size_t index) {
                LinkedList<T>::remove(index);
            }
            void removeAll() {
                LinkedList<T>::removeAll();
            }
            T take(size_t index) {
                return LinkedList<T>::take(index);
            }
    };

    template<typename T>
    struct DoublyNode {
        T data;
        DoublyNode<T>* prev{nullptr};
        DoublyNode<T>* next{nullptr};
    };

    template<typename T>
    class DoublyLinkedList {
        protected:
            DoublyNode<T>* head{nullptr};
            DoublyNode<T>* tail{nullptr};
        public:
            DoublyLinkedList() {};
            void add(T value) {
                DoublyNode<T>* newNode = new DoublyNode<T>;
                newNode->data = value;

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    DoublyNode<T>* currentNode = head;
                    while (currentNode->next != nullptr) {
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newNode;
                    newNode->prev = currentNode;
                    tail = newNode;
                }
            }
            void remove(size_t index) {
                if (index == 0) {
                    DoublyNode<T>* nodeToRemove = head;
                    this->head = head->next;
                    head->prev = nullptr;
                    delete nodeToRemove;
                }
                else {
                    DoublyNode<T>* currentNode = head;
                    for (int i = 0; i < index; ++i) {
                        if (currentNode->next == nullptr) {
                            throw std::out_of_range("Index out of range");
                        }
                        currentNode = currentNode->next;
                    }
                    if (currentNode->next != nullptr) {
                        currentNode->next->prev = currentNode->prev;
                    }
                    if (currentNode->prev != nullptr) {
                        currentNode->prev->next = currentNode->next;
                    }
                    delete currentNode;
                }
            }
            void forwardTraverseDemo() {
                DoublyNode<T>* currentNode = head;
                while (currentNode->next != nullptr) {
                    std::cout << currentNode->data;
                    if (currentNode->next != nullptr) {
                        std::cout << "; ";
                    }
                    currentNode = currentNode->next;
                }
                std::cout << currentNode->data;
                std::cout << "\n";
            }
            void reverseTraverseDemo() {
                DoublyNode<T>* currentNode = tail;
                while (currentNode->prev != nullptr) {
                    std::cout << currentNode->data;
                    if (currentNode->prev != nullptr) {
                        std::cout << "; ";
                    }
                    currentNode = currentNode->prev;
                }
                std::cout << currentNode->data;
                std::cout << "\n";
            }
    };
}

#endif