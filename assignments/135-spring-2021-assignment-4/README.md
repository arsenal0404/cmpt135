## Assignment 4: Recursion

The purpose of this assignment is to practice writing recursive functions. The
questions are posed in the comments of [a4.h](a4.h). Each question is
associated with two function declarations: one function that solves the
described problem, and another function to test it. 

Write your answers directly in [a4.cpp](a4.cpp), and use
[a4_main.cpp](a4_main.cpp) to run and test your answers. You will need to
compile [a4.cpp](a4.cpp) and [a4_main.cpp](a4_main.cpp) separately, and then
link their `.o` files into executable for running the tests. A special-purpose
[makefile](makefile) is provided to help with this.


### Pre-conditions and Post-conditions

The functions are specified using *pre-conditions*, *post-conditions*, and
*constraints*. For example, here is the specification for a function that sums
the integers from 1 to n:

```cpp
// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n integers, i.e. 1 + 2 + 3 + ... + n.
//    If n is 0, then 0 is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write
//    helper functions if necessary.
// Note:
//    You don't need to worry about sums that overflow int.
int sum(int n);
```

The **pre-condition** states what must be true *before* the function is
called, and the **post-condition** states what must be true *after* the
functions finishes running correctly (assuming that the pre-condition held
before it was called).

**Constraints** lists any other things that must be true for the function.

If a function's pre-condition is *false* when the function is called, then
that means it's being called with bad data, and you probably have a bug
somewhere in your code.

> **Hint**: For functions with pre-conditions, put a call to `assert` at the
> start to check if the pre-condition is true. This can be a good way help
> catch bugs.


## Testing

For each function, you must also write a corresponding **test function** that
*automatically* runs tests on the function to help ensure it is working
correctly. For example, the test function for `sum` could be this:

```cpp
#include <cassert>

// ...

void sum_test() {
  cout << "Testing sum ... ";
  assert(sum(0) == 0);
  assert(sum(1) == 1);
  assert(sum(2) == 1 + 2);
  assert(sum(3) == 1 + 2 + 3);
  assert(sum(4) == 1 + 2 + 3 + 4);
  cout << "all sum tests passed!\n";
}
```

In some cases, you might prefer to use an if-statement rather than `assert`.
For example, the test `assert(sum(2) == 1 + 2)` could be written like this:

```cpp
if (sum(2) != 1 + 2) cmpt::error("test failed");
```

However you write your tests, make sure they are all run and checked
*automatically*.

You may also want to use [cmpt_trace.h](cmpt_trace.h) to help debug your
functions. It prints messages when functions are called and when they exit,
which can be helpful for understanding and debugging recursive functions. See
the comments in [cmpt_trace.h](cmpt_trace.h) for an example of how to use it.


## General Implementation Constraints

You are **can** use helper functions (that you write) if you like.

**Do not** use any global variables, static local variables, or other such
tricks when implementing these functions. If your code uses any of these
tricks then you will get 0 for that question. Just use functions, parameters,
and return values.

**No loops are permitted** in any of the code you write for this assignment
(not even in the test functions or helper functions). If your code uses a loop
then you will get 0 for that question.

Use **exactly** the function names and parameters given in [a4.h](a4.h).
**Don't change those declarations in any way**. If you do, you will get 0 for
that question, since your mark depends upon implementing exactly those
functions with exactly those names and parameters.


## Submitting Your Work

On Canvas, please submit [a4.cpp](a4.cpp), and nothing else. 

The marker will compile your [a4.cpp](a4.cpp) and link it with their own
`main()` function. A copy of [a4.h](a4.h), [cmpt_error.h](cmpt_error.h),
[cmpt_trace.h](cmpt_trace.h), and [cmpt_trace.cpp](cmpt_trace.cpp) will be in
the same folder as your program when it runs.


## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using the [makefile](makefile) in this
  assignment. 

  ```bash
  $ make
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o a4.o a4.cpp
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o a4_main.o a4_main.cpp
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g  -c -o cmpt_trace.o cmpt_trace.cpp
  g++ -o a4_main_test a4.o a4_main.o cmpt_trace.o

  $ ./a4_main_test
  ...
  ```

  Note that this [makefile](makefile) is customized for this assignment.
  Notice also that the name of the executable it builds is `a4_main_test`. See
  the comments at the top of [makefile](makefile) for how to use it.
  
  If your program fails to compile using this [makefile](makefile), your mark
  for this assignment will be 0.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:

  ```
  $ valgrind ./a4_main_test
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory error if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
    lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non- zero number of
    bytes.

- **You must include the large comment section with student info and the
  statement of originality**. If your submitted file does not have this, then
  we will assume your work is not original and it will not be marked.
  
If your program meets all these basic requirements, then it will be graded
using the marking scheme on Canvas.


## Marking Scheme

### Source Code Readability (6 marks)

- All names of variables, functions, structs, classes, etc. are sensible,
  self-descriptive, and consistent.

- Indentation and spacing is perfectly consistent and matches the structure of
  the program. All blank lines and indents have a reason.

- All lines are 100 characters in length, or less.

- Comments are used when appropriate, e.g to describe code that is tricky or
  very important. There are no unnecessary comments, and no commented-out
  code.

- Appropriate features of C++ are used in an appropriate way. For example, do
  **not** use a feature of C (like C-style strings) when there is a better C++
  feature (e.g. the standard `string` class). Don't use any features you don't
  understand.

- Overall, the source code is easy to read and understand.

### Functions (20 marks)

- 1 mark for correctly and efficiently implementing each requested recursive
  function.

- 1 mark for thoroughly testing each requested recursive function with its own
  test function.
