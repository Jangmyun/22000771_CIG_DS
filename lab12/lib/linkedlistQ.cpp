#include "./linkedlistQ.h"

LinkedListQ::LinkedListQ() {
  this->front = NULL;
  this->rear = NULL;
}

void LinkedListQ::initialize() {
  Node* tmp = front;
  for (Node* i = front->link; i != NULL; i = i->link) {
    delete tmp;
    tmp = i;
  }
}

LinkedListQ::~LinkedListQ() { initialize(); }

bool LinkedListQ::isEmpty() const {
  if (front == NULL) {
    return true;
  }
  return false;
}

int LinkedListQ::Front() const { return !isEmpty() ? front->data : 0; }
int LinkedListQ::Rear() const { return !isEmpty() ? rear->data : 0; }

void LinkedListQ::enqueue(const int& data) {
  Node* n = new Node(data);
  if (isEmpty()) {
    front = n;
    rear = n;
  }
}

void LinkedListQ::dequeue() {
  if (isEmpty()) {
    return;
  }
  Node* tmp;
  if (front == rear) {
    delete front;
    front = rear = NULL;
    return;
  }
  tmp = front;
  front = front->link;
  delete tmp;
}

void LinkedListQ::printAll() const {
  if (isEmpty()) {
    return;
  }
  for (Node* i = front; i != NULL; i = i->link) {
    cout << i->data << " ";
    if (!(i->link == NULL)) {
      cout << "-> ";
    }
  }
}
