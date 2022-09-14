#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "heap.h"

using namespace std;

int main(int argc, char** argv)
{
  Heap h;
  Heap h_2;
  const unsigned MAX_RANDOM_VALUE = 10000000;
  default_random_engine get_next_value(static_cast <unsigned>
                    (chrono::system_clock::now().time_since_epoch().count()));
  uniform_int_distribution<unsigned> uniform(0, MAX_RANDOM_VALUE);

  //Dummy is used to waning
  int dummy = argc;
  dummy++;

  unsigned input_array_size = stoul(argv[1]);


  //Declare a vector.
//  vector<unsigned> random_array(input_array_size);


  //Use for loop to assign each element in vector.
  for (size_t i = 1; i <= input_array_size; i++)
  {
    unsigned random_value = uniform(get_next_value);

    h.push(random_value);

    cerr << i << " "<< h.bubble_counter + h.push_counter << endl;
    h.bubble_counter = 0;
    h.push_counter = 0;
  }

  for (size_t i = input_array_size; i >= 1; i--)
  {
    h.pop();
    cout << i << " " << h.percolate_counter + h.pop_counter << endl;
    h.percolate_counter = 0;
    h.pop_counter = 0;
  }



  //Output the elements.
  //h.dump();
}


