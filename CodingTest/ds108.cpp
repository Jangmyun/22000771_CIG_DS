#include <iostream>
#include <vector>
using namespace std;
int tmp;

bool isEqual(const pair<int, int>& element) { return element.first == ::tmp; }

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> pairVector;

  for (int i = 0; i < n; i++) {
    cin >> ::tmp;
    auto it = find_if(pairVector.begin(), pairVector.end(), isEqual);
    if (it == pairVector.end()) {
      pair<int, int> pairTemp(tmp, 1);
      pairVector.push_back(pairTemp);
    } else {
      it->second++;
    }
  }

  int maxNum = pairVector[0].second;
  int maxVal = pairVector[0].first;

  for (int i = 0; i < pairVector.size(); i++) {
    if (pairVector[i].second > maxNum) {
      maxNum = pairVector[i].second;
      maxVal = pairVector[i].first;
    }
  }
  cout << maxVal << endl;
  return 0;
}