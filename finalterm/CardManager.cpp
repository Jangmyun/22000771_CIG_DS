#include "cardManager.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

extern map<string, Card*> allclasses;
extern map<string, double> gradescore;

CardManager::~CardManager() {
  vector<Card*>::iterator iter;
  for (iter = myclasses.begin(); iter != myclasses.end(); ++iter) {
    delete (*iter);
  }
}

void CardManager::printAll() {
  int i;
  double total = 0;
  int credit = 0;
  double GPA = 0.0;
  double gs;  // grade score

  for (i = 0; i < myclasses.size(); i++) {
    gs = gradescore.find(myclasses[i]->getCredit());
    cout << i + 1 << " | " << myclasses[i]->toString() << endl;
  }
}

void CardManager::addCard() {
  string code, grade;
  cout << ">> Enter class code > ";
  cin >> code;

  for (vector<Card*>::size_type i = 0; i < myclasses.size(); i++) {
    if (myclasses[i]->getCode() == code) {
      cout << "The Card of " << code << " already exists." << endl;
      return;
    }
  }

  if (allclasses.count(code) > 0) {
    cout << allclasses[code]->toStringShort() << endl;
    cout << ">> Enter grade > ";
    cin >> grade;

    if (gradescore.find(grade) == gradescore.end()) {
      cout << "Wrong grade!" << endl;
      return;
    }

    Card* new_card = new Card(allclasses[code], grade);
    myclasses.push_back(new_card);
    count++;
    total_credit += new_card->getCredit();
  } else {
    cout << "No such class." << endl;
  }
}

void CardManager::editCard() {
  int no;
  string new_grade;
  cout << ">> Enter a Card number > ";
  cin >> no;
  cout << myclasses[no - 1]->toString() << endl;
  cout << ">> Enter new grade > ";
  cin >> new_grade;
  myclasses[no - 1]->setGrade(new_grade);
  cout << "Grade changed." << endl;
}

void CardManager::sortByCode() {
  sort(myclasses.begin(), myclasses.end(), Card::cmpCode);
}

void CardManager::loadCards(string filename) {
  string line, code, grade;
  int count = 0;
  ifstream file(filename);
  while (!file.eof()) {
    if (file.eof()) break;
    file >> code >> grade;
    Card* new_card = new Card(allclasses[code], grade);
    myclasses.push_back(new_card);
    count++;
    total_credit += new_card->getCredit();
  }
  file.close();
  cout << count << " classes are loaded.\n";
}

void CardManager::findCards(string name) {
  int found = 0;
  cout << "Searching keyword: " << name << endl;
  for (int i = 0; i < myclasses.size(); i++) {
    if (myclasses[i]->getName().find(name) != string::npos) {
      found++;
      cout << i + 1 << " | " << myclasses[i]->toString() << endl;
    }
  }
  cout << count << " classes found.\n";
}