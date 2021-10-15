.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec6_1:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec6_class_review:

User defined Types
************************

- C++ provides various built-in types, such as :code:`char,int,` and :code:`double`.
- Types that are not built-in are called `user-defined types` (UDTs)

    - They can be a part of the standard library
    
        - :code:`string`
        - :code:`vector`
        - :code:`ostream`
    - They can be types that we build ourselves. 
    
        - :code:`Student`
        - :code:`Complex`
        - :code:`Xspace`

Why use types?
######################

- Types are good at directly representing ideas in our code.

    - Helps us, the compiler, and those who read our code understand our code better
    - When we want to do integer arithmetic, :code:`int` is a good type.
    - When we want to manipulate text, :code:`string` is a good type. 
    
  - If you can think of "it" as a separate entity, its plausible that it can be made into a class
  - Vector, Matrix, input stream, string, FFT, graph, box, clock


How to create types?
######################

- C++ provides two kinds of user-defined types:

    - :code:`classes`
    - :code:`enumerations`

- A class is a (user-defined) :code:`type` that specifies:

    - How objects of that type are represented (data members) 
    - How objects  of that type can be used (function members) 

- Classes serve as a key building block of large and small programs.


Classes and Members
************************

- A class is a user-defined type made up of

    -  built-in types 
    -  other user-defined types
    -  and functions

- The parts that make up a class are called the **members**
  
    - A class can have zero or more members


.. code-block:: cpp

    class X{ // classes name is X
    // data members (they store information)
    // function members (the things they do)
    };

Here we define a simple type :code:`X` with no members.
The class definition needs to declare all of the classes members
inside the scoped braces of the class

.. code-block:: cpp

    class Y{ 
        public:
            int m;// data member
            int mf(int v){int old=m; m=v; return old;}// function member
    };

- Members can be of various types.

    - data members define the representation of an object of the class
    - function members provide the operations on the objects

- We access members using :code:`object.member` notation

.. code-block:: cpp

    Y var; // var is variable of type X
    var.m =7; // access var's data member m
    int x=var.mf(9);// call var's member function mf()
    
Interface and Implementation
##############################

- We can think of classes as having an interface plus an implementation

    - **Interface** is how the user can use objects of a class

        - Using keyword :code:`public:`
    - **Implementation** part of the class's declaration that user use indirectly through the interface
        - Using keyword :code:`private:`

.. code-block:: cpp

    class X{
        public:
        // public members
        // the interface accessible by all
        // functions
        // types
        // data

        private:
        // private members
        // the implementation details (used by members of the class only)
        // functions 
        // types
        // data
        };

- Class members are private by default:

The following two classes are effectively the same:

.. code-block:: cpp

    class X{
        int mf();
        };

    class X{
        private:
        int mf();
        };
    
If you try to access a private member using the accessor notation will be an error

.. code-block:: cpp

    X x; // variable of type X
    int y=x.mf(); // error mf is private member

A user cannot directly refer to a private member.  Instead they have to go through
a public member function for example:

.. code-block:: cpp

    class X{
        private:
            int mf();
            int m;
        public:
            int f(int i){m=i; return mf(i);}
        };

    X x;
    int y=x.f(2);// access through member function f
    
The use of private and public is to separate the interface and implementation of a class.

- A :code:`struct` is a class where the members are public by default:

.. code-block:: cpp

    struct X{
        int mf();
        };
    // These two structs are the same
    struct X{
        public:
        int mf();
        };

- A :code:`struct` is used for data structures where the members can take any value
- There is no need to restrict how a user uses the class.

Evolving a Class
##############################

We can illustrate how to build a class, and the various language
features supporting the type by showing how we might evolve a simple
data structure representing a date into a class with private
implementation details and supporting operations.   

This following a simple :code:`struct` representing a a date.
The :code:`struct` only stores the value of the month, day, and year in 
integer variables.  

.. literalinclude:: /lecture_code/lecture6_1/date_struct0.cpp
    :language: cpp

- We are free to use :code:`Date` however we like.
- We can read and write to the data members to change the values
- Not very connivent
- Error prone

To improve functionality of our :code:`Date` type we can add some
helper functions which will help users with the most common tasks.

For most types the most common operations are:

- initialization
- assignment

