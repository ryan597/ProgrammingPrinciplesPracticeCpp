# Programming Principles and Practice using C++

Exercises and code from the book [`Programming Principles and Practice using C++`](https://www.stroustrup.com/programming.html) by Bjarne Stroustrup.

I have made this repository pubic to motivate me to continue and complete the exercises within the book and to hopefully help me understand programming and C++ more completly. I also wanted to improve my documentation skills by writing more markdown (even if no-one will read it).  Note: The numbers in the filenames do not necessarily correspond to the numbered exercises in the book.

I give no warrenty for the code in this repository, that it works or is free from errors. The code presented here is mostly directly from the book in cases of the example files. Where the files are labeled as drills or exercises, it is my own solution to the posed problem.

---

## Contents

[Programming Principles and Practice using C++](#programming-principles-and-practice-using-c++)

1. [Dependencies](#1-dependencies)
2. [Folder Structure](#2-folder-structure)
3. [Programs](#3-programs)

    [Chapter 2](Chapter2/): Hello World

    [Chapter 3](Chapter3/): Objects, Types and Values

    [Chapter 4](Chapter4/): Computation

    [Chapter 5](Chapter5/): Errors

    [Chapter 6](Chapter6/): Writing a Program

    [Chapter 7](Chapter7/): Completing a Program

    [Chapter 8](Chapter8/): Technicalities: Functions, etc

    [Chapter 9](Chapter9/): Technicalities: Classes, etc

    [Chapter 10](Chapter10/): Input and Output Streams

    [Chapter 11](Chapter11/): Customising Input and Output

    [Chapter 12](Chapter12/): A Display Model

    [Chapter 13](Chapter13/): Graphics Classes

    [Chapter 14](Chapter14/): Graphics Class Design

    [Chapter 15](Chapter15/): Graphing Functions and Data

    [Chapter 16](Chapter16/): Graphical User Interface

    [Chapter 17](Chapter17/): Vector and Free Store

    [Chapter 18](Chapter18/): Vectors and Arrays

    [Chapter 19](Chapter19/): Vector, Templates, and Exceptions

    [Chapter 20](Chapter20/): Containers and Iterators

    [Chapter 21](Chapter21/): Algorithms and Maps

    [Chapter 22](Chapter22/): Ideals and History

    [Chapter 23](Chapter23/): Text Manipulation

    [Chapter 24](Chapter24/): Numerics

    [Chapter 25](Chapter25/): Embedded Systems Programming

    [Chapter 26](Chapter26/): Testing

    [Chapter 27](Chapter27/): The C Programming Language

---

## 1. Dependencies

To compile C++ code you need a C++ compiler. As the book is written for the C++11 and C++14 standards it is recommended that you use a compiler which is compatitable with the C++11 and C++14 standards, however I have not stuck to these standards and at some points there may be code which is from the C++20 standard. Thus you will need to compile with at least the `-std=c++11` flag for your compiler and in some places `-std=c++17` (and maybe `-std=c++2a`).

---

## 2. Folder Structure

There are 27 Chapters within the book, of which chapter 1 does not include any code examples or coding exercises so it is not listed as one od the folders.

Each folder in the repository contains three different type of C++ files. Those labeled as `example` are the sample codes used in the book (with possibly some minor modifications or comments where I saw fit). Files with the prefix `drill` are the suggested drills. As Bjarne suggests, you have not read the book unless you have done all the included drills and some of the exercises.  Lastly the files with `exercise` in the name are the problems to solve at the end of each chapter.

Each file is also numbered successively restarting at 1 with each chapter, and given a name indicative of the task the program is doing or the concept it is teaching.  The exercises are not numbered corresponding to the exercise in that chapter! I have skipped some where I deemed them too similar to others.

---

## 3. Programs

Here I will detail the exercises I completed from the different chapters of the book and what they teach. Each program should be easy to understand from its source code with the comments I have included, but I have decided this will give an easy overview without opening each individual file. As I work through the book, the style may (and should) change as I learn more about the language and the modern practices which may not even be in the book. For instance, I only setup the Clang-Tidy linter around chapter 5, so code begins to follow that formatting around then (eg. Functions with trailing return types).

- FILE_LINK: (Un)helpful description

## Part I: The Basics

### Chapter 2: Hello World

- [Example 1](Chapter2/example1_helloworld.cpp): Hello World
- [Drill 1](Chapter2/drill1_keepopen.cpp): Keep Window Open
- [Exercise 1](Chapter2/exercise1_helloworld.cpp): Hello World

### Chapter 3: Objects, Types and Values

- [Example 1](Chapter3/example1_nameage.cpp): Name and Age
- [Example 2](Chapter3/example2_operators.cpp): Operators
- [Example 3](Chapter3/example3_stringoperations.cpp): String Operations
- [Example 4](Chapter3/example4_repeatedwords.cpp): Repeated Words
- [Example 5](Chapter3/example5_unsafeconventions.cpp): Unsafe Conventions
- [Drill 1](Chapter3/drill1_letter.cpp): Letter
- [Exercise 1](Chapter3/exercise1_milestokms.cpp): Convert Miles to Kilometers
- [Exercise 2](Chapter3/exercise2_dollerscents.cpp): Calculate Value of Coins in Dollers

### Chapter 4: Computation

- [Example 1](Chapter4/example1_ifconditions.cpp): If Conditions
- [Example 2](Chapter4/example2_cmtoinch.cpp): Convert cm to inches
- [Example 3](Chapter4/example3_switchitup.cpp): Switch Statements
- [Example 4](Chapter4/example4_casesandcasesandcases.cpp): Cases in Switch Statements
- [Example 5](Chapter4/example5_whileloop.cpp): While Loops
- [Example 6](Chapter4/example6_printingchars.cpp): Printing Chars From Ints
- [Example 7](Chapter4/example7_functionprint.cpp): Printing Functions
- [Example 8](Chapter4/example8_vectors.cpp): Vectors
- [Example 9](Chapter4/example9_temperaturevector.cpp): Temperature Vector
- [Example 10](Chapter4/example10_simpledictionary.cpp): Unique Words
- [Drill 1](Chapter4/drill1_whileloop.cpp): Comparing While
- [Exercise 1](Chapter4/exercise1_currencyconvertorswitch.cpp): Converting Currencies
- [Exercise 2](Chapter4/exercise2_median.cpp): Calculating the Median
- [Exercise 3](Chapter4/exercise3_citydistance.cpp): City Distances
- [Exercise 4](Chapter4/exercise4_numberguessing.cpp): Number Guessing Game
- [Exercise 5](Chapter4/exercise5_calculator.cpp): Calculator
- [Exercise 6](Chapter4/exercise6_digitstrings.cpp): Digit Strings
- [Exercise 7](Chapter4/exercise7_singlespelldigitcalc.cpp): Spelling Digits
- [Exercise 8](Chapter4/exercise8_ricechesssquares.cpp): Grains of Rice
- [Exercise 9](Chapter4/exercise9_largestsquares.cpp): Overflow and Precision
- [Exercise 10](Chapter4/exercise10_rockpaperscissors.cpp): Rock, Paper, Scissors
- [Exercise 11](Chapter4/exercise11_primes.cpp): Primes
- [Exercise 12](Chapter4/exercise12_maxprimes.cpp): Max Primes
- [Exercise 13](Chapter4/exercise13_SieveOfEratosthenes.cpp): Sieve of Eratosthenes
- [Exercise 14](Chapter4/exercise14_MaxSieveOfEratosthenes.cpp): Max Sieve of Eratosthenes
- [Exercise 15](Chapter4/exercise15_nprimes.cpp): N Primes
- [Exercise 16](Chapter4/exercise16_findthemode.cpp): Find the Mode
- [Exercise 17](Chapter4/exercise17_minmaxmodestrings.cpp): Min, Max of Strings
- [Exercise 18](Chapter4/exercise18_quadratics.cpp): Quadratic Solver
- [Exercise 19](Chapter4/exercise19_namescores.cpp): NameScore

### Chapter 5: Errors

- [Example 1](Chapter5/example1_runtimeerrors.cpp): Runtime Errors
- [Example 2](Chapter5/example2_errorreporting.cpp): Error Reporting
- [Example 3](Chapter5/example3_vectorrange.cpp): Vector Range
- [Example 4](Chapter5/example4_runtimeerror.cpp): Runtime Exceptions
- [Example 5](Chapter5/example5_logicerrors.cpp): Logic Errors
- [Drill 1](Chapter5/drill1_codefragments.cpp): Code Fragments
- Exercise 1: Contains no code
- [Exercise 2](Chapter5/exercise2_converttemp.cpp): Fix errors in temp convert
- [Exercise 3](Chapter5/exercise3_absolutezero.cpp): Throwing errors below zero
- [Exercise 4](Chapter5/exercise4_absolute0.cpp): Throwing in the function
- [Exercise 5](Chapter5/exercise5_tempconversion.cpp): C to K and K to C
- [Exercise 6](Chapter5/exercise6_moretemperatures.cpp): All the Temperature Units
- [Exercise 7](Chapter5/exercise7_quadratics.cpp): No Complex Quadratics!
- [Exercise 8](Chapter5/exercise8_sumints.cpp): Summing it up
- [Exercise 9](Chapter5/exercise9_onlyintsums.cpp): Kinda Repetitive
- [Exercise 10](Chapter5/exercise10_sumdoubles.cpp): Really Bjarne?
- [Exercise 11](Chapter5/exercise11_fibonacci.cpp): Fibonacci to the Limit
- [Exercise 12](Chapter5/exercise12_bullsandcows.cpp): 4 Bulls and No Cows
- [Exercise 13](Chapter5/exercise13_bullsandcows2.cpp): Can't get enough Bulls
- [Exercise 14](Chapter5/exercise14_dayofweek.cpp): I Hate Monday -20 monday -100

### Chapter 6: Writing a Program

- [Example 1](Chapter6/example1_firstattempt.cpp): Starting Parsing
- [Example 2](Chapter6/example2_moreoperations.cpp): Throwing Again
- [Example 3](Chapter6/example3_tokens.cpp): Tokens
- [Example 4](Chapter6/example4_expressions.cpp): Parsing Expressions
- [Example 5](Chapter6/example5_term.cpp): Parsing Terms
- [Example 6](Chapter6/example6_primary.cpp): Primary First
- [Example 7](Chapter6/example7_donteatmytokens.cpp): Put It BACK!
- [Example 8](Chapter6/example8_tokenstream.cpp): Streaming Tokens
- [Drill 1](Chapter5/drill1_fixbuggy.cpp): Squashing Bugs
- [Exercise 1](Chapter6/exercise1_fixbuggy.cpp): Squashing Bugs 2: Electric Zapper
- [Exercise 2](Chapter6/exercise2_nameandvalue.cpp): Name and Shame
- [Exercise 3](Chapter6/exercise3_grammar.cpp): Grammar Grammar
- [Exercise 4](Chapter6/exercise4_bullsandcows.cpp): Guessing Game
- [Exercise 5](Chapter6/exercise5_permutations.cpp): Permutating

### Chapter 7: Completing a Program

### Chapter 8: Technicalities: Functions, etc

### Chapter 9: Technicalities: Classes, etc

---

## Part II: Input and Output

### Chapter 10: Input and Output Streams

### Chapter 11: Customising Input and Output

### Chapter 12: A Display Model

### Chapter 13: Graphics Classes

### Chapter 14: Graphics Class Design

### Chapter 15: Graphing Functions and Data

### Chapter 16: Graphical User Interface

---

## Part III: Data and Algorithms

### Chapter 17: Vector and Free Store

### Chapter 18: Vectors and Arrays

### Chapter 19: Vector, Templates, and Exceptions

### Chapter 20: Containers and Iterators

### Chapter 21: Algorithms and Maps

---

## Part IV: Broadening the View

### Chapter 22: Ideals and History

### Chapter 23: Text Manipulation

### Chapter 24: Numerics

### Chapter 25: Embedded Systems Programming

### Chapter 26: Testing

### Chapter 27: The C Programming Language

---
