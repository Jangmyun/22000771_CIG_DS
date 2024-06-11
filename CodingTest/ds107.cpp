#include <iostream>
#include <vector>
using namespace std;

bool compare(int x, int y) { return x > y ? true : false; }

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> vec;
  int score;

  for (int i = 0; i < a + b; i++) {
    cin >> score;
    vec.push_back(score);
  }
  sort(vec.begin(), vec.end(), compare);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  return 0;
}