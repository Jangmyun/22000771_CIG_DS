#include <iostream>
using namespace std;

struct Menu
{
  string name;
  int price;
};

struct Cafe
{
  string name;
  int msize;
  Menu *list;
};

void addCafe(Cafe &c)
{
  getline(cin, c.name);
  cin >> c.msize;
  c.list = new Menu[c.msize];
}

void displayMenus(Cafe &c)
{
  cout << "===== " << c.name << " =====" << endl;
  for (int i = 0; i < c.msize; i++)
  {
    cout << c.list[i].name << " " << c.list[i].price << endl;
  }
  cout << "=============" << endl;
}

void addMenu(Menu &m)
{
  cin >> m.name >> m.price;
  return;
}

int main()
{
  Cafe c;
  addCafe(c);

  for (int i = 0; i < c.msize; i++)
  {
    addMenu(c.list[i]);
  }

  displayMenus(c);

  delete[] c.list;
  return 0;
}