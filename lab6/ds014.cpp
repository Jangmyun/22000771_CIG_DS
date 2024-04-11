#include <iostream>
#include <string>
using namespace std;

#define TAB "\t"

string ltrim(string str)
{
  string output;
  int i = 0;
  while (str[i] == ' ')
  {
    i++;
  }
  for (int j = i; j < str.length(); j++)
  {
    output += str[j];
  }
  return output;
}

string rtrim(string str)
{
  string output;
  int i = str.length();
  while (str[i] == ' ')
  {
    i--;
  }
  for (int j = 0; j < i; j++)
  {
    output += str[j];
  }
  return output;
}

string removeTab(string str)
{
  string output;
  int firstIndex = -1;
  int lastIndex = -1;

  firstIndex = str.find_first_not_of(TAB);

  if (firstIndex != -1)
  {
    for (int i = firstIndex; i < str.length(); i++)
    {
      output += str[i];
    }
  }
  else
  {
    output = str;
  }
  string output2 = output;
  lastIndex = output.find_last_not_of(TAB);
  if (lastIndex != -1)
  {
    for (int i = 0; i < lastIndex; i++)
    {
      output2 += output[i];
    }
  }
  return output2;
}

string removeAllSpaces(string str)
{
  string output = str;
  while (output[0] == ' ' || output[0] == '\t')
  {
    if (output[0] == ' ')
    {
      output = ltrim(output);
    }
    if (output[0] == '\t')
    {
      output = removeTab(output);
    }
  }
  while (output[output.length() - 1] == ' ' || output[output.length() - 1] == '\t')
  {
    if (output[output.length() - 1] == ' ')
    {
      output = rtrim(output);
    }
    if (output[output.length() - 1] == '\t')
    {
      output = removeTab(output);
    }
  }
  return output;
}

int main()
{
  string input, output;
  getline(cin, input, '\n');

  output = removeAllSpaces(input);
  cout << output << endl;
  return 0;
}