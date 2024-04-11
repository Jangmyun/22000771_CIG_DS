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

void addCafe(Cafe &c);
void displayMenus(Cafe &c);
void addMenu(Menu &m);

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

void addCafe(Cafe &c) // Cafe 추가하는 함수
{
  getline(cin, c.name);       // 카페이름 입력받기
  cin >> c.msize;             // 메뉴 사이즈 입력받기
  c.list = new Menu[c.msize]; // 카페 메뉴리스트에 메모리 사이즈만큼 할당
}

void displayMenus(Cafe &c) // 메뉴 출력함수
{
  cout << "===== " << c.name << " =====" << endl;
  for (int i = 0; i < c.msize; i++)
  {
    cout << c.list[i].name << " " << c.list[i].price << endl;
  }
  cout << "=================" << endl;
}

void addMenu(Menu &m) // 메뉴 추가 함수
{
  cin >> m.name >> m.price; // 메뉴이름과 가격 입력받기
  return;
}