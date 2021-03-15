// a4.h

///////////////////////////////////////////////////////////////////////////////
//
// Do not change this file in any way!
//
// Implement the requested functions. Put your implementations of the given
// functions into a4.cpp.
// 
///////////////////////////////////////////////////////////////////////////////

#ifndef A4_H
#define A4_H

// Don't #include any other files.
#include "cmpt_error.h"
#include "cmpt_trace.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n squares, i.e.
//    1^2 + 2^2 + 3^2 + ... + n^2. If n is 0, then 0 is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write
//    helper functions if necessary.
// Note:
//    You don't need to worry about overflow sums that overflow int.
int sum_of_squares(int n);

void sum_of_squares_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n > 0
// Post-condition:
//    Returns the count (not the sum!) of the number of integers from 1 to n
//    (inclusive) that are multiples of 3 but not multiples of 5.
//
//    For example, sum_strange(20) returns 5 because among the numbers 1 to
//    20, the multiples of 3 are: 3, 6, 9, 12, 15, 18. Since 15 is also
//    a multiple of 5, it's not counted. So there are 5 counted numbers: 3, 6,
//    9, 12, 15, 18.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    You don't need to worry about overflow sums that overflow int.
int sum_strange(int n);

void sum_strange_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if all the characters in s are the same, and false
//    otherwise. If s is the empty string, true is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
bool all_same(const string& s);

void all_same_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if s is either empty, or contains only digit characters
//    '0' to '9'.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    When testing functions that return bool, make sure to include some 
//    test cases that return true, and some that return false.
bool all_digits(const string& s);

void all_digits_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a copy of s, but with all leading and trailing spaces removed.
//    No other characters are changed. For example, trim("  ab c  d ") returns
//    "ab c  d". If s is the empty string, then "" is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string trim(const string& s);

void trim_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the sum of just the negative numbers in v.
//    If v is empty, 0 is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int sum_neg(const vector<int>& v);

void sum_neg_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    a.size() == b.size(), and a.size() > 0
// Post-condition:
//    Returns a vector equal to {min(a[0],b[0]), min(a[1],b[1]),
//    min(a[2],b[2]), ..., min(a[n-1],b[n-1])}, where n == a.size().
//
//    For example, min_vec({3, 4, 1}, {2, 5, 2}) returns the new vector 
//    {2, 4, 1}.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<int> min_vec(const vector<int>& a, const vector<int>& b);

void min_vec_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the number of strings in v that are equal to s.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int count(const vector<string>& v, const string& s);

void count_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    s.size() == t.size()
// Post-condition:
//    Returns a vector<string> where the first string is the first character
//    of s followed by the first character of t, the second string is the
//    second character of s followed by the second character of t, and so on.
//    For example, zip("abc", "xyz") returns {"ax", "by", "cz"}.
//
//    If both s and t are empty, then an empty vector<string> is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<string> zip(const string& s, const string& t);

void zip_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a string consisting of all the strings in v concatenated
//    together with sep after each string (except for the last). 
//
//    For example, join({"cat", "dog", "house"}, ", ") returns the string
//    "cat, dog, house", and join({"he", "we", "see"}, "") returns the string
//    "hewesee".
//
//    If v is empty, the empty string is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string join(const vector<string>& v, const string& sep);

void join_test();

#endif
