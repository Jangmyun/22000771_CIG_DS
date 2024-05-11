#include "./mystack_char.h"

MyLinkedStack::MyLinkedStack() { stacktop = NULL; }

void MyLinkedStack::initialize() {
  Node* i = stacktop;  // stacktop 부터 i가 NULL이 아닐때까지 반복
  Node* tmp;
  while (i != NULL) {
    tmp = i;      // tmp에 i주소 저장
    i = i->link;  // i 를 i->link로 변경 후 tmp 메모리 해제
    delete tmp;
  }
  stacktop = NULL;  // 모든 node 메모리 해제 후 stacktop == NULL
}

bool MyLinkedStack::isEmpty() const {
  if (stacktop == NULL) {
    return true;
  }
  return false;
}

void MyLinkedStack::push(const char& c) {
  Node* newNode = new Node(c);
  if (isEmpty()) {
    stacktop = newNode;
    return;
  }
  newNode->link = stacktop;
  stacktop = newNode;
}

void MyLinkedStack::pop() {
  Node* t;
  t = stacktop;
  stacktop = stacktop->link;
  delete t;
}

char MyLinkedStack::peek() const { return stacktop->data; }

int MyLinkedStack::getNodeCnt() const {
  Node* i;
  int count = 0;
  for (i = stacktop; i != NULL; i = i->link) {
    count++;
  }
  return count;
}

MyLinkedStack::~MyLinkedStack() { initialize(); }

void MyLinkedStack::printAll() {
  Node* i;
  for (i = stacktop; i != NULL; i = i->link) {
    if (i->link == NULL) {
      cout << i->data << " ";
    } else {
      cout << i->data << " -> ";
    }
  }
  cout << endl;
}
