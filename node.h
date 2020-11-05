#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(student*);
  ~Node();
  student* getStudent();
  void setStudent(student*);
  void setNext(Node*);
  Node* getNext();
 private:
  student* nodeStudent;
  Node* next;
};
#endif
