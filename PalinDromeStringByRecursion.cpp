#include <iostream>
#include <string.h>
using namespace std;
bool isPal (string);
bool isPalRec (string, int, int);

bool
isPal (string str)
{
  int n = str.length();
  if (n == 0)
    return true;
  else
    return isPalRec (str, 0, n - 1);
}

bool
isPalRec (string str, int first, int last)
{
  if (first == last)
    return true;
  if (str[first] != str[last])
    return false;
  if (first >= last)
    return true;
  return isPalRec (str, first + 1, last - 1);
}


int
main ()
{
  string str;
  cout<<"Enter string to check : ";
  cin>>str;
  if (isPal (str))
    cout << "\nString is Palindrome" << endl;
  else
    cout << "\nString isn't Palindrome" << endl;
  return 0;
}
