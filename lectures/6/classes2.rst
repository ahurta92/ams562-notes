.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec6_2:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec6_class_review:

Classes
************************

In the last class, we presented some C++ language features that allow us to create our own user-defined types.  

We discussed the difference between the interface and implementation of our classes.
We showed how we can design easier and safer classes by creating a good interface for our classes.
Whenever possible, we should try to keep users from directly accessing the representation of types.
Data should only be accessed carefully designed members functions that ensure the validity of our objects.
These member functions should be guaranteed to generate objects with valid values and throw exceptions when
they are incorrect (remember invalid Dates). Finally, we discuss some of the features of a good class interface.
A good class interface should provide a few things.

- Provide Constructors that initialize our types with valid values.
- The interface should support or restrict copying.  
- We also keep our interface as minimal as possible.
- Not every function needs access to the representation
- Use types when possible to provide good argument checking for our member functions
- Identify all the nonmodifying member functions
- Provide meaningful operator overloaded functions that reflect how a user might expect to use an object.
- Provide a set of helper functions defined outside of class. 

FIn this class, we will show how we can use some of the language features presented in the last lecture to create 3 basic categories of types. 

- Concrete Types
- Abstract Types
- Classes in Class Hierarchies

Most classes that can be built can be categorized into these three fundamental types or variants of such.
Therefore, the techniques used to create these fundamental types can implement any other complicated type you wish to make. 

Concrete types
##########################

The basic idea of a concrete type is that they are a type that should behave just like the built-in types.
So, for example, when we wish to define a Complex number type, it should behave just like an int.  

.. literalinclude:: /lecture_code/classes2/concrete1.cc
    :language: cpp

On the other hand, we can also have vectors and strings, which behave just like arrays.
They are containers that hold data of a particular type, but they behave better.

.. literalinclude:: /lecture_code/classes2/concrete2.cc
    :language: cpp

The defining characteristic of a concrete type is that the representation is a part of the class definition.
We will demonstrate this with a few examples.  



Arithmetic Types
##########################

Here we present the classical user-defined arithmetic type: complex.

.. literalinclude:: /lecture_code/classes2/complex1.h
    :language: cpp

Here we present the classical user-defined arithmetic type: complex.

This complex type is represented by two double, which store the real and imaginary parts of a complex number object.  
This class definition contains only the operations that allow users to access the underlying representation

Constructors
----------------------

As you can see, we have three constructors. First, we have a default constructor that sets the values of the real and imaginary parts to 0.  
We have a constructor that takes in a single double which sets the real part to the value of the double and the imaginary to 0.  
The last constructor takes in two doubles to set the real and imaginary parts.

This allows us to automatically initialize our complex numbers as so

.. literalinclude:: /lecture_code/classes2/complex1.cc
    :language: cpp


Member Functions
----------------------

We also have a set of accessors and simple operations.
For our complex type to be efficient, it is best to inline the simple operations.
For example, we can inline our constructors and operations such as :code:`+=`, :code:`imag()`.
Remember that providing member function definitions within the class definitions inlines the function by default.  

It is also possible to explicitly request inlining by using the keyword :code:`inline` in front of the function.

.. literalinclude:: /lecture_code/classes2/memberfunctions1.h
    :language: cpp

Here is an example that it makes sense to return a reference to an object.  The operators

.. code-block:: cpp
   
   a+=z;
   a-=z;
   a*=z;
   a/=z;

all return a reference to a complex object.  The reference returned uses :code:`*this` meaning
we are returning the actual complex number that calls these functions.


Const members
----------------------

Remember that :code:`const` specifies function members that do not modify the objects that invoke these functions.
Here we have the functions :code:`imag()` annd :code:`real()` which return the real and imaginary parts.
Since these functions do not modify the object it is best to specify them as :code:`const`.  This is important
when dealing with const and non-const objects.  Const functions can be called by both const and non-const objects.  
Non-const member functions can only be invoked for non-const objects. 

.. code-block:: cpp

   complex z{1,0};
   const complex cz{1,3};
   z=cz;// okay we can assign to a non-const variable
   cz=z;// not okay.... complex::operator=() is a non-const member function
   double x=z.real(); //okay complex::real() is a const member function


Helper functions
----------------------

Many operations do not need direct access to the representation of complex.  Therefore it is best to declare them
outside of class definitions.  These are considered a classes helper functions.  Here we create overload the 
standard arithmetic operators in order to allow the user to use a complex type as intuitively as possible.  

.. literalinclude:: /lecture_code/classes2/helper1.cc
    :language: cpp

Notice that here we pass by value.  This allows us to copy the arguments and modify without affecting the 
the caller's copy.  We then can use the result as the return value.  
It is important to note that each of these member functions uses the member functions defined within the 
class definition.

We can also define logical operators that help distinguish equality between two objects of our complex type.

.. code-block::cpp
   
   bool operator==(complex a, complex b)
   // equal
   {
   return a.real()==b.real() && a.imag()==b.imag();
   }
   bool operator!=(complex a, complex b)
   {
   return !(a==b);
   }
   complex sqrt(complex);
   // not equal
   // the definition is elsewhere
   //

Notice how :code:`!=` uses the definition of :code:`==`

Here is the example of the complete complex class.  You can find the code 
at /lecture_code/classes2/complex.h


