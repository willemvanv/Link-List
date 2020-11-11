#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

//Function declarations
void add();
void print();
void delet();
void average();

//Head node
Node* head;

int aba = 0;

int main() {
  //Variables
  bool running = true;
  //Instrctions
  cout << "Commands: add, print, delete, average, quit" << endl;
  while (running == true) {
    if (aba == 0) {
      cout << endl;
      cout << "Enter a Command" << endl << endl;
    }
    char* input;
    cin.getline(input, 99);
    aba = 0;
    if (input[0] == 'a' && input[1] == 'd' && input[2] == 'd') {
      add();
      aba = 1;
    }
    if (input[0] == 'p' && input[1] == 'r' && input[2] == 'i' && input[3] == 'n' &&
	input[4] == 't') {
      print();
    }
    if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't') {
      running = false;
    }
    if (input[0] == 'd' && input[1] == 'e' && input[2] == 'l' && input[3] == 'e' &&
	input[4] == 't' && input[5] == 'e') {
      delet();
      aba = 1;
    }
    if (input[0] == 'a' && input[1] == 'v' && input[2] == 'e' && input[3] == 'r' &&
	input[4] == 'a' && input[5] == 'g' && input[6] == 'e') {
      average();
    }
  }
}
//Add a new student
void add() {
  float Gpa1;
  int Id1;
  char* NameFirst1;
  char* NameLast1;
  NameFirst1 = new char[99];
  NameLast1 = new char[99];
  cout << "Enter gpa" << endl;
  cin >> Gpa1;
  cout << "Enter id" << endl;
  cin >> Id1;
  cout << "Enter first name" << endl;
  cin >> NameFirst1;
  cout << "Enter last name" << endl;
  cin >> NameLast1;
  student* b = new student(Gpa1, Id1, NameFirst1, NameLast1);
  Node* current = head;
  Node* temp;
  if (current == NULL) {
    head = new Node(b);
  }
  else {
    if (current->getNext() != NULL) {
      if (current->getStudent()->getId() > Id1) {
	temp = head;
	head = new Node(b);
	head->setNext(temp);
      }
      else {
	while (current->getNext()->getStudent()->getId() < Id1 && current->getNext() != NULL) {
	  current = current->getNext();
	}
	if (current->getNext() != NULL) {
	  temp = current->getNext();
	  current->setNext(new Node(b));
	  current->getNext()->setNext(temp);
	}
	else {
	  current->setNext(new Node(b));
	}
      }
    }
    else {
      if (current->getStudent()->getId() > Id1) {
	temp = head;
	head = new Node(b);
	head->setNext(temp);
      }
      else {
	head->setNext(new Node(b));
      }
    }
  }
}
//Print all students
void print() {
  Node* current = head;
  student* b;
  if (current != NULL) {
    b = current->getStudent();
    b->Print();
    if (current->getNext() != NULL) {
      current = current->getNext();
      while (current->getNext() != NULL) {
	b = current->getStudent();
	b->Print();
	current = current->getNext();
      }
      b = current->getStudent();
      b->Print();
    }
  }
}
//Delete a student
void delet() {
  Node* temp;
  Node* current = head;
  int ID;
  cout << "Enter id" << endl;
  cin >> ID;
  if (head->getStudent()->getId() == ID) {
    temp = head->getNext();
    head->~Node();
    head = temp;
  }
  else {
    while (current->getNext() != NULL) {
      if (current->getNext()->getStudent()->getId() == ID) {
	temp = current->getNext()->getNext();
	current->getNext()->~Node();
	current->setNext(temp);
      }
      current = current->getNext();
    }
  }
}
//Average Gpas
void average() {
  float GPA;
  float no;
  Node* current = head;
  if (head != NULL) {
    while (current->getNext() != NULL) {
      GPA = GPA + current->getStudent()->getGpa();
      current = current->getNext();
      no++;
    }
    no++;
    GPA = GPA + current->getStudent()->getGpa();
  }
  GPA = GPA/no;
  cout << "Average GPA: ";
  printf("%.2f", GPA);
  cout << endl;
}
