#include <iostream>
using namespace std;

int main()
{
  int N;
  int max = 0;
  int sum = 0;

  cin >> N;

  int *arr = new int[N];

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
    sum += arr[i];
    if (max < arr[i])
    {
      max = arr[i];
    }
  }

  cout << sum << " " << max << endl;

  delete[] arr;
  return 0;
}
