#include <iostream>
#include <cstdio>
using namespace std;

int charToNum(char c);

int main()
{
  char input[20];
  int result = 0;
  scanf("%s", input);

  for (int i = 0; i < (sizeof(input) / sizeof(input[0])); i++)
  {
    result += charToNum(input[i]);
  }
  cout << result << endl;
  return 0;
}

int charToNum(char c)
{
  if (c == 'I')
  {
    return 1;
  }
  if (c == 'V')
  {
    return 5;
  }
  if (c == 'X')
  {
    return 10;
  }
  if (c == 'L')
  {
    return 50;
  }
  if (c == 'C')
  {
    return 100;
  }
  if (c == 'D')
  {
    return 500;
  }
  if (c == 'M')
  {
    return 1000;
  }
  return 0;
}