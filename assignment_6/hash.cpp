/**
 * This program will read in the word file and hash them,
 * then count the collisions
 * @author Bill Jin
 * @version 28th Oct. 2020
 */

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

/**
 * This function will hash the key and return its index it should be in table.
 * @param key the entries from file words
 * @param table_size the size of the table
 * @return the value after entry being hashed
 */
size_t hashx(const string& key, uint64_t table_size);

int main()
{
  string word;
  const unsigned table_size = 102407; //102407 is the nearest prime number to
                                                //the number of words in file.
  const unsigned MAX = 999999;
  
  //Create a vector whose size is 102407, which is used to check if it is
  //the value is colliding or not.
  vector<uint64_t> checking_table(table_size, MAX);

  unsigned collision_counter = 0;

  while (getline(cin, word))
  {
    //save index into temp_index variable
    uint64_t temp_index = hashx(word, table_size);
    
    //if this is the first time stored in vector.
    if (checking_table.at(temp_index) == MAX)
    {
      checking_table.at(temp_index) = temp_index;
    }
    else //otherwise, this is not the first time, collision happenes.
    {
      collision_counter++;
    }
  }
  cout << collision_counter << endl;
  return 0;
}

uint64_t hashx(const string& key, uint64_t table_size)
{
  uint64_t hash_value = 1;
  for (auto character : key)
  {
    hash_value = 43 * hash_value + static_cast<uint64_t>(character);
  }
  return hash_value % table_size;
}
