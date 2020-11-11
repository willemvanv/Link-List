#include <iostream>
#include <cstring>
#include "student.h"

student::student(float Gpa, int Id, char* NameFirst, char* NameLast) {
  gpa = Gpa;
  id = Id;
  nameFirst = new char[99];
  nameLast = new char[99];
  strcpy(nameFirst, NameFirst);
  strcpy(nameLast, NameLast);
}
void student::Print() {
  cout << endl << nameFirst << " " << nameLast << ", " << id << ", " << gpa << endl;
}
int student::getId() {
  return id;
}
float student::getGpa() {
  return gpa;
}
