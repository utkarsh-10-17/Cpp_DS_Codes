#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  string str;
  cin >> str;

  char firstChar = str.at(0);
  char lastChar = str.at(-1);

  int a;
  a = (str.size() - 2);

  cout << firstChar + a + lastChar;

  return 0;
}