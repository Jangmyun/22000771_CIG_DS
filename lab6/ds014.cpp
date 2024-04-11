#include <iostream>
#include <string>
using namespace std;

string ltrim(string &str);
string rtrim(string &str);
string removeLTab(string &str);
string removeRTab(string &str);
string removeAllSpaces(string &str);

int main()
{
  string input;

  getline(cin, input);

  removeAllSpaces(input);

  cout << input << endl;
  return 0;
}

string ltrim(string &str) // reference variable 사용
{
  string tmp;
  int index;
  index = str.find_first_not_of(' ');        // index = 가장 처음으로 나오는 공백 집합의 인덱스
  for (int i = index; i < str.length(); i++) // 받아온 인덱스부터 문자열 끝까지 반복
  {
    tmp += str[i]; // 공백을 제외한 다른 문자열 옮겨담기
  }
  str = tmp;

  return tmp;
}
string rtrim(string &str)
{
  string tmp;
  int index;
  index = str.find_last_not_of(" ");
  for (int i = 0; i < index; i++)
  {
    tmp += str[i];
  }
  str = tmp;
  return tmp;
}

string removeLTab(string &str)
{
  string tmp;
  int index;

  index = str.find_first_not_of('\t'); // 인덱스 = 가장 처음으로 나오는 탭 집합 인덱스

  for (int i = index; i < str.length(); i++)
  {
    tmp += str[i];
  }
  str = tmp;

  return tmp;
}

string removeRTab(string &str)
{
  string tmp;
  int index;

  index = str.find_last_not_of('\t');

  for (int i = 0; i < index + 1; i++)
  {
    tmp += str[i];
  }
  str = tmp;

  return tmp;
}

string removeAllSpaces(string &str)
{
  string tmp;
  // 문자열의 가장 첫번째 인덱스의 값이나 마지막 인덱스의 값 문자가 공백이 아닐때까지 반복
  while (!(str[0] != ' ' && str[str.length() - 1] != ' ' && str[0] != '\t' && str[str.length() - 1] != '\t'))
  {
    if (str[0] == ' ')
    {
      ltrim(str);
    }
    if (str[str.length() - 1] == ' ')
    {
      rtrim(str);
    }
    if (str[0] == '\t')
    {
      removeLTab(str);
    }
    if (str[str.length() - 1] == '\t')
    {
      removeRTab(str);
    }
  }
  return tmp;
}