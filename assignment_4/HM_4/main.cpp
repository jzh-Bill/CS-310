/**
  * This program will build a vector and make it become a heap.
  * @author Bill Jin
  * @version 9 September 2020
  */
#include <iostream>
#include <algorithm>
#include <vector>
#include "heap.h"

using namespace std;

int main()
{
  Heap h;

  vector<unsigned> values;
  for (unsigned i = 0; i < 100; i++)
  {
    values.push_back(i);
  }

  random_shuffle(values.begin(), values.end());

  for (auto value : values)
  {
    cout << "pushing " << value << endl;
    h.push(value);
  }

  h.dump();

  while (!h.empty())
  {
    unsigned value = h.pop();
    cout << "popped: " << value << endl;
  }

  return 0;
}