For our :code:`Date` type we also provide a method to increase the value of a date.


.. literalinclude:: /lecture_code/lecture6_1/date_struct1.cpp
    :language: cpp


Member Functions
##############################

So far we have added a function to initialize a date and add days to a date.
In principle these functions allow us to generate dates with valid values.
This is helpful as long as we use actually remember to use these functions.
It is possible that a user does not use these functions or forgets to initialize a :code:`Date`.
For this reason, it is best to provide member functions which help require that your types
are used correctly.

- A member function is a function that is declared as a member of a class within the class body.

.. literalinclude:: /lecture_code/lecture6_1/date_struct2.cpp
    :language: cpp

- Here we increase the functionality of our Date structure by including member functions.  
- A member function with the same name as a class is a constructor

    - The constructor is used for initialization
    - It is a compiler error to initialize a class that uses a constructor that requires an argument.
- Above you can find all the ways to call the argument constructor

    - You can also use :code:`Data(2021,11,8)` but :code:`Date{2021,11,8}` is preferred because it indicates initialization

.. note:: 
    Notice that by adding a constructor we can no longer create uninitialized 
    dates unless we explicitly add the default constructor.

.. warning:: 
    Since the members of the struct or public, even if we have functions
    that return valid dates nothing prevents the user from making 
    the date invalid.

Keep Details private
##############################

- We still have a problem with the current state of :code:`Date`
- People can still forget to use the member functions
- A user can directly change any one of the values directly
- This can and will lead to users creating invalid dates which will in turn produce run-time errors or bad-results.

For this reason it is best keep the details and representation of :code:`Date` as private.

.. literalinclude:: /lecture_code/lecture6_1/date_class0.cpp
    :language: cpp


In the case of a date, there is a notion of what is a valid date.  
When designing types, it is essential to know the valid values for data members of the kind.
We should design types so that values are guaranteed to be valid:

- Hide the representation :code:`y,m,d`
- Provide a constructor that only creates valid types
- Provide member functions that expect valid dates and return valid dates in return

An **invariant** is a rule that constitutes what is a valid value of a type.

The invariant for :code:`Date` is that it must represent a day is the past, present, or future.

If we can't think of a good invariant for a data type then we can probably just use a :code:`struct`



Defining Member functions
==========================

Lets go back to the our date class.  So far we have shown 
the interface of our class but eventually we need to actually
implement our member functions.  Typically class are structured 
so that the interface lies on top and the implementation lies 
somewhere else, either in the same file or in a source file. 

.. literalinclude:: /lecture_code/lecture6_1/date_class1.cpp
    :language: cpp

When we defined member functions outside of a class we need to
tell the compiler which class this function is a member of.
We do this with the :code:`class_name::member_name` syntax.  

The :code:`:y{yy},m{mm},d{dd}` syntax is how we can initialize members
of our class in a constructor.  We can write:

.. code-block:: cpp 

    Date::Date(int yy, int mm, int dd) {
        y=yy;
        m=mm;
        d=dd;
    }

but this will first call the default initializer for each of the
members and then assign the values to them.  

We can also define member functions right in the class definition:


.. literalinclude:: /lecture_code/lecture6_1/date_class2.cpp
    :language: cpp

Writing the definition of the member function within the class definition 
has three effects:

1. The function will be inline;
2. All the uses of the class will have to be recompiled whenever you change the body of an inline function.
3. The class definition gets larger


Referring to the current object
=================================

Consider the simple use of the :code:`Date` class so far:

.. code-block:: cpp 

    class Date{ 
        // ....
        int month(){ return m;}
    private:
        int y,m,d; // year, month, day
    };

    void f(Date d1, Date d2){
        cout<<d1.month()<<" "<<d2.month()<<"\n";
        }

- How does :code:`Date::month()` know which value to return
- :code:`Date::month()` has an implicit argument which identifies which object called it.




Reporting errors
==========================

- What can we do when a user tries to create an invalid date?
- We can throw an exception
- We can create the exception within the class! 

.. literalinclude:: /lecture_code/lecture6_1/date_class3.cpp
    :language: cpp

- We place the testing of validity in a separate function :code:`is_valid()`
- This allows us catch errors in the initialization of our types.

Enumerations
++++++++++++++++++++

