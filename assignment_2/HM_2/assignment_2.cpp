/**
 * a program illustrating how to use reference and plain variables between
 * different functions
 * @author Bill Jin
 * @version 23 August 2020
 */

#include <iostream>
using namespace std;

/**
 * This is a simple function that will change the value of parameter
 * and call another function to pass them by reference, then print them out
 * @param a an integer 10
 * @param b an reference integer variable passed from main function
 */
int foo(int a, int& b);

/**
 * This is a function that will change the references variable in parameter
 * and print them out
 * @param x an reference integer variable passed from foo function
 * @param y an reference integer variable passed from foo function
 */
void bar(int& x, int& y);


int main()
{
  int i = 10;
  int& j = i;
  int k = foo(10,i);

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;

  return 0;
}

int foo(int a, int& b)
{
  a = a * 2;
  b--;
  int c = 20;
  bar(b, c);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

  //Return the sum of those three variables
  return a + b + c;
}

void bar(int& x, int& y)
{
  x = x + 2;
  y--;

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
}



