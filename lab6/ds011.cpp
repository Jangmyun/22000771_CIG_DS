#include <iostream>
using namespace std;

int main()
{
  int N;
  int max = 0;
  int sum = 0;

  cin >> N;

  int *arr = new int[N]; // 포인터 변수 선언 후 입력받은 N만큼 메모리 할당

  for (int i = 0; i < N; i++) // N입력 받은 만큼 숫자 입력받고 sum에 입력받은 숫자 더하기/ 최대값 저장
  {
    cin >> arr[i];
    sum += arr[i];
    if (max < arr[i])
    {
      max = arr[i];
    }
  }

  cout << sum << " " << max << endl; // 결과 출력

  delete[] arr;
  return 0;
}
