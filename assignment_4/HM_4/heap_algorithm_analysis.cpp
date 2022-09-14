//This is the header file for main function.
#ifndef HEAP
#define HEAP
#include <cassert>
#include <vector>

/*
 * a class to implement a maxheap that stores unsigned integers
 */
class Heap
{
 public:

  unsigned push_counter = 0;
  unsigned pop_counter = 0;
  unsigned percolate_counter = 0;
  unsigned bubble_counter = 0;

  /**
   * The constructor of an empty heap has nothing to do
   */
  Heap() { }

  /**
   * The destructor has nothing to do
   */
  ~Heap() {}

  /**
   * Disallow the copy and move constructors and the copy and move
   * assignment operators
   */
  Heap(const Heap& rhs) = delete;
  Heap(Heap && rhs) = delete;
  Heap& operator= (const Heap& rhs) = delete;
  Heap& operator= (Heap&& rhs) = delete;

  /**
   * add an element to the heap
   * @param element the element to add
   */
  void push(unsigned element)
  {
    push_counter++;
    heap.push_back(element);

    bubble_up(heap.size() - 1);
  }

  /**
   * delete and return the largest element of the heap
   * @return the deleted element
   */
  unsigned pop()
  {
    pop_counter++;
    assert(heap.size() > 0);

    pop_counter++;
    unsigned value_to_return = heap.at(0);

    pop_counter++;
    heap.at(0) = heap.at(heap.size() - 1);

    pop_counter++;
    heap.pop_back();

    percolate_down(0);

    return value_to_return;
  }

  /**
   * this function will return the size of the heap
   * @return the size of the heap
   */
  size_t size() const
  {
    return heap.size();
  }

  /**
   * delete all the elements in the heap
   * @return a boolean variable 0
   */
  bool empty() const
  {
    return heap.size() == 0;
  }

  /**
   * just for debugging use
   * display the contents of the heap as a vector to stdout
   */
  void dump() const
  {
    for (auto element : heap)
    {
      std::cout << element << ' ';
    }
    std::cout << std::endl;
  }

 private:

  /**
   * this function will percolate down the root element into the right
   * position.
   * @param position is the index of the root in heap
   */
  void percolate_down(size_t position)
  {
    percolate_counter++;
    //declare left and right children
    size_t left_child_position;

    percolate_counter++;
    size_t right_child_position;

    percolate_counter++;
    percolate_counter++;
    //assign indexes into both children in those two variable
    left_child_position = 2 * position + 1;
    right_child_position = 2 * position + 2;

    percolate_counter++;
    //declare loop control variable to see if the loop can iterate more
    bool loop_guard = true;

    //this loop continues iterates until the element find the right position.
    //and it will always iterates if there is at least 1 child.
    while (number_of_chidren(position) >= 1 && loop_guard)
    {
      percolate_counter += 3;
      //if the element has 2 children.
      if (number_of_chidren(position) == 2)
      {
        percolate_counter++;
        if (heap.at(left_child_position) <= heap.at(right_child_position))
        {
          percolate_counter++;
          //if the element is smaller than its right child
          if (heap.at(position) <= heap.at(right_child_position))
          {
            percolate_counter++;

            percolate_counter += 2;
            std::swap(heap.at(position), heap.at(right_child_position));

            percolate_counter++;
            position = right_child_position;
          }
          else
          {
            //the element is bigger than its all children, loop ends.
            percolate_counter++;
            loop_guard = false;
          }
        }
        else //right child is smaller than left child
        {
          if (heap.at(position) <= heap.at(left_child_position))
          {
            percolate_counter++;

            percolate_counter += 2;
            std::swap(heap.at(position), heap.at(left_child_position));

            percolate_counter++;
            position = left_child_position;
          }
          else
          {
            percolate_counter++;
            //the element is bigger than its all children, loop ends.
            loop_guard = false;
          }
        }
      }
      else if (number_of_chidren(position) == 1) // element only has one child
      {
        percolate_counter++;
        if (heap.at(position) < heap.at(left_child_position))
        {
          percolate_counter++;

          percolate_counter += 2;
          std::swap(heap.at(position), heap.at(left_child_position));

          percolate_counter++;
          position = left_child_position;
        }
        else
        {
          percolate_counter++;
          //the element is bigger than its all children, loop ends.
          loop_guard = false;
        }
      }
      //assign the new index of the children of the element

      percolate_counter += 2;
      left_child_position = 2 * position + 1;
      right_child_position = 2 * position + 2;
      }

      percolate_counter += 3;
    ((void)0);
  }

 /**
  * this function will find the number of the element
  * @return this will return the number of the element
  */
  unsigned number_of_chidren(size_t index)
  {
    //declare two children and convert size_t into unsigned
    unsigned left_c = static_cast<unsigned>(index * 2 + 1);
    unsigned right_c = static_cast<unsigned>(index * 2 + 2);
    if (left_c >= heap.size() && right_c >= heap.size())
    {
      //there is no child for this element
      return 0;
    }
    else if (right_c >= heap.size() && left_c < heap.size())
    {
      //there is one child for this element
      return 1;
    }
    else if (right_c < heap.size() && left_c < heap.size())
    {
      //the element has two children
      return 2;
    }
    //just for avoiding waning and this will never be executed
    const unsigned ERROR = 3;
    return ERROR;
  }

  /**
   *  this function will put the push-back element into its right position
   */
  void bubble_up(size_t position)
  {
    bubble_counter++;
    if (position != 0)
    {
      bubble_counter++;
      size_t parent = (position - 1) / 2;


      while (position != 0 && heap.at(position) > heap.at(parent))
      {
        bubble_counter += 2;

        bubble_counter += 2;
        std::swap(heap.at(position), heap.at(parent));

        bubble_counter++;
        position = parent;

        bubble_counter++;
        parent = (position - 1) / 2;
      }

      //count for two more while loops
      bubble_counter += 2;
    }
  }

  std::vector<unsigned> heap;
};

#endif