An :code:`enum` is a user-defined types, which specify a set of values as symbolic constants.

.. literalinclude:: /lecture_code/lecture6_1/enum0.cpp
    :language: cpp

- The body is a list of Enumerations
- The :code:`class` means that the enumerations are in the scope of the enumeration.

    - to refer to :code:`jan` we need to write :code:`Month::jan`
- You can specify values or have the compiler pick

    - If you let the compiler pick each enumeration will have the value of the previous plus one 
    - If you don't specify the fist value it will start at 0

Enumerations are useful whenever we need a set of related nambed integer constants.

Operator Overloading
+++++++++++++++++++++++++++++

- You can define almost all C++ operators for a class or enumerations.
- This is called operator overloading.  
- We use operator overloading when we want to provide a conventional notation for a type that we design

.. literalinclude:: /lecture_code/lecture6_1/operator_overload0.cpp
    :language: cpp


- We can define just about any operator provided by C++ but only use existing operators such as:
- :code:`+,-,*,/,%,[],(),^,!`

- You can only define operators with the conventional number of operands; 
  
    - for example you can define a unary :code:`-` but not a unary :code:`<=`, 
    - and a binary :code:`+` but not a binary :code:`!`. 

- The language allows you to use existing syntax for the types you define.

An operator overload must have at least one user-defined type as operand:

.. code-block:: cpp

    // Overloading operators

    int operator+(int int) // error can't overload built in
    Vector operator+(const Vector &, const Vector &);//Okay
    Vector operator+=(const Vector &,int);//Okay

.. note:: 

    It's a good idea define operators with their conventional meaning.  

    - :code:`+` should be addition 
    - :code:`-` should be subtraction 
    - :code:`*` should be binary multiplication 
    - :code:`[ ]` should be access   
    - :code:`( )` should be call   

    This is not a strict rule.  


Class Interfaces
************************

How can we create good class interfaces for our users?
Here are some general rules:

- Keep interfaces complete
- Keep interfaces minimal
- Provide constructors
- Support copying (or prohibit it)
- Use types to provide good argument checking
- Identify nonmodifying member functions
- Free all resources in the destructor

Argument Types
#########################

It is possible to use types to provide good argument checking for our types.
For example in the case of our :code:`Date` class we used three :code:`int`s
as the arguments.  That can cause problems

.. code-block:: cpp

    Date d1{4,5,2005};// year 4 and bad day
    Data d2{2005,4,5};// April 5 or May 5

- The first line the problem is obvious
- The second line we try and fix the problem
  
    - Did we mean April 5th or May 4th?

- To prevent errors we can use a :code:`Month` type.

We can bring in the :code:`Month` enumeration we defined earlier and 
use it as one of our data members.

.. literalinclude:: /lecture_code/lecture6_1/date_class4.cpp
    :language: cpp

- Now the compiler will catch if we swap a month and a day
- The enumeration gives us symbolic names to use which is less error-prone:
- Notice we don't use :code:`Month.nov` 

    - :code:`Month` is a type.  Not an object
    - :code:`nov` is an enumeration.  Not a data member

- When we can, we should try to catch errors at compile time.

We can also provide a type for the year of a date.

.. literalinclude:: /lecture_code/lecture6_1/Year.h
    :language: cpp

- Notice that we set a min and max year using the :code:`static const` keyword

    - This is the way we can define constants within a class
    - :code:`static` insures that there is just one copy of a value in a program. It does not copy the value for each object.


Copying
#########################

When we create objects we are forced to think about the objects constructor.
The constructor is one of the most important members of a class.

- You decide how to initialize an object of your type
- You also decide what is required to initialize the object
- How can we insure that we initialize a valid object.

After initialization we need to consider if we can copy our objects.  If we can,
how do we copy?

For a :code:`Date` or :code:`Month` we can easily copy. 
We can simply just copy each of the members and this is done by default in C++

- C++ provides a default constructor which copies each member.

example:

.. code-block:: cpp

    Date holiday{2021,Month::oct,8};//initialization
    Date d2=today;// copy  
    Date d3=Date{2021,Month::oct,5}
    holiday =Date{1978,Month::dec,24};// assignment
    d3=holiday;

Default Constructors
#########################

