# Column Sums

In [bits_1000_500.txt](bits_1000_500.txt), there are 1000 rows, each row
consisting of exactly 500 0s and 1s. This forms a table with 1000 rows and 500
columns, where the columns are numbered from 1 to 500. 

What is the number of the column with the greatest sum, and what is the sum?
If two or more columns tie for the greatest sum, return the rightmost column
(i.e. the one with the biggest column number).


## Allowable Includes

You may use only the following #includes in your code:

```cpp
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
```

You do not need to use all of these, but you cannot use any others.


## Files

[bits_1000_500.txt](bits_1000_500.txt).

Write your answer in [challenge_6.cpp](challenge_6.cpp).


## Extra

The following are some related ideas that you might want to think about. They
are not for marks!

- Would your program still work if the 0s and 1s could be any integers? Or any
  floating point numbers?

- How would you modify your program to handle rows that are of varying
  lengths?


## Reminder

The purpose of these challenges is to practice solving problems with C++.
Please try to do them on your own, and don't just search for solutions online
or ask others for the answers.