.. literalinclude:: /lecture_code/classes2/complex.h
    :language: cpp

Here are some examples of how you might use the complex class.

.. literalinclude:: /lecture_code/classes2/main_complex.cc
    :language: cpp

Exercise
----------------------

You can find the above code in the file /lecture_code/classes2/main_complex.cc.

If you try and build and compile the code you will run into link time errors.  
Read the errors and then provide the missing definitions.


A Container Type
##########################

Containers are objects which hold a collection of elements.  Containers are often used
in computing when we want to store multiple objects of the same type.  Some examples 
are the built-in :code:`arrays`. The built-in arrays represents a stack allocated
block of memory holding a particular type.  The trade-off is that programs are limited 
to a finite amount of stack-memory and the sizes of these arrays must be known at compile
time.

.. literalinclude:: /lecture_code/classes2/array1.cc
    :language: cpp

We can also create dynamically allocated arrays using the :code:`new` operators.  This allows
us to define the sizes of arrays at run-time.  It also allows us to allocate memory on the heap.
The downside is that it forces us to work with pointers and we need to remember to deallocate 
our memory before we leave the scope of the pointers. 

.. literalinclude:: /lecture_code/classes2/array2.cc
    :language: cpp


In the best-case scenario, it would be great to create dynamically allocated containers without
having to work with naked pointers, forcing the user to remember to free memory.  
In the following, we will show an implementation of a Vector type that stores dynamically allocated doubles.
We will highlight some of the interface features which make using our Vector class superior to working with pointers to doubles.  

Vector
----------------------

.. literalinclude:: /lecture_code/classes2/Vector1.h
    :language: cpp

Here is our basic container class Vector.  
The representation is simply a pointer :code:`double * elem`.
This pointer will be used to point to our heap-allocated array of doubles.
We also have an :code:`int sz` which saves the size of our array. 
These are the basic components of our representation. 

:code:`Vector(int s)`
   Let's take a look at the constructor.  Here we initialize our Vector by initializing 
   our elem pointer by calling the :code:`new` operator. We also set the value of the 
   doubles to 0 by default.  This prevents us from accessing uninitialized memory.
   Here we also make sure to record the size of our Vector. 

:code:`~Vector(){delete[] elem;}`
   We also provide a destructor.  This guarantees that whenever our Vector objects
   go out of scope the memory that is stored by our Vector is automatically freed. 
   No longer does the use have to remember to free the memory using the :code:`delete` 
   operator.

:code:`double &operator[](int i){return elem[i];}`
   This function returns a reference to a double stored at the **i** position.  This
   allows us to access the arrays ith element just as you normally would when working
   with arrays.  Notice that since we are returning a reference to the double we are 
   able to both read and write to the location.

:code:`int size() const {return sz;}`
   This function allows us to get read access to the size of our Vector.  This allows 
   use to iterate over its elements without having to keep track of the size elsewhere.
   No longer should we be accessing elements outside of our array.

With all of these definitions we could use our container as in the following code.

.. literalinclude:: /lecture_code/classes2/main_vector1.cc
    :language: cpp

It's important to notice that Vector follows the same rules for naming, scope, allocation, lifetime 
as does a built-in type, such as :code:`int` and :code:`char`.  Here we have left out the necessary
error handling.  


.. note::
   Constructor/destructor combination serves as the basis of most resource management techniques in C++.
   The constructor allocates the elements and initializes the Vector members immediately.  The 
   destructor deallocates the members.  This allows us to control the lifetime of our objects as
   well as the memory our objects used.  This techniques allows us to avoid to use of naked pointers
   naked delete operations.


Initializing Containers
--------------------------


Containers exist to store elements. Therefore, we should define
convenient ways to store stuff in the containers.
With the current implementation, we can create a Vector with
an appropriate size and then assign it to them,
but there are other more elegant ways to achieve initialization.  

Here are just two standard ways:

- *Initializer-list constructor*: Intialize with a list of elements.
- :code:`push_back(double)`: Adds a new element at the end of the sequence,

These can be declared like this,


.. literalinclude:: /lecture_code/classes2/Vector2.h
    :language: cpp

The push_back() function is useful for input 
of an arbitrary number of elements.  For example:

.. literalinclude:: /lecture_code/classes2/read_vector.h
    :language: cpp


The :code:`std::initilizer_list` used to define the initializer list constructor is a standard-library type known to the compiler.  This allows us to use a {} -list, such as {1,2,3,4}.  The compiler will create a type initializer_list to give to the program. 
This allows us to write

.. code-block:: cpp

   Vector v1={1,2,3,4,5};
   Vector v2={1.23,2,5.2};

The implementation fo the initializer list constructor might look something like,

.. literalinclude:: /lecture_code/classes2/init_list.h
    :language: cpp

A Container Type
##########################

Part1
----------------------

In the lecture code you will find a backbone code for hw2 part2.  

The solution uses a class :code:`SpherePoint` representing a point
on the unit sphere.  

I have written the declarations required to build to code.

You need to implement the function defintions in order to run the code
and complete the assignment.

Part2
----------------------

Instead of working with a naked pointer to a SpherePoint create
a class RandomSpherePointVectors.  

Constructor should take in an int N rand return a RandomSpherePointVectors
of size N

