#ifndef _ARRAY_HPP
#define _ARRAY_HPP

class Array {
 public:
  // default constructor
  // overwrite this one to set data and size to
  // empty status
  Array();

  // copy constructor
  // we want to perform a deep copy so that
  // each Array will own its own
  // data and copies the values of the "other"
  // hint: you need a for/while loop here
  Array(const Array &other) {
    // the default copy constructor is copying data attributes accordingly
    this->_size = other._size;
    // this _data points to the same underlying raw dynamic array in other
    // this->_data = other._data;

    // what we need is to create another dynamic memory that has the same length
    // as other's and the same values as others.
  }

  // constructor with array size and
  // the default initialization value
  explicit Array(unsigned n, double v = 0.0) {
    // three steps:

    // step 1:
    // allocate a raw dynamic array and assign the address to _data
    // use _data to allocate a chunk of dynamic memory with length n

    // step 2:
    // copy n to _size

    // step 3:
    // write an iterative loop to initialize all entries in _data with v
  }

  // we want to overwrite the implicit destructor
  // so that the memory is freed!
  ~Array() {
    delete[] this->_data;
    this->_size = 0;
  }

  // get the length of array
  unsigned size() const { return this->_size; }

  // get the data pointer of array
  // Array *this
  double *data() { return _data; }

  // get read-only pointer of array
  // const Array *this
  const double *data() const;

  // given a rhs Array, copy its value
  // make sure the sizes are same
  void copy(const Array &rhs) {
    // step 1:
    // if rhs (constant) has different size of this
    // then resize this

    // step 2:
    // copy rhs._data to this->_data one by one
  }

  // reference entry "index" of the data
  // it allow to modify the value at _data[index]
  double &at(unsigned index) { return this->_data[index]; }

  // read-only reference entry "index" of the data
  // this is just for loading the data
  const double &at(unsigned index) const { return this->_data[index]; }

  // resize the array
  // require memory allocation and deallocation
  // prsv is a flag that indicates if the user
  // wants to preserve the old values
  //
  // pseudo code:
  //   create new_data (dynamically) with size new_size
  //   if presv:
  //      copy _data to new_data with size = min(new_size, _size)
  //   free the old memory (_data)
  //   make _data points to the new_data
  //
  // hint: you can call destructor explicitly in this function to free
  // old memory
  void resize(unsigned new_size, bool prsv = true);

  // some math functions
  // L-2 norm, sum, maximum/minimum, and dot (inner) products
  double norm() const;                  // l2 norm
  double sum() const;                   // sum
  double max() const;                   // maximum value
  double min() const;                   // minimum value
  double dot(const Array &rhs) const {  // inner
    // for this one, compute the dot product (or inner product)
    // between this and rhs. The region is the min(this->_size and rhs.size())
  }

  // addition: this+rhs, return a new array
  Array add(const Array &rhs) const {
    // you need to make a decision that if this and rhs do not the same length
    // then what is the length of the return array

    unsigned n = std::min(_size, rhs.size());
    Array v(n);  // make a copy of rhs
    // write a loop to compute this+rhs and store the results to v
    return v;
  }

  // subtraction: this-rhs, return a new array
  Array sub(const Array &rhs) const;

  // do some terminal printing
  void print() const;

  // operators

  // accessing operator
  double &operator[](const unsigned index) { return this->at(index); }
  const double &operator[](const unsigned index) const {
    return this->at(index);
  }

  // assignment, hint call resize if other and "this" have difference sizes
  Array &operator=(const Array &other) {
    // it is not a constant memory function
    // so we can call resize
    resize(other.size());
    // copy the value correspondingly
    return *this;  // do not forget this
  }

 private:
  double *_data;   ///< data pointer
  unsigned _size;  ///< length of the array
};

// free functions

// addition of two arrays
Array operator+(const Array &lhs, const Array &rhs) { return lhs.add(rhs); }

// subtraction of two arrays
Array operator-(const Array &lhs, const Array &rhs) { return lhs.sub(rhs); }

void test_func() {
  Array v(100);
  // we know v should have length 100, with initialized value of zero
  // v = {0, 0, 0, ..., 0}
  for (unsigned i = 0; i < v.size(); ++i) {
    v[i] = i;
    v.at(i) = i;
  }

  Array v2(v);  // make a "copy"
  Array v3;     // default
  // the size of v3 should be 0
  v3 = v;
  // the size of v3 should be 100, and v3 == v
}  // destructor is called, dynamic memory inside v will be freed.

#endif
