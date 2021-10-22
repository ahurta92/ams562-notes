class complex {
private:
  double re = 0;
  double im = 0; // respresentation: two doubles with default values 0.0
public:
  // construct complex from two scalars
  complex(double r, double i) : re{r}, im{i} {}
  // construct complex from one scalar
  complex(double r) : re{r}, im{} {}
  // default complex:{0,0}
  complex() : re{}, im{} {}
};
