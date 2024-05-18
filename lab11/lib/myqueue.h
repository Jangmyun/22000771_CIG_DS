#ifndef MyTemplate_H
#define MyTemplate_H

#include <iostream>
using namespace std;

class Student {
 private:
  double gpa;
  string name;

 public:
  Student() {
    gpa = 0;
    name = "none";
  }
  Student(double g, string n) {
    gpa = g;
    name = n;
  }
  double getGpa() const { return gpa; }
  string getName() const { return name; }
};

template <typename T>
class MyCircularQueue {
 private:
  int maxsize;
  int front;
  int rear;
  T* list;

 public:
  void initialize();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(const T& elem);
  void dequeue();
  T Front();
  T Rear();
  MyCircularQueue(int size = 10);
  ~MyCircularQueue();
  void print() const;
  int size() const;
  void printDetail() const;
};

#endif