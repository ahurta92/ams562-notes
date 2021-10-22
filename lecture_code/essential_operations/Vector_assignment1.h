class Vector {

public:
  // allocates mem on free store
  Vector(Vector &&a);            // move constructor
  Vector &operator=(Vector &&a); // move assignment

private:
  double *elem;
  int sz;
};
