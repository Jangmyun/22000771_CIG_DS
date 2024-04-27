#include <iostream>
using namespace std;

class Product {  // 상품 한개 정보 다루는 클래스
 private:
  string pName;
  string cName;
  string weight;
  int price;
  int discount;

 public:
  void setProduct() {  // 상품정보 입력 함수
    getline(cin >> ws, this->pName);
    cin >> this->price >> this->discount >> this->weight >> this->cName;
  }
  // 상품 할인률 계산한 실제 가격 리턴하는 함수
  int getActualPrice() { return price - (int)(price / 100.0 * discount); }
  void printProduct() {  // 상품정보 출력하는 함수
    cout << getActualPrice() << " (-" << discount << "%) " << pName << " "
         << weight << " " << cName << endl;
  }
};

class Shop {  // shop 클래스
 private:
  Product *list;  // Product 리스트를 동적 배열로 선언
  int pSize;      // Product 리스트의 사이즈를 저장하는 변수

 public:
  Shop() {  // shop 인스턴스 생성 시 pSize를 0으로 설정하고 빈 리스트 생성
    pSize = 0;
    list = new Product[1];
  }
  void manageProduct() {  // 메뉴로 Product 관리하는 함수
    int select = 0;
    while (select != 3) {
      cout << "1.Add  2.List  3.Quit > ";
      cin >> select;

      if (select == 1) {
        addProducts();
      } else if (select == 2) {
        printProducts();
      } else {
        break;
      }
    }
  }

  void addProducts() {
    Product *newList;
    Product *tmp;
    // 새로운 Product 리스트를 만들고 pSize보다 1크게 메모리 할당
    newList = new Product[pSize + 1];

    for (int i = 0; i < pSize; i++) {  // 기존 list복사
      newList[i] = list[i];
    }
    Product
        newProduct;  // 새로운 Product 생성하고 입력받아서 마지막 인덱스로 넣기
    newProduct.setProduct();
    newList[pSize] = newProduct;
    pSize++;

    tmp = list;
    list = newList;
    delete[] tmp;  // newList의 주소값을 list로 넘기고 기존 list는 메모리 해제
  }

  void printProducts() {
    for (int i = 0; i < pSize; i++) {
      list[i].printProduct();
    }
  }

  ~Shop() { delete[] list; }
};

int main() {
  Shop a;
  a.manageProduct();
  return 0;
}