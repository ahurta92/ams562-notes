

class X {

public:
  X(int);                  // "ordinary construction
  X();                     // default construction
  X(const X &);            // copy constructor
  X(X &&);                 // move constructor
  X &operator=(const X &); // copy assignment: clean up target and copy
  X &operator=(X &&);      // move assignement: clean up target and  move
  ~X();                    // destructor:clean up
  //...
};

class complex {
  double re = 0;
  double im = 0;

public:
  complex(double r, double i)
      : re{r}, im{i} {} // construct complex with two scalars
  complex(double r) : re{r} {}
  complex() {}
  //..
  //
};
