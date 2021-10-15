// method 1 initializer-list constructor
Vector(std::initializer_list<double> l)
    : elem{new double[l.size()]}, sz{static_cast<int>(l.size())} {
  std::copy(l.begin(), l.end(), elem);
}
