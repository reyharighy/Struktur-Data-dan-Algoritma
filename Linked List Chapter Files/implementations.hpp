#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H
// for data structures that implement the linkedlist class as defined in ./linkedlist.hpp.
#include "linkedlist.hpp"

namespace Implementations {
    template <typename T>
    class Stack {
        private:
            int size{}; 
            int top{-1};
            LinkedList::LinkedList<T> stack = LinkedList::LinkedList<T>();
        public:
            Stack(int size = -1) {
                this->size = size;
            }
            bool isEmpty() {
                return top == -1;
            }
            bool isFull() {
                return (top == size - 1) && (size != -1);
            }
            void push(T item) {
                if (!isFull()) {
                    stack.add(item);
                    ++top;
                }
            } 
            T pop() {
                T data = stack.take(top);
                --top;
                return data;
            }
            T peek() {
                return stack.get(top);
            }
    };
    
    template <typename T>
    class Queue {
        private:
            LinkedList::LinkedList<T> queue = LinkedList::LinkedList<T>();
            int size{};
            int front{-1};
            int rear{-1};
        public:
            Queue(int size) {
                this->size = size;
            }
            bool isEmpty() {
                return front == -1 && rear == -1;
            }
            bool isFull() {
                return front == 0 && rear == size - 1;
            }
            void enqueue(T item) {
                if (!isFull()) {
                    queue.add(item);
                    if (isEmpty()) {
                        front = 0;
                    }
                    ++rear;
                }
                else {
                    throw std::out_of_range("Queue is full.");
                }
            }
            T dequeue() {
                if (!isEmpty()) {
                    T data = queue.take(front);
                    --rear;
                    if (rear < front) {
                        front = -1;
                    }
                    return data;
                }
                throw std::out_of_range("Queue is empty.");
            }
    };
}   

#endif