#include <iostream>
using namespace std;

struct Product
{
  string name;
  int price;
  string company;
};

void addProducts(Product *products)
{
  for (int i = 0; i < 2; i++)
  {
    cin >> products[i].name >> products[i].price >> products[i].company;
  }
}
string toUpperCase(string str) // 문자열을 대문자로 변환
{
  string output;
  for (int i = 0; i < str.size(); i++)
  {
    output += toupper(str[i]);
  }
  return output;
}

void isEqualProduct(Product *products)
{
  string pName1, pName2;
  pName1 = toUpperCase(products[0].name);
  pName2 = toUpperCase(products[1].name);

  if (pName1 == pName2 && products[0].price == products[1].price)
  {
    cout << products[0].name << " is equal" << endl;
  }
  else
  {
    cout << products[0].name << " and " << products[1].name << " is not equal." << endl;
  }
}

int main()
{
  Product *products = new Product[2];
  addProducts(products);
  isEqualProduct(products);

  delete[] products;
  return 0;
}