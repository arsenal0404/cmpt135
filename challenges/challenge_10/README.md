# Tough Primes

A **tough prime** is a [prime
number](https://en.wikipedia.org/wiki/Prime_number) where after deleting *any
one* of its digits the resulting number is still a prime.

For example, the smallest tough prime is 23. Deleting the 2 leaves 3 (which is
prime), and deleting the 3 leaves 2 (which is also prime).

Another example is 4019. It's a tough prime because 4019 is prime, and so are
19, 419, 409, and 401 (the numbers resulting from deleting one digit of 4019).

What's the sum of all the tough primes less than a million?


## Files

Write your answer in [challenge_10.cpp](challenge_10.cpp).


## Extra

The following are some related ideas that you might want to think about. They
are not for marks!

- How would you modify your program to find primes that are still prime when
  exactly 2 digits are removed?

- Can you think of a way to remove digits of an integer without converting the
  integer to a string?


## Reminder

The point of these challenges is for you to practice solving problems with
C++. Please try to do them on your own, and don't just search for solutions
online.
