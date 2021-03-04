# Min and Max

On each row of [numbers5.txt](numbers5.txt) are one or more comma-separated
numbers. Let A be the *minimum* of all the *maximums* of the rows, and let B
the be the *maximum* of all the *minimums* of the rows.

For example, suppose the file had these three rows:

```
2.09, 4, 3.72, -2.3
9
1.2, 20, -44.2
```

Then A is the min of all the row maxes, i.e. A is the min of {3.72, 9, 1.2},
so A = 1.2. B is the max of all the row mins, i.e. B is the max of {-2.3, 9,
-44.2}, so B = 9.

What are A and B for [numbers5.txt](numbers5.txt)?


## Files

[numbers5.txt](numbers5.txt)

Write your answer in [challenge_5.cpp](challenge_5.cpp).


## Extra

The following are some related ideas that you might want to think about. They
are not for marks!

- How would you change you program if the numbers in the file were
  space-separated instead of comma-separated?


## Reminder

The purpose of these challenges is to practice solving problems with C++.
Please try to do them on your own, and don't just search for solutions online
or ask others for the answers.
