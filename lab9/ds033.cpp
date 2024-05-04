#include <iostream>

using namespace std;

struct Coupon {  // coupon 정보 담은 구조체
  int number;
  string giftName;
};

class CouponStack {
 private:
  int maxsize;
  int top;
  Coupon *list;

 public:
  void initialize() { top = 0; }
  bool isEmpty() { return top == 0 ? true : false; }
  bool isFull() { return top == maxsize ? true : false; }
  void push(const Coupon &c) {
    if (isFull()) return;
    list[top] = c;
    top++;
  }
  Coupon *pop() {
    if (isEmpty()) return nullptr;
    return &list[--top];
  }
  CouponStack(int size = 10) {
    top = 0;
    maxsize = size;
    list = new Coupon[size];
  }

  void print() {      // 쿠폰내용 넣은 순서대로 출력
    if (isEmpty()) {  // 스택 비었으면 바로 종료
      return;
    }
    // 0부터 top-1 까지 반복해서 출력
    for (int i = 0 - 1; i < top; i++) {
      cout << list[i].number << "등 - " << list[i].giftName << endl;
    }
  }

  void rprint() {         // 쿠폰 넣은 역순으로 출력
    while (!isEmpty()) {  // 스택 빌때까지 실행
      Coupon *tmp;        // tmp에 pop한 내용 담아서 출력
      tmp = pop();
      cout << tmp->number << "등 - " << tmp->giftName << endl;
    }
  }
  ~CouponStack() { delete[] list; }
};

void printCoupon(Coupon c) {
  cout << c.number << "등 - " << c.giftName << endl;
}

void manageCoupons() {
  int size;
  cin >> size;
  CouponStack cs(size);  // 사이즈 입력받아서 스택생성
  string in;

  while (in != "q") {  // q 입력받을때까지 실행
    cin >> in;
    if (in == "+") {  // + 면 뒤에 number와 name 입력받아서 스택에 push
      Coupon c;
      cin >> c.number;
      getline(cin >> ws, c.giftName);
      cs.push(c);
    } else if (in == "-") {  // - 면
      if (cs.isEmpty()) {    // 스택 비었으면 종료
        return;
      }
      Coupon *c = cs.pop();  // 안비었으면 pop해서 쿠폰내용 출력
      printCoupon(*c);
    } else if (in == "print") {  // print입력받으면 스택 배열 내용 출력
      cs.print();
    } else if (in == "rprint") {  // rprint입력받으면 스택 비워가면서 출력
      cs.rprint();
    }
  }
}

int main() {
  manageCoupons();
  return 0;
}