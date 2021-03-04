# Unprecedented Arithmetic

An **unprecedented arithmetic expression** is a sequence of integers and
operators such as `1 - 2 + 3` or `6 - 2 * 3`. The operators all have the same
precedence, and so expressions are evaluated from left to right in the order
they occur.

For example, `1 - 2 + 3` evaluates to 2, and `6 - 2 * 3` evaluates to 12 (not
0!).

For simplicity, the numbers are always integers greater than 0, and there are
no brackets. There is at least one space between each operator and number.
There are four legal operators: `+`, `-`, `*`, and `@`. The `+`, `-`, and
`*`work in the usual way, but `@` is a variation of `%` that first calculates
the absolute value of its arguments. The expression `a @ b` evaluates to the
same thing as `abs(a) % abs(b)`.

How many expressions (one per line) in [expr1000.txt](expr1000.txt) evaluate
to a number that is a multiple of 5?


## Files

[expr1000.txt](expr1000.txt)

Write your answer in [challenge_8.cpp](challenge_8.cpp).


## Extra

The following are some related ideas that you might want to think about. They
are not for marks!

- What if 0 was allowed as a value? How would you modify the expressions to
  always work with 0?

- Modify your program to allow the integer division operator `/`. For example,
  `10 / 3` is 3, and `6 / 15` is 0.


## Reminder

The point of these challenges is for you to practice solving problems with
C++. Please try to do them on your own, and don't just search for solutions
online.
