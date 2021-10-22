

class X {

public:
  X(int);                  // "ordinary construction: create an object
  X();                     // default construction
  X(const X &);            // copy constructor
  X(X &&);                 // move constructor
  X &operator=(const X &); // copy assignment: clean up target and copy
  X &operator=(X &&);      // move assignement: clean up target and  move
  ~X();                    // destructor:clean up
  //...
};
