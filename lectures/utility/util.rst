.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec13:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec_Input_Output_:


Utilities
#################################################

Here we will go over a helpful set of components in the C++ language.
These components are not like the standard features such as the containers and algorithms.
Instead, these components serve as tools that help us design our programs or modify the usages of our programs.

Resource Management
#################################################

A critical task in programming is to manage resources properly.
A resource is something that is acquired and later released.
Examples can be memory, locks, sockets, thread handles, and file handles.
Failing to release a resource can cause a leak a degrade the performance of our application.

The standard library components are designed not to leak resources.
They use constructor/destructor pairs to ensure that a resource does not outlive an object responsible for it.
An example of this is the standard library :code:`vector`.
Vector is an example of an object which acquires resources when defined in scope and releases the resource
when the object's scope is left.

unique_ptr and shared_ptr
#################################################

What can we do about objects that are defined on the free store?  In :code:`<memory>` the
standard library provides two "smart pointers" to help manage the lifetime of objects on
the free store:

1. :code:`unique_ptr` to represent unique ownership
2. :code:`shared_ptr` to represent shared ownership

The most basic use of the smart pointers is to prevent memory leaks.

.. literalinclude:: code/example1.cpp
    :language: cpp

.. admonition:: Question

    - What happens to the memory pointed to by :code:`p` if
    - We can how much memory is lost using `valgrind <https://www.cs.tufts.edu/comp/15/reference/valgrind.shtml>`_




Remember, when we define an object on the free store using the :code:`new` operator, we must ensure that the object is deleted before we leave the scope of the pointer.
Here we do not delete :code:`p` if :code:`i<99` or :code:`j<77`.
:code:`unique_ptr` ensures that the object is destroyed whichever way we
exit :code:`f()`.

Another possible use of :code:`unique_ptr` is in passing free_store allocated
objects in and out of functions:  Recall how we can return arrays from a function.

.. admonition:: memleak.cpp

    - We have a function that returns a pointer to an integer
    - We create a heap allocated array of size s
    - We return a pointer to that memory location
    - Notice that we always need to the delete the allocated memory somewhere.
    - What is output of the program showing?


.. literalinclude:: code/memleak.cpp
    :language: cpp
    :linenos:

.. admonition:: Why don't we return a pointer to a locally allocated array?

    - replace line 6 with line 5
    - What is the output?

.. admonition:: memleak_sol.cpp using :code:`unique_ptr`

    - We can cast the assign the unique_ptr to our memory using a static_cast
    - Notice we do not explicitly call delete in either the function or in main
    - Notice how we access the elements of the array.
        - :code:`ptr.get()` returns a pointer to the managed object or null if no object is owned.
    - What if deleted the memory by calling delete on :code:`a`?

.. literalinclude:: code/memleak_sol.cpp
    :language: cpp
    :linenos:

.. admonition:: memleak_sol_2.cpp using :code:`unique_ptr<T[]>`

    - If we know that our pointer points to an array we can declare that fact.
    - We can create a unique pointer of type :code:`unique_ptr<T[]>`
    - This way the pointer will behave like an array as usual.

.. literalinclude:: code/memleak_sol2.cpp
    :language: cpp



The :code:`shared_ptr` is similar to :code:`unique_ptr` except :code:`shared_ptr` s are copied rather than moved.
The :code:`shared_ptr` s for an object share the ownership of an object; that object is then destroyed
when the last of its :code:`shared_ptrs` is destroyed.

.. admonition:: shared.cpp :code:`shared_ptr<T>`

    - We create shared pointer :code:`fp`
    - The pointer can be copied freely
    - file handle will be closed when the last copy of the pointer is destroyed

.. literalinclude:: code/shared.cpp
    :language: cpp


make_shared and make_unique
############################

Creating an object on the free_store and then passing the pointer to a smart pointer is a bit
verbose.  Instead we can initialize using the functions :code:`make_shared()` and :code:`make_unique`.

.. admonition:: make_ptr.cpp :code:`make_unique<T>` :code:`make_shared<T>`

    - We defined a class :code:`S`
    - We can automatically create the objects on the heap using :code:`make_shared` or :code:`make_unique`
    - I believe :code:`make_unique` is a C++ 20 feature so you may need to compile with the -std=C++20 flag

.. literalinclude:: code/make_ptr.cpp
    :language: cpp

.. admonition:: Microsoft smart pointer links

    - `Smart Pointers <https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170>`_
    - `Unique Pointers <https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170>`_
    - `Shared Pointers <https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170>`_

