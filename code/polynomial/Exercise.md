# Exercises

For the following begin by creating an executable using
`Cmake` or `Make`


## 1. Polynomial

Write a class for polynomials that should at least contain:

- A constructor giving the degree of the polynomial;
- A dynamic array/vector/list of double to store the coefficients
- A destructor; and
- An output function for ostream

## Move Assignment

- Write a move assignment operator for the polynomial class.
- Define a copy constructor as **default**.
- Test whether your assignment is used to write a function
  polynomial `f(double c2,double c1,double c0)` takes three
  coefficients and returns a polynomial.
- Print out a message in your move assignment or use a debugger to
  make sure that the move assignment is used.

## Initializer List

- Expand the program with a constructor and an assignment operator for an initializer list.
- The degree of the polynomial should be the length of the initializer list minus one afterward.

```cpp
//input std::initializer_list<double> l
// output Polynomial
// We can use std::copy to copy the elements of l into our polynomial
```

## Implementing polyval std::for_each

In **Matlab** you can find the function `polyval()`. which evaluates a polynomial
for a given value `x`.  For example, to evaluate the polynomial $p(x)=x^2-1$ we first
express the polynomial using the array `[0,-1,1]`.  To evaluate we use p(x)=0 we can write 
`polyval([0,-1,1],1)`.  

- Write your own version of polyval that takes in a double and returns the evaluated double. 
- Write a second version which takes in a set of x values and returns a vector 
  - Try using std::algorithms for_each

## write an addition which adds two polynomials.

## Input and Output for Polynomial

1. Overload the << operator for output have the format look similar to matlab

```cpp

Polynomial p1{1,2,4};//4x^2+2x^1+1x^0
cout<<p1;
```

should output 

```console
[ 1 2 4 ]
```

2. Overload the input operator to read polynomials in the same form as above.
3. Test your code by writing polynomials to a file and reading polynomials from a file


## Implementing Math functions

- Implement functions that add two polynomials 
- Implement functions that subtract two polynomials
- Implement function that multiplies two polynomials

## Writing Tests Using Catch2




