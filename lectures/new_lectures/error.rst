.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec6:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec6_Errors_:

Errors
########################

.. contents::
   :local:
   :backlinks: top

Dealing with errors is a fundamental part of developing a program. 
Our objective is to write programs that satisfy these basic requirements.  

1. Should produce the desired results for all legal inputs
2. Should give reasonable error messages for illegal inputs
3. Need not worry about misbehaving hardware
4. Need not worry about misbehaving system software
5. Should be allowed to terminate after finding an error


To achieve this objective, we will discuss errors and how to deal with errors in C++. 


Kinds of Errors
***************************

* Compile-time errors
   * syntax errors
   * type errors
* Link-time errors
* Run-time errors
   * Detected by computer
   * Detected by library
   * Detected by user code
* Logic errors
   * detected by the programmer when running code and seeing unexpected results



Error Handling in Modern C++
===========================================


Modern C++ allows us to deal with errors in two ways, assertions, and exceptions.
Assertions will enable us to deal with programming errors
that help us find bugs in our computations.  
Exceptions allow us to handle situations that prevent the normal execution of our programs,
such as incorrect argument inputs.  

Assertions
=========================

The macro :code:`assert` which is found in the header :code:`<cassert>` is useful
in finding programming errors.  :code:`assert` evalues an expression and
if the result is false the program will terminate immediately.  For example, 
say we write a function that computes the square root of a number using
an intersting algorithm  we can check if the result is non-negative


.. code-block:: cpp
   
   double square_root(double x){
   
   check_somehow(x>=0);
   // do the computation

   assert(result>=0);

   return result;
   }

If the result is negative the program will terminate and return an error


An advantage of using :code:`assert` is that once we feel that we have
fixed all of the bugs we can let :code:`assert` dissappear by defining,
:code:`NDEBUG` before including :code:`<cassert>`.

.. code-block:: cpp

   #define NDEBUG
   #include <cassert>

This will remove all assertions when building your program.  If we rather 
not change our source this way we can also compile with :code:`-DNDEBUG` 
compiler flag to remove the assertion.  For example

.. code-block:: console

   g++ sqrt.cpp -o my_sqrt -03 -DNDEBUG



Exceptions
=========================

Exceptions are used for errors that are sometime not preventable but occur
in the runtime of a program.  Some examples may include:

* Incorrect arguments in the call to a function
* Reading a file that does not exist
* Trying to allocate more memory than is available on the machine


Argument Checking
***************************

One of the most critical ways we can deal with errors is by checking the input values of our functions.
We should check the input meets our expectations and our requirements.

Compiler checks inputs arguments
======================================

The compiler helps us check our input arguments.
The compiler will check whether the number and type of inputs match the function declaration. 

Example bad_arguments.cpp
*****************************


.. code-block:: cpp

   int area(int length, int width){
      return length*width;
   }

   int x1=area(7); // error wrong number of inputs
   int x2=area("seven",2); // 1st argument as wrong type
   int x3=area(7,10); // ok
   int x5=area(7.5,10);// ok but be careful... truncation error

   int x=area(10,-7); // types are correct but value makes no sense

The compiler will check the validity of each of these cases.
In the cases where there is an obvious error, the code will not build.
However, some errors are harder to find as the compiler does not find them.  


How to report an Error
======================================

One common way we can deal with errors is by having our program
return a bad result.  For example, we know
that we do not want negative values for the arguments in computing the area.
When we come across a negative value, we can return :code:`-1` indicating
the error. 

.. code-block:: cpp
   int area(int length, int width){
      if(length <= 0 || width <= 0) return -1;
      return length*width;
   }

When we call the function, we can check for the error code using an if- statement.  
This  method works, but it forces us to check
for the error code each time we call the function, which we can easily forget.

.. code-block:: cpp

   int z=area(x,y)
   // a wrapper of std::runtime_error(cosnt)
   if (z<0 ) error("bad area computation");
   //..

Another way we can report an error is by using the global
:code:`errno` variable defined int :code:`<cerrno>`.  :code:`errno`
is a integer used for indicating errors.  You can read more about it
`here <https://en.cppreference.com/w/cpp/error/errno>`_

.. code-block:: cpp
   int area(int length, int width){
      if(length <= 0 || width <= 0) errno=7;
      return length*width;
   }

