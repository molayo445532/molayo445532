#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>
class Bitset{
public:

  //creates a bitset of size(N=8),with all bits set to 0
  Bitset();

  // creates a bitset of size N,all set to 0;checks for invalid inputs(N<=0)
  Bitset(intmax_t size);

  // creates a biset with a string input; all input characters must be 0 or 1
  Bitset(const std::string & value);

  // deallocates memory and deconstructs class object
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // returns the size of the bitset
  intmax_t size() const;

  // checks if the bitset is valid
  bool good() const;

  // sets the index bit value to 1 only if (N-1)>n>0;otherwise the bitset becomes invalid
  void set(intmax_t index);

  // resets the index bit value to 0 only if (N-1)>n>0;otherwise the bitset becomes invalid
  void reset(intmax_t index);

  // toggles the index bit value only if (N-1)>n>0;otherwise the bitset becomes invalid
  void toggle(intmax_t index);

  // returns true if the index bit value is set to 1, if not and if n is not (N-1)>n>0, returns false
  bool test(intmax_t index);

  // returns the bitset as a string of 0's and 1's from left to right
  std::string asString() const;

private:
  std::string *bitArray;
  int validity;//member varible that tells whether the instance is valid or not
int bitsetsize;//size of bitset
};

#endif
