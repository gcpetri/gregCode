// SCLL.h
#ifndef SCLL_H
#define SCLL_H

#include <iostream>
#include "Node.h"

template <typename T>
class SortedCircularList {
  Node<T>* head;  
  Node<T>* tail;
public:
  SortedCircularList() : head(nullptr), tail(nullptr) {}
  void print(std::ostream& out=std::cout) const;
  // insert val into a sorted circular list
  void insertValue(const T& val);
};

// print function
template <typename T>
void SortedCircularList<T>::print(std::ostream& out) const {
   Node<T>* current=head;
   if (current!=nullptr) {
      out<<current->data<<" ";
      while(current->next != head)
   {
         current = current->next;   
         out<<current->data<<" ";
      }
   }
}

// WRITE THIS FUNCTION
template <typename T>
void SortedCircularList<T>::insertValue(const T& val)  {
    // TODO(student): insertValue
    Node<T>* node = new Node<T>(val);
    Node<T>* current = head;
    if (current == nullptr) {
        head = node;
        tail = node;
        node->next = node;
        return;
    }
    else if (current->data >= node->data) {
        while (current->next != head) {
            current = current->next;
        }
        current->next = node;
        node->next = head;
        head = node;
    }
    else {
        while (current->next != head && current->next->data < node->data) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

#endif