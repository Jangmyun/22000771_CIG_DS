#include <iostream>
#include <cstdio>
using namespace std;

struct subject
{
  string subjectName;
  int credit;
  int score;
  double mark;
  string grade;
};

subject *createSubject(string str, int credit, int score);
string checkGrade(int score);
double checkMark(int score);
string underbarToBlank(string str, int credit);

int main()
{
  subject *subArr[3];
  int totalCredits = 0;
  double avg;
  for (int i = 0; i < 3; i++)
  {
    string subName;
    int credit, score;
    scanf("%s %d %d", subName, &credit, &score);
    totalCredits += credit;
    subArr[i] = createSubject(subName, credit, score);

    cout << std::left << std::setw(25) << subArr[i]->subjectName << endl;
  }
}

subject *createSubject(subject *t, string str, int credit, int score)
{
  subject tmp;

  tmp.subjectName = str;
  tmp.credit = credit;
  tmp.score = score;
  tmp.grade = checkGrade(tmp.score);

  *t = tmp;
  return t;
}

string underbarToBlank(string str, int credit)
{
  string output;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '_')
    {
      output += ' ';
    }
    else
    {
      output += str[i];
    }
  }
  output += '(' + credit + ')';
  return output;
}

double checkMark(int score)
{
  if (95 <= score && score <= 100)
  {
    return 4.5;
  }
  else if (90 <= score && score < 95)
  {
    return 4.0;
  }
  else if (85 <= score && score < 90)
  {
    return 3.5;
  }
  else if (80 <= score && score < 85)
  {
    return 3.0;
  }
  else if (75 <= score && score < 80)
  {
    return 2.5;
  }
  else if (70 <= score && score < 75)
  {
    return 2.0;
  }
  else if (65 <= score && score < 70)
  {
    return 1.5;
  }
  else if (60 <= score && score < 65)
  {
    return 1.0;
  }
  else
  {
    return 0;
  }
}

string checkGrade(int score)
{
  if (95 <= score && score <= 100)
  {
    return "A+";
  }
  else if (90 <= score && score < 95)
  {
    return "A0";
  }
  else if (85 <= score && score < 90)
  {
    return "B+";
  }
  else if (80 <= score && score < 85)
  {
    return "B0";
  }
  else if (75 <= score && score < 80)
  {
    return "C+";
  }
  else if (70 <= score && score < 75)
  {
    return "C0";
  }
  else if (65 <= score && score < 70)
  {
    return "D+";
  }
  else if (60 <= score && score < 65)
  {
    return "D0";
  }
  else
  {
    return "F";
  }
}