move()
############################

We can use :code:`std::move()` if we would like to specify a move operation instead of a copy.
This is helpful when dealing with :code:`unique_ptr` s because unique_ptr is the sole owner of a
copy.  Therefore, the object most be moved.

.. admonition:: move.cpp

    - We can not copy assign a unique pointer
    - What is error?

.. literalinclude:: code/move.cpp
    :language: cpp

In order to change ownership one must move the pointer explicitly.

.. admonition:: move1.cpp

    - We can move the unique_ptr
    - What is the state of p after the move?

.. literalinclude:: code/move1.cpp
    :language: cpp

.. admonition:: What does :code:`move()` do?

    - :code:`move()` doesn't actually move anything.
    - Instead, it casts the argument to an rvalue reference indicating that argument will not be used again and therefore maybe moved.
    - You can think of :code:`move()` as an :code:`rvalue_cast`.

.. admonition:: swap_move

    - Move exists to serve a few essential cases.
    - For example in a simple swap

.. literalinclude:: code/swap_move.cpp
    :language: cpp

Timing our code
############################

How can we time our code?

:code:`<chrono>` provides the standard library components which deal with time.

.. admonition:: time.cpp Basic timing

    - We can time code using :code:`<chrono>` library
    - Here is the basic pattern for timing


.. literalinclude:: code/time.cpp
    :language: cpp

.. admonition:: swap_time.cpp Timing swap move versus swap copy

    - We can use this test difference between swapping with move and swapping with copy.
    - Here we are testing the time difference between swaping vectors of increasing sizes
    - What do you find when you test to code?

.. literalinclude:: code/swap_time.cpp
    :language: cpp

Function Adaptation
############################

When passing a function as a function argument, the type of the argument must
exactly match the expectations expressed in the called functions declarations.
If the intended argument "almost matches expectations", we have three ways
to adapt the function

- Use a lambda
- Use :code:`std::mem_fn()`
- Define the function to accept a :code:`std::function`


Lambda as Adaptors
############################

.. admonition:: lambda_adaptar.cpp (i know i misspelled it)

    - This code relies on the shape class defined in Shapes.h
    - We want to use the :code:`for_each` function to call each shapes draw function
    - :code:`for_each` uses the :code:`f(x)` syntax
    - Since our vector holds a set of pointers to different shapes we need to use the :code:`x->f(x)` to call the draw function.
    - We can use a lambda function to fix the notation.

.. literalinclude:: code/lambda_adaptar.cpp
    :language: cpp


mem_fn()
############################

.. admonition:: mem_fun.cpp
    - Given a member function, the function adaptor :code:`mem_fn(mf)` produces a function object that
can be called as a nonmember function.
    - Here is the same draw example using mem_fn()

.. literalinclude:: code/mem_fn.cpp
    :language: cpp

function
#################

The standard-library :code:`function` is a type that can hold any object you can invoke using the call operator :code:`()`.

That is, an object of type :code:`function` is a function object. For example:

.. code-block::

    int f1(double);
    function<int(double)> fct1{f1};

    int f2(string);
    function fct2{f2};

    function fct3=[](Shape* p){p->draw();};



.. admonition:: Draw example with function

    - modify the draw all example to use :code:`function`


Type Functions
#################

A **type function** is a function that is evaluated at compile time that
is given a type as its argument or returning a type.  The standard
library provides type functions that help programmers take advantage of
aspects of the language.

.. admonition:: numeric_limits numerics.cpp

    For numerical types, :code:`numeric_limits` from :code:`<limits>` presents a variety
    of useful information for programming.  In the examples we investigate some of the
    useful properties of our types.  Notice that that input argument is placed as a
    type within the :code:`<>` brackets.  For more information check the `CPP Reference <https://en.cppreference.com/w/cpp/types/numeric_limits>`_

.. literalinclude:: code/numerics.cpp
    :language: cpp

Type functions are a part of C++ that allow for compile-time computation that allow
for better type checing and better performance.  The use of type functions is often
called metaprogramming or template metaprogramming.  We will go over two of the standard
library featuers :code:`iterator_traits` and **type predicates**.



:code:`iterator_traits`
#########################

In this example we will show further generalize the standard algorithm sort function using
the :code:`iterator_traits` type function.

