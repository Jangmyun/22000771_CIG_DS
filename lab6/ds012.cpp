#include <iostream>
using namespace std;

struct Product
{
  string name;
  int price;
  string company;
};

void addProducts(Product *products);
string toUpperCase(string str);
void isEqualProduct(Product *products);

int main()
{
  Product *products = new Product[2]; // 포인터 변수 선언 후 메모리 할당
  addProducts(products);              //
  isEqualProduct(products);

  delete[] products;
  return 0;
}

void addProducts(Product *products) // Product 정보 입력받는 함수
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

void isEqualProduct(Product *products) // 같은 Product인지 확인하는 함수
{
  string pName1, pName2;
  pName1 = toUpperCase(products[0].name); // 대소문자 구분하지 않으므로 두 Product 대문자로 일괄 변경
  pName2 = toUpperCase(products[1].name);

  if (pName1 == pName2 && products[0].price == products[1].price) // 상품이름과 가격 같으면 같다는 결과 출력
  {
    cout << products[0].name << " is equal" << endl;
  }
  else
  {
    cout << products[0].name << " and " << products[1].name << " is not equal." << endl;
  }
}