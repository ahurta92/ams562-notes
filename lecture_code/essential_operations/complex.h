class complex {
private:
  double re, im; // respresentation: two doubles
public:
  // construct complex from two scalars
  complex(double r, double i) : re{r}, im{i} {}
  // construct complex from one scalar
  complex(double r) : re{r}, im{0} {}
  // default complex:{0,0}
  complex() : re{0}, im{0} {}
};