.. admonition:: sort_original.cpp

    We begin with this template wrapper of the sort function that allows to sort
    containers without having the user have to specify the :code:`begin()` and :code:`end()`
    iterators.  The standard library takes a pair of iterators which define the sequence.
    Additionally, those iterators must offer random access to that sequence, meaning that
    they must be *random-access iterators*.

    This fact will invalidate our template sort function for any containers that do
    not provide *random-access iterators*.  One such example is the :code:`forward_list`
    The :code:`forward_list` is a singly-linked list so there is not reasonable way of
    referring back to the previous element.  For this reason we can not just use
    our :code:`sort` function on a :code:`forward_list`.

    Try compiling :code:`sort_original.cpp`.

.. literalinclude:: code/sort_original.cpp
    :language: cpp

The standard library provides a mechanism, :code:`iterator_traits`, that allow us to
check which kind of iterator is provided.  With :code:`iterator_traits` we can improve
the range :code:`sort()` to either accept a :code:`vector` or a :code:`forward_list`.

For example

.. code-block:: cpp

    void test(vector<int> &v , forward_list<double> &lst){
        sort(v);
        sort(lst);
    }

Here i will show the technique that makes this work and can be used in other examples.


.. admonition:: sort_iterator_traits.cpp

    First, we write two helper functions that take an extra argument which indicates whether they
    are used for random-access iterator or forward iterators.

    - The one for random-access iterators is trivial it simply just passes the begin and end iterators.
    - The version for forward iterators copies the list into a vector, sorts, and then copies back.

    :code:`Value_type<For>` is the type of :code:`For` 's elements, called its value type.
    Every standard-library iterator has a member :code:`value_type`.  We get the :code:`Value_type<For>`
    syntax by defining the type alias above the function.

    For a :code:`vector<X>`,:code:`Value_type<X> is :code:`XP`.

    The most important part of the code is in the selection of which helper function to use.
    This is done in the :code:`sort` function which uses two different **type functions**.
    The first is :code:`Iterator_type<C>` which returns the iterator_type of :code:`C` that is
    :code:`C::iterator`
    The second is :code:`Iterator_catergory<Iter>{}` which constructs a "tag" value indicating the
    kind of iterator provided:

    - :code:`std::random_access_iterator_tag` if :code:`C` s iterator supports random access
    - :code:`std::forward_iterator_tag` if :code:`C` s iterator supports forward iterations

    Given that, we can select between the two sorting algorithms at compile time.

.. literalinclude:: code/sort_iterator_traits.cpp
    :language: cpp

This technique is called **tag dispatch** and is one of several used in the standard library and elsewhere
to improve flexibility and performance.


.. admonition:: Extending tags for types without member types.

    We can extended this functionality for types without member types, such as pointers, the standard-library
    supports for tag dispatch comes in the form of a class template :code:`iterator_traits` from
    :code:`<iterator>`.  The specialization for pointer looks like this:

.. literalinclude:: code/iterator_pointer.cpp
    :language: cpp

With this definition, an :code:`int*` can be used as a random-access iterator despite not having to
a member type; :code:`Iterator_category<int*>` is :code:`random-access_iterator_tag`;

Type Predicates
#########################

In :code:`<type_traits>` the standard library offers simple type functions, called **type predicates**.
These answer fundamental questions about types.  For examples

.. code-block:: cpp

    bool b1=std::is_arithmetic<int>(); // yes, int is an arithmetic type
    bool b1=std::is_arithmetic<string>(); // no, string is not an arithmetic type

Other examples include

- :code:`is_class`
- :code:`is_pod`
- :code:`is_literal_type`
- :code:`has_virtual_destructor`
- :code:`is_base_of`

:code:`enable_if`
#########################

The obvious way of using **type predicates** includes conditions for :code:`static_asserts`, compile_time assertions
ifs, and :code:`enable_if` s.  The standard-library :code:`enable_if`  is a widely used mechanism
for conditionally introducing definitions.


.. admonition:: smart_pointer.cpp Defining a smart pointer type

    Consider defining a smart pointer.  We have a situtation where the pointer
    :code:`operator->()` should only work if the template argument is a class.

    .. code-block:: cpp

        template<typename >
        class Smart_pointer{
        // ...
        T & operator*();
        T & operator->();// should only work if and only if T is a class
        };

    The :code:`->` should be defined if and only if :code:`T` is a class type.  For examples
    :code:`Smart_pointer<vector<T>>` should have :code:`->` , but :code:`Smart_pointer<int>` should not.

    We cannot use a compile-time :code:`if` because we are not inside a function.
    Instead, we write

    .. literalinclude:: code/smart_pointer.cpp
         :language: cpp
