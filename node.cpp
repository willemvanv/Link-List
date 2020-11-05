#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(student* newStudent){
  nodeStudent = newStudent;
  next = NULL;
}

Node::~Node(){
  delete &nodeStudent;
  next = NULL;
}

student* Node::getStudent(){
  return nodeStudent;
}

void Node::setStudent(student* addStudent){
  nodeStudent = addStudent;
}

void Node::setNext(Node* newNode){
  next = newNode;
}

Node* Node::getNext(){
  return next;
}
