.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec7:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec_Essential_Operations_:

Essential Operations
########################

In the last class, we discussed the notion of three different types of classes—concrete, abstract, and classes in class hierarchies.
We discussed some of the aspects to consider when defining each of these types of classes.
In this lesson, we will discuss some of the fundamental operations that we must reason about regardless of the type of class we are trying to define.
These operations are known as essential operations. 

In the first half of the class, we will discuss the operations related to object lifetime.
These operations are known as the special member functions, and we will discuss these functions in great detail. 

In the second half, we will consider some conventional operations that we might want to define for our classes.
We will demonstrate how to define these operations and some of the advantages in defining these operations for our classes.  

Introduction
########################

In C++, we need to consider a set of essential operations that control the lifetime of our objects.
These operations include construction, destruction, initialization, assignment, and copy and move.
If we do not define these operations on our own, C++ will provide defaults for us.
However, we should be aware of these operations when we design our own types.
Often, we can allow the compiler to write these defaults.
Still, usually, when your class is a resource handle, i.e.
, manages some heap-allocated data, we need to define the complete set of operations.  


Here is the complete set of special member functions that we can define.

.. literalinclude:: /lecture_code/essential_operations/essential1.cpp
    :language: cpp

In the following we will talk about the usages of each of these operations and how to correctly 
write each for our types.

Construction, Destruction, Copy and Move
===============================================

There are five situations in which an object can be copied or moved.

- As the source of an assignment
- As an object initializer
- As a function argument
- As a function return value
- As an exception

An assignment uses a copy or move assignment operator.

