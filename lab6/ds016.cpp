#include <iostream>
#include <string>
using namespace std;
#define STRING_NUM 3 // 문자열 개수를 define으로 지정

string findPrefix(string *strP);

int main()
{

  // 포인터 선언
  string *strP = new string[STRING_NUM];

  // 문자열 개수만큼 입력받기
  for (int i = 0; i < STRING_NUM; i++)
  {
    cin >> strP[i];
  }

  cout << findPrefix(strP) << endl;

  return 0;
}

string findPrefix(string *strP)
{
  string output;
  int strLen = strP[0].length();

  for (int i = 0; i < STRING_NUM; i++) // 가장 짧은 문자열을 찾기
  {
    if (strP[i].length() < strLen)
    {
      strLen = strP[i].length();
    }
  }

  for (int i = 0; i < strLen; i++) // 0부터 가장 짧은 문자열 길이만큼 반복
  {
    char prefixChar = strP[0][i];
    bool allIncluded = true;
    for (int j = 0; j < STRING_NUM; j++)
    {
      if (prefixChar != strP[j][i]) // 문자 일치하지 않으면 false
      {
        allIncluded = false;
      }
    }
    if (allIncluded) // 해당 인덱스 모든 문자가 일치하면 output에 문자 넣기
    {
      output += prefixChar;
    }
  }
  if (output.empty()) // output이 텅 비었으면 물음표 출력
  {
    return "?";
  }
  return output;
}