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

private:
  long id;

}; // semi-col

void printStudent(Student const &s) {

  std::cout << "name : " << s.name << std::endl;
  std::cout << "sex : " << s.sex << std::endl;
  std::cout << "type : " << s.type << std::endl;
}

void interface(const Student &stdt) { std::cout << stdt.name << std::endl; }

int main() {

  int a;

  Student s1; // default constructor

  Student s5 = Student();

  s1.name = "Adrian";
  s1.sex = "Male";
  s1.type = "Hello";

  printStudent(s1);

  Student s2(s1); // default copy constructor
  printStudent(s2);

  Student s3;
  printStudent(s3);
  { Student s4; }

  Student se("Foo Bar");
  Student si(std::string("Spam Eggs"));

  interface(se);
  interface(Student(std::string("Hello")));

  return 0;
}
