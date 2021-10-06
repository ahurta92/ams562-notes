#include <iostream>

struct Student1 {
  std::string name;
  std::string sex;
  std::string type;
  std::string status;
};

// define a player class with a name and position
class Student {
public:
  std::string name;
  std::string sex;
  std::string type;
  std::string status;
  // default
  Student() {
    name = "NA";
    id = -1;
    type = "idk";
    sex = "NA";
    std::cout << "using our default constructor" << std::endl;
  }

  Student(const Student &other) {

    id = other.id;
    name = other.name;
    sex = other.sex;
    type = other.type;
    status = other.status;
    std::cout << "using our copy" << std::endl;
  }

  ~Student() {
    //
    std::cout << "using our destructor" << std::endl;
  }
  explicit Student(const std::string &nm) { name = nm; }

  // constructor with student name and ID
  Student(const std::string &nm, long ID) {
    name = nm;
    id = ID;
  }

  // constructor with all information
  Student(const std::string &nm, const std::string &s, const std::string &tp,
          const std::string &st, long ID) {
    name = nm;
    sex = s;
    type = tp;
    status = st;
    id = ID;
  }
  void printStudent() {
    std::cout << "name : " << name << std::endl;
    std::cout << "sex : " << sex << std::endl;
    std::cout << "type : " << type << std::endl;
  }

private:
  long id;

}; // semi-col

class MyInt {

public:
  void set_value() {
    // we can explicitly use this to access a
    this->a = 0;
  }
  int get_value() const { return a; }
  void print_value() const {
    std::cout << a << std::endl;
    ;
  }
  // overload!
  void set_value(int a) {
    // we can omit this, which is typically
    // what ppl do in practice
    this->a = a;
  }
  void copy(const MyInt &other) {
    a = other.a; // within class definition, we can access _a!
  }

private:
  int a;
};
void call_myClass(const MyInt &obj) {
  // ERROR! because set_value passes MyClass * in
  // not const MyClass *
  // and the const qualifier applied to obj will
  // automatically affect all its member functions/attributes
  obj.get_value();
  obj.print_value();
}

void interface(const Student &stdt) { std::cout << stdt.name << std::endl; }

int main() {

  MyInt a;
  a.set_value(4);

  MyInt b;
  b.copy(a);

  return 0;
}
