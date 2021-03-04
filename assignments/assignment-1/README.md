# Assignment 1: A Dynamic String Array

In this assignment your task is to implement, and test, a set of functions
that implement a dynamic array of strings.


## Getting Started

Please download all the files in this repository. Here are the important
assignment files:

- [a1.h](a1.h) is a header file that contains the `str_list` struct you'll
  need in the questions below.

- [a1.cpp](a1.cpp) is where you should write your solutions. It is set up to
  get you started. Make sure to fill in the info in the header at the top.

- [test_small.txt](test_small.txt) contains the sample text used below.

- [makefile](makefile) is the standard course makefile.

- [cmpt_error.h](cmpt_error.h) contains the `cmpt::error` function.

**Important**: Don't change [a1.h](a1.h) in any way! When the marker tests
your code, they will supply a copy of [a1.h](a1.h).

**Don't** add any other `#include` statements to [a1.cpp](a1.cpp). Use only
the ones that are already there.

You **can** add any helper functions you think might be useful (as long as you
write them yourself).

For each function requested by the questions below, also write a *test
function* that *automatically* checks that the function is working correctly.
Name these test functions the same as the function being tested, but with
`_test` added to the end. For example, the testing function for `make_new`
should be called `make_new_test`, and might be implemented like this:

```cpp
void make_new_test() {
   cout << "Running make_new_test() ... ";

   str_list a = make_new();
   assert(a.size == 0);
   assert(a.capacity == 5);

   // ...

   cout << "make_new_test() passed\n";
}
```


## Questions

1. Write a function that makes a new empty `str_list` of size 0 and capacity
   `cap`. It should have this header:

   ```cpp
   str_list make_new(int cap = 5)
   ```

   For example, calling `make_new(50)` returns a new `str_list` of size
   0 and capacity 50, and calling `make_new()` returns a new `str_list`
   object of size 0 and capacity 5.

   Remember to create a function called `make_new_test()` to test that
   `make_new` works correctly.

2. Implement this function:

   ```cpp
   void deallocate(str_list& arr)
   ```

   `deallocate(arr)` de-allocates the underlying array that `arr` points
   to.

   `deallocate(arr)` should call `delete[]` on the underlying array, and also
   set the array pointer to `nullptr`. Setting the array pointer to `nullptr`
   prevents memory corruption in cases when `deallocate` is called more than
   once on the same array.

   It is up to the programmer to always remember to call `deallocate` when
   they are finished using a `str_list`.

   Be sure to run your test code with `valgrind` to make certain it has no
   memory leaks or other memory errors!


3. Implement this function:

   ```cpp
   str_list clone(const str_list& other)
   ```
   
   `clone(other)` returns a new `str_list` that is a copy of `other`. The
   returned `str_list` points to its own array that is a copy of the array in
   `other`.

4. Implement this function:

   ```cpp
   string to_str(const str_list& arr)
   ```

   The string returned by `to_str(arr)` begins with a `[` and ends with `]`,
   and all the strings in it begin and end with `"`. The strings are separated
   by ", ".

   For example, if `arr` is an array with the strings `"owl"`, `"bug"`, and
   `"cow"`, then `to_str(arr)` returns this string:

   ```cpp
   ["owl", "bug", "cow"]
   ```

   If `arr.size` is 0, then `"[]"` is returned. If `arr.size == 1`, then
   there's only one string in it (and no commas). 

   **Important**: Make sure the string returned by `to_str` follows exactly
   this format. Make sure the spacing is *exact*.

   Note that `to_str` only writes the first `size` elements of the underlying
   array.

   After you've implemented `to_str`, use it to (easily!) implement these two
   functions:

   ```cpp
   // writes to_str(arr) to cout
   void write(const str_list& arr)

   // same as write, but also writes '\n' at the end
   void writeln(const str_list& arr)
   ```

5. Implement this function:

   ```cpp
   string get(const str_list& arr, int i)
   ```
   
   `get(arr, i)` returns the string at index location `i` of the underlying
   array.

   `get` should *check the bounds* of `i`, i.e. if `i < 0` or `i >= arr.size`,
   then call `cmpt::error` to stop the program with a helpful error message.

   Next, implement the `set(arr, i, s)` function, which assigns string `s`
   to location `i` of the underlying array:

   ```cpp
   void set(str_list& arr, int i, const string& s)
   ```

   As with `set`, check the bounds of `i`, i.e. if `i < 0` or `i >=
   arr.size`, then call `cmpt::error` to stop the program with a helpful
   error message.


6. Implement this function: 

   ```cpp
   void add_right(str_list& arr, const string& s)
   ```

   `add_right(arr, s)` adds a new string to the right end of `arr`, re-sizing
   `arr` if necessary.

   If `arr.size < arr.cap`, then `add_right` increments `arr.size` and puts
   `s` at the first unused location at the right end of `arr`.

   Otherwise, if `arr.size >= arr.cap`,  the underlying array is first
   re-sized to be **twice the capacity**. Then `s` is added to the right end
   of the array as in the previous case.


