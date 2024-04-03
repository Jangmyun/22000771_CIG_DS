#include <iostream>
using namespace std;

string toUpperCase(string str);

int main()
{
  string input;
  int alphaNum[27] = {0};

  getline(cin, input);
  input = toUpperCase(input);
  cout << input[3] << endl;

  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] == ' ')
    {
      alphaNum[0] += 1;
    }
    else
    {
      int index = (int)input[i] - 64;
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

string toUpperCase(string str)
{
  string output;
  for (int i = 0; i < str.size(); i++)
  {
    output += toupper(str[i]);
  }
  return output;
}