.. code-block:: cpp

   class x{
   public:
      X(Sometype);
      X& operator=(const X&); // copy assignment:
      X& operator=(X&&); // move assignment


In principle, the other cases use a copy or move constructor.
However, a copy or move constructor invocation is often optimized by constructing the object to initialize right in the target object.
So instead, the compiler will just call the constructor in the memory location of the object.
For example:

.. literalinclude:: /lecture_code/essential_operations/eliding_copy.cpp
    :language: cpp

Example: /lecture_code/essential_operations/**eliding_copy.cpp**

You can test go ahead and test this code.

We might expect that calling :code:`f()` or :code:`g()` will construct an object of type :code:`X` 
and return the object by copying this local object into :code:`x` or :code:`y`.  As you
will see the compiler will optimize away the copy just constructing the object in :code:`x`.


In addition to the initialization of named objects and of objects on the free store, constructors are used 
to **initialize temporary objects** and to implement **explicit type conversion**.

C++ guarantees that objects can be copied and moved.
The compiler will generate these special member functions by default.  If you want to be explicit 
about generating the default implementations you can add the keyword :code:`= default`


.. literalinclude:: /lecture_code/essential_operations/default_members.cpp
    :language: cpp

- If you are explicit about some defaults, other default definitions will not be generated

.. literalinclude:: /lecture_code/essential_operations/special_members.cpp
    :language: cpp

- When you create a class with a pointer member it's probably best to be explicit about copy and move operations.
- Pointers may point to something that the class must delete in which case the default memberwise copy would be wrong
- It can also point to something that one must not delete.

.. literalinclude:: /lecture_code/essential_operations/copy_pointer.cpp
    :language: cpp

Example: /lecture_code/essential_operations/**copy_pointer.cpp**

A good rule of thumb (sometimes called the rule of zero) is to either define all the essential operations or none
using default for all).  For example.

.. code-block:: cpp

   struct Z{
      Vector v;
      string s;
      };

   Z z1; // default initialize z1.v and z1.s
   Z z2=z1;// default copy z1.v and z1.s

Here the compiler will synthesize memberwise default construction, copy, move and destructor as needed, 
and all with the correct semantics.

:code:`= delete`
   Just as we can be explicit about wanting a default implementation we can also be explicit about insuring that 
   an a special member function not be generated by the compiler.


A base class in a class hierarchy is an example where we would not want to allow a memberwise copy.
For example

.. literalinclude:: /lecture_code/essential_operations/delete_operator.cpp
    :language: cpp

- :code:`=delete` makes any use of a deleted function a compile-time error; 
- can be used to suppress any function, not just essential member functions.



Conversions
===============================================

A constructor that takes a single argument defines a conversion from its argument type.
For example, :code:`complex` provides a constructor from a :code:`double`:


.. literalinclude:: /lecture_code/essential_operations/complex.h
    :language: cpp

We can use this constructor as so:

.. code-block:: cpp

   complex z1=3.14;// z1 becomes {3.14,0.0}
   complex z2=z1*2;// z2 becomes z1*{2.0,0}=={6.28,0}

This implicit is sometimes okay but not very every type.  Especially for types such as
Vector.

.. literalinclude:: /lecture_code/essential_operations/Bector.cpp
    :language: cpp

In order to avoid this implicit conversion we need to use the keyword :code:`explicit`.

.. literalinclude:: /lecture_code/essential_operations/Bector1.cpp
    :language: cpp

You should use :code:`explicit` for constructors that take in a single argument.

Member Initializers
===============================================

When a data member of a class is defined we can supply a default initializer called a default member initializer.

.. literalinclude:: /lecture_code/essential_operations/complex1.h
    :language: cpp

Notice how we set the default members to zero and we can use those defaults in our constructors.
The default value is used wherever we don't provide a value.  


Copy and Move
===============================================


C++ allows objects to be copied by default.  This is true for user-defined types and built-in types.
The default for copying is memberwise copy: copy each member. For example when we use the 
complex class.


.. literalinclude:: /lecture_code/essential_operations/complex_copy_test.cc
    :language: cpp

At the end all the complex numbers will have the same values because the initialization and the assignment 
copies all members :code:`re` and :code:`im`.

We we create our own types we need to consider how our objects may be copied in a typical usuage case.
- When they are copied by value in a function call
- or when they are initialized
- or when they assigned

For some concrete types such as :code:`complex` memberwise copy makes perfect sense.  For other 
concrete types like a container such as :code:`Vector`, memberwise copy is a bad idea.  
For abstract types memberwise copy is most likely never right.


Copying Containers
===============================================

Classes that are manage objects through a pointer should not use default memberwise copying.

Consider the case of copying a Vector.

.. literalinclude:: /lecture_code/essential_operations/bad_copy.cc
    :language: cpp

If we do a memberwise copy we will copy the pointer therefore both Vectors will
point to the same memory.  If we want to avoid this situation we need to define
better copy operations.

If we want to define copying of an object we need to define two members:

1. a copy constructor
2. a copy assignment

Consider a vector class

.. literalinclude:: /lecture_code/essential_operations/Vector_copy.cc
    :language: cpp

A proper copy constructor for our Vector class should:

1. allocate space for the required elements
2. Copy the the elements into the new space
3. Make sure you save the size.


.. literalinclude:: /lecture_code/essential_operations/Vector_copy_constructor.cc
    :language: cpp

We also need to define a copy assignment operator:


.. literalinclude:: /lecture_code/essential_operations/Vector_copy_assignment.cc
    :language: cpp

The copy assignment is a bit more complex:

1. it allocates new memory for the copy
2. Then it copies the elements into the new space
3. Then it deletes the memory the object currently points to.
4. sets elem to the new pointer
5. sets the new size
6. returns this object


Moving Containers
===============================================

Often when dealing with containers we would like to avoid the cost 
of copying all the values inside a container.  We can avoid the 
cost of copying when we pass values by reference but we can't 
return a reference to a local object as a result of a function.

Consider:


.. literalinclude:: /lecture_code/essential_operations/Vector_add.cc
    :language: cpp

When we return from a :code:`+` we are copying the result out of the local variable
and into some place where the caller can access it. 

- In this code we would be copying :code:`Vector` twice.  
- Once for each call to :code:`+`. 
- :code:`res` is never used after the copy.

What we really wnat is to move a :code:`Vector` rather than copy it.  
We can do this by defining move constructors and assignments as follows

.. literalinclude:: /lecture_code/essential_operations/Vector_assignment1.h
    :language: cpp


By giving these definition the compiler will choose to use the move constructor to transfer
values out of a function.  That means that :code:`r=x+y+z` will involve no copying of Vectors.
Instead, :code:`Vector` s are just moved.

A typical definition of move is as follows. 

.. literalinclude:: /lecture_code/essential_operations/Vector_move.cc
    :language: cpp

- :code:`&&` means "rvalue reference" and is a reference we can bind an rvalue.
- The word "rvalue" complements "lvalue", which means something that can appear on the left hand side of an assignment operations.
- Another way to put is that it is variable with a memory location.

.. code-block:: cpp

   x=2;
   x=f();

- An rvalue is a value that you can't assign to.
- An rvalue reference is a reference that nobody else can assign to

   - Therefore we can "steal" its value. 
- The :code:`res` local variable in :code:`operator+()` for :code:`Vector` s is an example

- Notice that a move constructor does not take a :code:`const` argument.  
  
   - The move is suppose to remove the value from its argument.  

- A move operation is applied when an rvalue reference is used as an initializer or as the right-hand side of an assignment.
- After a move, a moved-from object should be in a state that allows a destructor to be run
- We can also allow assignment to a moved from object.
- The standard-library algorithms assumes that 
- Our vector does that.

   - We can can assign to our :code:`Vector`
  
When we know a value wont be used again and we want to force a move when there might be a copy we can used
:code:`std::move()`.  For example:


.. literalinclude:: /lecture_code/essential_operations/move_example.cc
    :language: cpp

The standard-library function :code:`move()` doesn't actually move anything.  It simply returns a reference to its argument.

Exercise
_______________

Define the move assignment operations for the Vector class.
Example: /Vector_move_assignment.cc

.. literalinclude:: /lecture_code/essential_operations/Vector_move_assignment.cc
    :language: cpp


Resource Management
===============================================

By defining constructor, copy operations, move operations, and a destructor we are 
able to completely control the lifetime of a contained resource.  For example, 
we are able to control the life time of heap allocated resources.  By providing
a mve constructor we are also able to move objects from scope to another simply
and cheaply.  This limits unwanted and unnecessary copying from scopes.

In most cases designing a resource handle such as :code:`Vector` is superior 
to working with raw pointers in application code.  By doing so, we eliminate
the use of :code:`new` and :code:`delete` from our code and prevent resource leaks. 
In many other programming languages resource management is doing using a garbage collection 
scheme.  Garbage collection is global memory management scheme.  Although C++ offers a 
garbage collection interface that allows us to plug in a garbage collector it is recommended
to design resource safe *resource handles*.

The recommended design to to let each resource have an owner is some scope and by default
be released at the end of the owners scope.  In C++ this is known as RAII (Resource 
Acquisition is Initialization).  Resources are moved from scope to scope with 
the use of move semantics.  

RAII can be summarized as follows:

- encapsulate each resource into a class, where

  - the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done,
  - the destructor releases the resource and never throws exceptions;
- always use the resource via an instance of a RAII-class that either

   - has automatic storage duration or temporary lifetime itself, or
   - has lifetime that is bounded by the lifetime of an automatic or temporary object

Move semantics make it possible to safely transfer resource ownership between objects, across scopes, and in and out of threads, while maintaining resource safety.

You can read more about RAII and resource management `here <https://en.cppreference.com/w/cpp/language/raii>`_.


Conventional Operations
===============================================

Some operations we define for a class should have conventional meaning.  
Other libraries most notably the standard library assumes that 
these operators have conventional meaning.  By defining 
operations with conventional meaning we can take advantage of many
of the standard library features.  
Here is a list of operations you may want to define for your own types:

- Comparison: :code:`==`, :code:`!=`, :code:`>`, :code:`<` and :code:`>=`
- Container operations: :code:`size()`, :code:`begin()`, and :code:`end()`
- Input and output operations: :code:`>>` and :code:`<<`
- User-defined literals
- :code:`swap()`
- :code:`hash<>`


Comparison
_______________

The meaning of equality comparison (:code:`==` and :code:`!=`) is related to the notion of copying.

After a copy, the copies should compare equal:

.. code-block:: cpp

   X a=something;
   X b=a;
   assert(a==b); // if a!=b then something is really weird

When defining :code:`==`, also define :code:`!=` and makes sure that :code:`a!=b` means :code:`!(a==b)`.

Similarly, if you define :code:`<`, also define :code:`<=`, :code:`>`, :code:`>=`, and make sure that
the following equivalences hold.  

- :code:`a<=b` means :code:`(a<b)||(a==b)` and :code:`!(b<a)`
- :code:`a>b` means :code:`(b<a)`
- :code:`a>=b` means :code:`(a>b)||(a==b)` and :code:`!(a<b)`



Container Operations
______________________

It's always a good idea to try and design your own containers in the style of the 
standard-library containers.  In a future class we will go over the standard library containers.

Your containers should:

- resource safe by implementing it as a handle with the appropriate essential operations
- should know their own size by implementing a :code:`size()` function

This allows us to write code like:

.. code-block:: cpp

   for(size_t i=0;i<c.size();++i)
      c[i]=0;

Instead traversing containers using indices from :code:`0` to :code:`size()` we
can also use a pair of iterators.  

.. code-block:: cpp

   for(auto p=c.begin();p!=c.end();++p)
      *p=0;
   
- Here :code:`c.begin()` is a iterator that points to the first element
- :code:`c.end()` points to one past the last element.
- Iterators are like pointers

   - Support :code:`++` to move to the next element
   - Use :code:`*` to access the value of the element pointed to.  

Iterators are used in the standard algorithms library.

For example:

.. code-block:: cpp

   sort(v.begin(),v.end())

Works for any container that provides the :code:`begin()` and :code:`end()`.

Another way to traverse a container is by using the range-for loop:

.. code-block:: cpp

   for(auto& x:c)
      x=0;

This uses :code:`begin()` and :code:`end()`.


We will discuss how to define all of these in a future class.







  
