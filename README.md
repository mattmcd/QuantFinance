Derivatives Pricing
====================
Examples and exercises from Mark Joshi's books "C++ Design Patterns and
Derivatives Pricing" (1st ed), and "The Concepts and Practice of Mathematical Finance" (1st ed).

The main purpose of this project is to brush up on my C++ programming and see how the new 
features in C++11 can be used to simplify the original version of the code.

Notes
-----

- The PayOff class represents the pay off of an option whose value depends only on the 
  spot price.
- The VanillaOption is primarily used as an example of memory management in C++.
  This class stores a PayOff object and the time to expiry, the latter being used
  to discount the expected pay off under the risk neutral measure.  In Chapter 4 of
  CDPaDP the VanillaOption class starts out as storing a reference to the PayOff. 
  The limitations of this approach are presented, mainly that shared ownership leads
  to possibility of error due to multiple objects modifying the PayOff.  
  A solution using pointers and a bridge class to handle memory management is presented.
  (Declaring the PayOff to be const may be another solution).  The key point is
  the 'Rule of 3' i.e. if you overload any of the copy constructor, assignment or destructor
  methods you will probably need to overload all of them.  Note that in C++11 there are
  also the move constructor and move assignment functions to consider, although
  smart pointers can help reduce required code.
- The Wrapper class uses template programming to handle the memory management. 
