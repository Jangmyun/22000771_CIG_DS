#include <iostream>
#include <vector>
using namespace std;

// compare 방식 정의
bool compareString(string a, string b) {
  // 길이 같으면 string자체 대소 비교로 사전순서로 정렬
  if (a.length() == b.length()) {
    return a > b ? true : false;
  } else {  // 길이 다르면 길이 짧은 순 정렬
    return a.length() > b.length() ? false : true;
  }
}

int main() {
  int N;
  cin >> N;

  vector<string> vec;
  string input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    // vector의 처음부터 끝까지 반복해서 입력받은 input값이 중복되는지 찾고,
    // 중복 안된다면 넣기
    if (find(vec.begin(), vec.end(), input) == vec.end()) {
      vec.push_back(input);
    }
  }
  // 위에서 정의한 compare 방식으로 정의
  sort(vec.begin(), vec.end(), compareString);
  // 출력
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
  return 0;
}