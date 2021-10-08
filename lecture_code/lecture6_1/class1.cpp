

//
class X { // the class' name is X
          // data members (they store information)
          // function members (they do things, using the information)
};

// Another example
class Y {
public:
  int m; // data members
  int mf(int v) {
    int old = m;
    m = v;
    return old;
  }
};
