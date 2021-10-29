.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec_Templates_:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec_Templates_:

Class Summary and What is next
################################

So far, we have used learned how to develop our classes in C++.
We are now able to define the types that are specialized for our particular problems.
Next, we discussed the different types of lessons we can design.

- Concrete Types: contains the representation

    - Arithmetic 

        - complex

    - Containers

        - Vector
- Abstract Types: includes the representation

    - Serves as a base class
    - Defines a standard interface for all derived classes
- Derived Types

We showed some implementations for practical classes that can serve as a basis for any of the types you use in the future.
Next, we talked about the essential operators of all C++ types.
These operations deal with an object's lifetime as well as resource management.
We showed how to implement copy and move operations for a container class.
Again this serves as a design basis for how to create containers that manage resources like memory safely and efficiently. 

Now that we have an idea of how to create a good class in C++, the next step is how we can write more general code.
In other words, we can design types like a complex or Vector, but one limitation is that the representation only uses doubles.
In reality, the concept of a Vector being a container that holds a set of something is much more general.
What if we wanted to create a Vector that contains :code:`int` or that contains a :code:`SpherePoint`.  

Consider creating a Vector that held :code:`ints`.
Notice that all the operations that are defined in double should work for our VectorInt.
It is possible to copy and paste the code and replace all the instances where we use double with int.  Lets do that:

.. admonition:: Exercise: Write int Vector

    - Go to the code /lecture_code/templates/Vector/Vector0.h
    - Write a class declaration for a Vector that holds :code:`ints`
    - Save the class in VectorInt.h
    - Test both the original code and the new code


But then what if we wanted a Vector of complex numbers?  Again we can copy and paste.
If you go through writing the code, you will notice that all of the patterns are the same.
So how can we prevent writing the same way multiple times?  We need a method to generalize our code.
C++ provides a syntax that allows us to generalize our code.

.. admonition:: Exercise: Write complex Vector

    - Go to the code /lecture_code/templates/Vector/Vector0.h
    - Write a class declaration for a Vector that holds :code:`Complex`
        - :code:`complex` is defined in /lecture_code/templates/Complex/Complex.h
    - Save the class in VectorComplex.h
    - Test both the original code and the new code in a main file


Templates
########################

Template
    A **class** or **function** that we parameterize with a set of **types** or **values**
    

Parameterized Types
_______________________

In the following we are going to describe how we can parameterize types.  We will
show how to parameterize our Vector of doubles class into a Vector that can hold 
any type :code:`T`.

.. admonition:: Example: Parameterize Vector Class

    - Go to the code /lecture_code/templates/Vector/VectorT.h
    - Add line :code:`template<typename T>` above class definition
    - Replace representation :code:`double *` with :code:`T *`

Notice a few things:

    - first line :code:`template <typename T>` defines a template class or function

        - :code:`template<typename T>` makes T a parameter of the :code:`Vector` declaration
    - Our representation has changed

        - :code:`T* elem` 
        - We are now pointing to an array of type :code:`T`
        - :code:`int sz` remains the same.

This is C++'s version of the mathematical "for all type T".

.. note:: 
    Using :code:`class` to introduce a type parameter is equivalent to using :code:`typename`

Lets now define member functions:

.. admonition:: Example: Parameterize Vector Class Member Functions

    - Go to the code /lecture_code/templates/Vector/VectorT.cc
    - Replace representation :code:`double *` with :code:`T *`

Lets use our new parameterized Vector class.

.. admonition:: Example: Using Vector Class 

    - Go to the code /lecture_code/templates/Vector/mainVectorT.cc
    - define three different types of Vectors

        - :code:`Vector<int>`
        - :code:`Vector<double>`
        - :code:`Vector<complex>`
    - print the vectors
            
            
Using our Vector Class
````````````````````````````````

Here are some examples using our vector template class.  
The first example is using our vector to hold strings.

.. literalinclude:: /lecture_code/templates/Vector/write_string_vector.cc
    :language: cpp

Here we have two functions.  The first function returns a :code:`Vector<string>`
by passing in a string and breaking up each word in the string.

The second function prints our :code:`Vector<string>` by looping with the :code:`size()` function.    

Supporting range-for
````````````````````````````````

We can support the range-for loop by defining :code:`begin()` and :code:`end()` functions.
These functions need to point to the first element and one past the last element of our 
:code:`Vector<T>`.

.. literalinclude:: /lecture_code/templates/Vector/write_string_vector2.cc
    :language: cpp

- This example shows how we can write :code:`begin()` and :code:`end()` functions
- We declare const to insure that we only get read access.
- We can declare non-const versions of begin and end


.. admonition:: Example: Non const begin and and end functions

    - Start in `write_string_vector2.cc`
    - Write a function that changes each string in the vector to your name
    - Use range-for loops by providing necessary non-const begin and end functions
  
.. admonition:: Example: begin() and end() member functions

    - Add begin and end functions to `VectorT.h`
    - Hint: You will need to return :code:`&this`


Notes
``````````````````````````````````````````````````````````
We can define all types of generic data structures using the template syntax.
On your own you should try to implement your own version of each of these:

- lists
- vectors
- maps and unordered maps

.. note:: 
    - Templates are a compile time mechanism

        - No run time overhead
        - :code:`Vector<double>` is the same as the original :code:`Vector`
    - Template plus a set of template arguments is called an *instantiation* or *specialization*
    - You cannot separate template class definitions from declarations


.. admonition:: Exercise: HW Part 2 using Vector<T>

    - Use our new Vector type that we have define to try and create a Vector<SpherePoints>
    - Find the max and min arc distances of :code:`N` points on the Sphere
    - Start in `/Vector/sphere_point.cc`
    - You will need to rewrite the generate function



Value Template Arguments
____________________________

- Instead of **types** templates can also take **values**
- Here is an example of a Buffer of variable size

.. literalinclude:: /lecture_code/templates/buffer/buffer.cc
    :language: cpp

- Useful for creating arbitrary sized buffers on the stack
- template value arguments must be a constant expression

    - Evaluated at compile time


Parameterized Operations
____________________________

- Templates can be used to parameterize operations.
- An operation can be parameterized by a type or a value
- 3 ways to parameterize an operations

    - A function template
    - A function object: Object that carries data but is called like an object
    - A lambda expression: A shorthand notation to a function object


Function Templates
____________________________

Example: Write a function that calculates the sum of the elements of any sequence that a range for
can traverse.





Function Objects
____________________________

Example: Less than function object

.. literalinclude:: /lecture_code/templates/operations/Less_than.cc
    :language: cpp

- Above is a function object.
- Notice the constructor takes in a value of type T
- We have a call operator


.. admonition:: Using the Less than Function

    - Begin in the file :code:`/lecture_code/templates/operations/Less_than.cc`
    - Create 3 template specializations comparing

        - strings
        - ints
        - doubles
    - Use your function objects

Function Objects are often used as arguments to algorithms.

.. admonition:: Example: Count occurrences of value for which predicate returns true

    - A predicate is function that returns true or false
    - Look in the file :code:`/lecture_code/templates/operations/count.cc`
    - We created function count that takes in a container and predicate

        - C needs to be able to use range-for
        - P needs to be callable and return boolean
    - Here we pass in our Less_than<T> function as the predicate

.. literalinclude:: /lecture_code/templates/operations/count.cc
    :language: cpp


Lambda
____________________________