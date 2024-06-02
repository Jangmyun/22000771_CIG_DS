#include <iostream>
using namespace std;

class node {
 public:
  int data;
  string name;
  struct node* link;

  node() {
    link = NULL;
    data = 0;
    name = "";
  }
  node(int data) {
    this->link = NULL;
    this->data = data;
  }
  node(int data, string name) {
    this->link = NULL;
    this->data = data;
    this->name = name;
  }
};

class linkedList {
  node* start;
  node* last;

 public:
  linkedList() {
    start = NULL;
    last = NULL;
  }

  void clearLinked() {
    node* tmp;
    while (start != NULL) {
      tmp = start;
      start = start->link;
      delete tmp;
    }
    start = NULL;
    last = NULL;
  }
  ~linkedList() { clearLinked(); }

  node* createNode(int x) {
    node* newNode = new node;
    newNode->data = x;
    newNode->name = "";
    newNode->link = NULL;
    return newNode;
  }

  node* createNode(int x, string n) {
    node* newNode = new node;
    newNode->data = x;
    newNode->name = n;
    newNode->link = NULL;
    return newNode;
  }

  void addLast(int y) {
    node* newNode = createNode(y);
    if (start == NULL) {
      start = newNode;
      last = newNode;
    } else {
      last->link = newNode;
      last = newNode;
    }
  }

  void addLast(int y, string n) {
    node* newNode = createNode(y, n);
    if (start == NULL) {
      start = newNode;
      last = newNode;
    } else {
      last->link = newNode;
      last = newNode;
    }
  }

  void printLinked() {
    node* tmp = start;

    while (tmp->link != NULL) {
      cout << tmp->data << " " << tmp->name << endl;
      tmp = tmp->link;
    }
    cout << tmp->data << " " << tmp->name << endl;
  }

  void printLinkedName() {
    node* tmp = start;
    int i = 1;
    while (tmp->link != NULL) {
      cout << i << "> " << tmp->data << " " << tmp->name << endl;
      tmp = tmp->link;
      i++;
    }
    cout << i << "> " << tmp->data << " " << tmp->name << endl;
  }

  void init(int size) {
    int number;
    clearLinked();
    printf("Enter numbers...");
    for (int i = 0; i < size; i++) {
      cin >> number;
      addLast(number);
    }
  }

  void initName(int size) {
    int number;
    string name;
    clearLinked();
    for (int i = 0; i < size; i++) {
      cin >> number >> name;
      addLast(number, name);
    }
  }

  void swapNode(node* x, node* y) {
    int tmp = x->data;
    string tmp2 = x->name;
    x->name = y->name;
    x->data = y->data;
    y->name = tmp2;
    y->data = tmp;
  }

  void selectionLinked() {
    for (node* i = start; i->link != NULL; i = i->link) {
      node* minNode = i;
      for (node* j = i->link; j != NULL; j = j->link) {
        if (minNode->data > j->data) {
          minNode = j;
        }
      }
      if (minNode != i) {
        swapNode(i, minNode);
      }
    }
  }

  int getListLength() {
    node* p = start;
    int length = 0;
    while (p != NULL) {
      length++;
      p = p->link;
    }
    return length;
  }

  void bubbleLinked() {
    int length = getListLength();

    for (int i = 0; i < length - 1; i++) {
      node* current = start;
      node* prev = NULL;
      node* next = start->link;

      for (int j = 0; j < length - i - 1; j++) {
        if (current->data < next->data) {
          if (prev) {
            prev->link = next;
          } else {
            start = next;
          }
          current->link = next->link;
          next->link = current;

          prev = next;
          next = current->link;
        } else {
          prev = current;
          current = next;
          next = next->link;
        }
      }
    }
  }
};