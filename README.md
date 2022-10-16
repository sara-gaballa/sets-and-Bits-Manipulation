# sets-and-Bits-Manipulation.
1 Part 1: Basic Bit Operations
You have to implement 4 bits operations, so your programe might allow user choose one of the
following operations.
1. getBit(int number, int position):This function returns the bit value (an integer, 0 or
1) in the number at position position, according to its binary representation. The least
significant bit in a number is position 0.
2. setBit(int number, int position):This function set the bit value ( to be 1) in the
number at position position, according to its binary representation. The least significant
bit in a number is position 0 and return number after setting the bit.
3. clearBit(int number, int position):This function cleat the bit value ( to be 0) in the
number at position position, according to its binary representation. The least significant
bit in a number is position 0 and return number after clearing the bit.
4. updateBit(int number, int position, boolean value):This function set the bit value
according to value parameter(an integer, 0 (false) or 1(true) in the number at position
position, according to its binary representation. The least significant bit in a number is
position 0 and return number after update .
2 Part 2: Sets Operations using Bits manipulation
Write a program that takes
1. An input a list of strings as a Universe
2. Then takes another input a number of sets (that are subsets of the universe)
3. Then ask the user about the operations they want to perform (3 required features to be
implemented in this assignment):
(a) Union of two sets.
(b) Intersection of two sets
(c) Complement of a set
3 Part 3: Applications for bits manipulation
1. Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one. You must implement a solution with a linear runtime complexity and
use only constant extra space. you must think for your solution using bits manipulation
operation.
2. Write a function that takes an unsigned integer and returns the number of ’1’ bits it.
