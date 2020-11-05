#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class student {
 public:
  student(float Gpa, int Id, char* NameFirst, char* NameLast);
  void Print();
  int getId();
  float getGpa();
 private:
  float gpa;
  int id;
  char* nameFirst;
  char* nameLast;
};
#endif
