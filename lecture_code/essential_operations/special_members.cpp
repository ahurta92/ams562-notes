// The special member functions
struct S {
  S(); // default constructor
  // does not affect other special member functions
  // If you define any of the following, you must deal with
  // all the others.
  S(const S &);            // copy constructor
  S(S &&);                 // move constructor
  S &operator=(const S &); // copy assignment operator
  S &operator=(S &&);      // move assignment operator
};
