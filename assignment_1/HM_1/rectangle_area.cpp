// a program to illustrate style and exercise several functions
// create a number of rectangles specified on the command line of
// random lengths and widths
// Zhihao Jin
// 8/18/2020

#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

/** 
 * compute the area of a rectangle 
 * @param length the length of the rectangle 
 * @param width the width of the rectangle 
 * @return the area of a length X width rectangle
 */
unsigned get_rectangle_area(unsigned length, unsigned width);

/** 
 * get a random value between low and high inclusive 
 * @param low the smallest random value 
 * @param high the largest random value 
 * @return a random value between low and high 
 */
unsigned get_random_within(unsigned low, unsigned high);

int main(int argc, char* argv[])
{
  const unsigned MAX_WIDTH = 75;
  const unsigned MAX_LENGTH = 500;
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << "n where n is the number of" <<
         " rectangles to generate" << endl;
    return 1;
  }

  srand(static_cast<unsigned>(time(nullptr)));
  cout << "This program displays the area of rectangles" << endl;
  cout << "The widths are within 1 and " << MAX_WIDTH << " and the lengths"
       <<" are within 1 and " << MAX_LENGTH << endl << endl;

  unsigned number_of_rectangles = static_cast<unsigned> (stoul (argv[1]));
  for (unsigned rectangle = 0; rectangle < number_of_rectangles; rectangle++)
  {
    unsigned length = get_random_within(1, MAX_LENGTH);
    unsigned width = get_random_within(1, MAX_WIDTH);
    unsigned area = get_rectangle_area(length, width);
    cout << "The area of a " << width << " by " << length << " rectangle is "
         << area << endl;
  }
  return 0;
}

unsigned get_random_within(unsigned low, unsigned high)
{
  assert(low <= high);
  unsigned value = static_cast<unsigned>(rand()) % (high - low + 1) + low;
  return value;
}

unsigned get_rectangle_area(unsigned length, unsigned width)
{
  return length * width;
}