7. Implement this operator:

   ```cpp
   bool operator==(str_list a, str_list b)
   ```
   
   `a` and `b` are considered equal if they have the same size, and contain
   the same strings in the same order.

   Also, implement this operator:

   ```cpp
   bool operator!=(str_list a, str_list b)
   ```

   `a != b` is true just when `a` and `b` are *not* the same.

8. Implement this function:

   ```cpp
   void clear(str_list& arr)
   ```

   After calling `clear(arr)`, the size of `arr` is 0. The underlying array
   doesn't need to change.


9. Implement this function:

   ```cpp
   void add_left(str_list& arr, const string& s)
   ```

   It works just like `add_right` from above, but `s` is added at the left
   end, i.e as the *first* element of the array (and all the other elements
   are moved right one position).

   For example, if `arr` is `["up", "down", "mouse"]`, then after calling
   `add_left(arr, "cat")` `arr` will be `["cat", up", "down", "mouse"]`.


10. Implement this function:

    ```cpp
    void shrink_to_fit(str_list& arr)
    ```

    `shrink_to_fit(arr)` will, if possible, re-size the underlying array as
    described. The values in `arr` should be the same (and in the same order)
    after calling `shrink_to_fit` as before.


11. Implement this function:
  
    ```cpp
    str_list make_fromFile(const string& fname)
    ```

    `fname` is the name of a text file, and `make_fromFile(fname)` reads all
    the strings, in the same order they occur in the file, into a new
    `str_list`. To read the strings, use a loop that repeatedly calls `fin >>
    s`, where `fin` is an `fstream` object and `s` is the string read in.

    For example, suppose the text file `test.txt` contains this:

    ```
    main() is the 1st "function" 
    C++ calls?!
    ```

    Then this code

    ```cpp
    str_list arr = make_fromFile("test.txt");
    cout << arr.size << " words added\n";
    writeln(arr);
    ```

    prints:

    ```
    7 words added
    ["main()", "is", "the", "1st", ""function"", "C++", "calls?!"]
    ```

    Notice the order of the words is the same as in the file.

12. Implement this function:

    ```cpp
    double avg_size(str_list& arr)
    ```

    `avg_size(arr)` returns the average of the sizes of the strings in `arr`.
    If `arr` is empty, 0 is returned.

13. Implement this function:

    ```cpp
    str_list append(str_list a, str_list b)
    ```

    `append(a, b)` returns a new `str_list` consisting of the elements of `a`
    followed by the elements of `b`. For example, if `a` is `["once", "upon",
    "a"]` and `b` is `["time", "Bob", "wondered"]`, then `append(a, b)`
    returns the `str_list` `["once", "upon", "a", "time", "Bob", "wondered"]`.


## Submit Your Work

Please put all your code into [a1.cpp](a1.cpp), and submit just that file on
Canvas. Make sure to use **exactly** the same function headers for all the
questions, otherwise the marking software will probably give you 0!

**Do not submit** [a1.h](a1.h), [cmpt_error.h](cmpt_error.h), **or any other
files**. Copies of [a1.h](a1.h) and [cmpt_error.h](cmpt_error.h) will be
supplied in the same folder as your `.cpp` file when the marker runs your
program.


## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using [the standard course
  makefile](makefile):

  ```console
  $ make a1 
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   a1.cpp   -o a1
  ```

  If your program fails to compile, your mark for this assignment will be 0.

  [cmpt_error.h](cmpt_error.h) will be in the same folder as `a1.cpp` when
  it's compiled, so your program can use `cmpt::error` if necessary.

- It must have no memory leaks, according to `valgrind`, e.g.:

  ```console
  $ valgrind ./a1
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory leaks if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and
    `possibly lost` must all be 0.

  - `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non-zero number of
    bytes.

  If `valgrind` reports any errors for your program, your mark for the
  assignment will be 0.

- **You must include the large comment section with student info and the
  statement of originality**. If your submitted file does not have this, then
  we will assume your work is not original,  and it will not be marked.
  
If your program meets all these basic requirements, then it will graded using
the marking scheme on Canvas.


## Marking Scheme

### Source Code Readability

- All names of variables, functions, structs, classes, etc. are sensible,
  self-descriptive, and consistent.

- Indentation and spacing is perfectly consistent and matches the structure of
  the program. All blank lines and indents should have a reason.

- All lines are 100 characters in length, or less.

- Comments are used when appropriate: to describe code that is tricky or very
  important. There are no unnecessary comments, and no commented-out code.

- Appropriate features of C++ are used in an appropriate way. For example, do
  **not** use a feature of C (like C-style strings) when there is a better
  feature of C++ (e.g. the standard `string` class). Don't use any features
  you don't understand.

- Overall, the source code is easy to read and understand.

### Questions 

- 1 mark for correctly and efficiently implementing the functions for each
  question.

- 1 mark for testing the functions for each question with their own test
  function.
