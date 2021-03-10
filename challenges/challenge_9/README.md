# Double Sorting

Suppose you sort the letters of each word in [words9.txt](words9.txt) into
alphabetical order, and then sort that resulting list of strings into
alphabetical order. What is the word from the original list that ends up at
position 50,000 (where the first word is at position 1, the second word is at
position 2, and so on) of the final doubly-sorted list?

For example, suppose you were given these words:
```
cat
plus
dog
act
lava
```

After sorting the letters of each word the list is:
```
act
lpsu
dgo
act
aalv
```

Sorting these strings gives:
```
aalv
act
act
dgo
lpsu
```

The word from the original list that ends up in the 5th position is "plus".


## Files

[words9.txt](words9.txt)

Write your answer in [challenge_9.cpp](challenge_9.cpp).


## Extra

The following are some related ideas that you might want to think about. They
are not for marks!

- How would you modify your program so it ran as fast as possible?

- Can you think of any practical uses for sorting the letters of a word?


## Reminder

The point of these challenges is for you to practice solving problems with
C++. Please try to do them on your own, and don't just search for solutions
online.