Again we can check for the error code wherever we call the function.

.. code-block:: cpp

   int z=area(x,y)
   // a wrapper of std::runtime_error(cosnt)
   if (errno==7 ) error("bad area computation");
   //..


Exceptions
=========================

Instead of using error codes and if-statements C++ provides us with 
exceptions.  The idea of using exceptions is that that we would 
like to separate the action of detecting error which should be done by
the function from handling the error, which should be done by the 
the caller. 

In the following code, we report an error by throwing an exception.
We define the error as :code:`Bad_area{}`.  We will talk more about Classes
in future lectures, but all you need to know is that a class
is a user-defined type.  When the function encounters an error, we throw the exception.   Now the program is required to handle the exception, or the program will terminate. 

.. code-block:: cpp
   
   #include "../std_lib_facilities.h"
   // use global error code
   class Bad_area {}; // class is a user defined type
   int area(int length, int width) {
     if (length <= 0 || width <= 0) {
       throw Bad_area{};
     }
     return length * width;
   }

In order to handle the error we need to :code:`catch` the exception.  This is done using 
a :code:`try-catch` block:

.. code-block:: cpp

   try {
   ...
   } catch ( e1_type & e1 )
   { ...
   } catch ( e2_type & e2 ) { ... }

Whenever we expect a problem that we can solve, we should open a try-block.  
After the closing brace, we can catch exceptions and start handling errors
depending the type of error.  When an exception is throwin, the first
catch-block with a matching type is executed.  The catch-block with
an ellipsis catches all exceptiosn:

.. code-block:: cpp

   try {
   ...
   } catch ( e1_type & e1 )
   { ...
   } catch ( e2_type & e2 ) { ... }
   } catch (...) { // deal with all other exceptions
    }

It is reccomended to catch exceptions by reference.  After the exception is caught the exectuation continues after 
the catch-block.  

.. code-block:: cpp

   int main() {
     int x = 8;
     int y = -1;
     try {

       int z = area(x, y);
     } catch (Bad_area) {
       cerr << "opps! Bad area calcluation - fix programming" << endl;
     }

     cout<< "Hello world"<<endl;
   }


If you would like to terminate the program
you can use :code:`exit` defined in `<cstdlib>` 

.. code-block:: cpp

   int main() {
     int x = 8;
     int y = -1;
     try {

       int z = area(x, y);
     } catch (Bad_area) {
       cerr << "opps! Bad area calcluation - fix programming" << endl;
       exit(EXIT_FAILURE)
     }

     cout<< "Hello world"<<endl;
   }

In the following case, instead of exiting when we catch the 
exception we can fix the error by using a while-block.  

.. code-block:: cpp
   
  int main() {
  int x;
  int y;
  bool keep_trying = true;
  do {
    cout << "Please enter a length " << endl;
    cin >> x;
    cout << "Please enter a width " << endl;
    cin >> y;

    try {

      int z = area(x, y);
      keep_trying = false;
      cout << "The area is equal to " << z << endl;
    } catch (Bad_area) {
      cerr << "opps! Bad area calcluation - fix programming" << endl;
    }
  } while (keep_trying);
   }



Exercise Error Handling matlab arrays 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Your task is to implement a set of functions which generate 
the following set of standard arrays.  

* :code:`allocate_array(N)` returns pointer to array N dimensional arrayn
* :code:`fill_array(N,val,array)` fills array of size N with value val
* :code:`ones(N)` returns array of ones with size N
* :code:`zeros(N)` returns array of zeros with size N
* :code:`print_array(array,N)` prints an array of N 
* :code:`linspace(pt1,pt2,N)`  returns an array of N evenly spaced values between pt1 and pt2 

.. note:: 
    * First implement functions using doubles.
    * Set default values for the size parameter.
    * Using function overloading to create a set of functions using ints
    * For each function think about the input and output types.
    * Write a main that tests your implementations

Challenge Task:

Write a function that takes in a function pointer to a standard math fuction defined in
in :code:`<cmath>` and an array.  
The function should evaluate the function at each value of the array.  
See :code:`function_pointer.cpp` example to see a use of function_pointers.   

Evaluate :code:`std::cos` and :code:`std::sin` between 0 and :math:`2*pi`