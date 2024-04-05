#include <iostream>
using namespace std;

string toUpperCase(string str);

int main()
{
  string input;
  int alphaNum[27] = {0}; // 공백 + 알파벳  = 27개의 int 배열을 0으로 초기화

  getline(cin, input);        // 한줄 입력받기
  input = toUpperCase(input); // 대문자로 바꾸기
  cout << input[3] << endl;

  for (int i = 0; i < input.size(); i++) // 입력받은 문자열의 사이즈만큼 반복
  {
    if (input[i] == ' ') // 공백일 경우 0번째 원소 1추가
    {
      alphaNum[0] += 1;
    }
    else //
    {
      int index = (int)input[i] - 64; // 알파벳(대문자) 의 경우 A가 아스키 65부터 시작 & alphaNum 배열 1부터 시작  ==> char을 int로 형변환하고 64를 빼면 배열의 인덱스가 됨
      alphaNum[index] += 1;
    }
  }

  for (int i = 0; i < sizeof(alphaNum) / sizeof(int); i++)
  {
    if (alphaNum[i] != 0)
    {
      if (i == 0)
      {
        cout << "blanks"
             << " : " << alphaNum[i] << endl;
      }
      else
      {
        char alpha = (char)(i + 64);
        cout << alpha << " : " << alphaNum[i] << endl;
      }
    }
  }

  return 0;
}

string toUpperCase(string str) // 문자열을 대문자로 변환
{
  string output;
  for (int i = 0; i < str.size(); i++)
  {
    output += toupper(str[i]);
  }
  return output;
}