- We should try to avoid creating initialized objects because this can lead to many errors.
- To avoid this issue we can provide a constructor.

    - In the case of :code:`Date` programmers are forced to use 3 values for the Date
    - An uninitialized :Code:`Date` object cannot exist.

- Many classes can have a sensible default values for their members.

.. code-block:: cpp

    std::string s1; // default value: empty string " "
    std::Vector v1; // default value: empty container; no elements 

- In these cases we can provide a **Default constructor**
- The syntax for a default constructor of type :code:`T` is :code:`T{}`
  
.. code-block:: cpp

    std::string s1=string{}; // default value: empty string " "
    std::Vector v1=Vector{};// default value: empty container; no elements 

For the built-in types such as :code:`int`, the default constructor means :code:`0`.
Therefore,

.. code-block:: cpp

    int a=int{};// 0
    double d=double{};//0.0

Even though it's hard to think of a default value for our :code:`Date` class we can still
set one just to show how we can.


.. literalinclude:: /lecture_code/lecture6_1/date_class5.cpp
    :language: cpp

- Here we set the default day to Jan 1 2001.  
- :code:`Date::Date()` provides the default constructor definition

Instead of placing the default values in the constructor, we
can also place them on the members themselves:

.. literalinclude:: /lecture_code/lecture6_1/date_class6.cpp
    :language: cpp



Const member Fuctions
#########################

- Some variables are meant to be changed while are some are not.
- Some member functions are meant to change the values while some are not
- We can specify that operations on a class can be either **modifying** or not **nonmodifying**

    - Operations that are nonmodifying can be invoked for :code:`const` objects
    - Operations that are modifying cannot be invoked for :code:`const` objects

.. literalinclude:: /lecture_code/lecture6_1/date_class7.cpp
    :language: cpp

- Calling a non const function for a const member is an error
- Trying to change an object from a const member function is also an error. 


Member functions vs "Helper functions"
#############################################

By designing our classes to be minimal yet complete we are required to leave
out many operations that are merely useful.  

- Functions that are helpful and can be implemented as freestanding function should be implemented outside of the class
- Prevents bugs in the function from corrupting the class itself.
- Not accessing the representation directly is important

    - When debugging a class you first look at the members that directly access the representation
    - It would be better if there is a minimal amount versus say 50

- When a representation changes, only the member functions need to change.  For example

.. code-block:: cpp 

    // helper functions
    // access d using d.day(), d.month() and d.year()
    // make new Date to return
    Date next_Sunday(const Date& d){/*...*/}
    Date new_weekday(const Date& d){ /*.....*/}
    bool leapyear(int y){/*....*/}
    bool is_date(int y, Month m, int d);
    bool operator ==(const Date& a, const Date &b)
    { return a.year()==b.year()&&a.month()==b.month()&&a.day()==b.day();}
    bool operator !=(const Date& a, const Date & b){
    return !(a==b);
    }

- When the class representation itself changed none of these helper function need to be changed.
- Helper functions are convenience functions, auxiliary functions.
- Helper functions are a design concept
- Helper functions often take arguments of the classes that they are helpers of.  

We can use namespaces to identify a group of helper functions.  
    


Date Class
************************

Here is what an example :code:`Date` class might look like.  
Some of the function bodies are just comments.  You can go ahead
and try to implement the functions yourself.  

The declarations are in a file called Chrono.h

.. literalinclude:: /lecture_code/lecture6_1/Chrono.h
    :language: cpp

The definitions are in a file called Chrono.cpp

.. literalinclude:: /lecture_code/lecture6_1/Chrono.cpp
    :language: cpp

Exercises
************************

Excercise 1
#############################################

In HW2 we asked you to generate random points on a unit sphere and compare the **great circle** length
between the points. Here I would like you implement the same solution with help classes and helper functions.

1. Implement a class SpherePoint

    1. The representation should be 3 doubles representing the x,y, and z coordinates.
    2. Implement a constructor that takes in two doubles theta, and phi for the angles of the sphere.
    3. Implement a default constructor that generates a random point on a sphere.
    4. Create a helper function that takes in two :code:`SpherePoint` and returns the great circle distance.

2. Generate an array of N random Sphere Points and find the max and min lengths.  

Exercise 2
#############################################

1. Implement the leapyear() function in Chrono.cpp
