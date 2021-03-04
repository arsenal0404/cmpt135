// a2.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Justin Chiang
// St.# : 301431456
// Email: jpc13@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

//
// These are the only permitted includes: don't include anything else.
//
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <algorithm>       
#include <cassert>

using namespace std;

class str_vec {

  // ...

  int vecSize;
  int vecCapacity;
  string* arr;
  

  public: 

    // Default constructor 
    str_vec() : vecSize(0), vecCapacity(10), arr(new string[vecCapacity]){}

    //Fills arr with string
    str_vec(int n, string s) 
    : vecSize(n), vecCapacity(n), arr(new string[vecCapacity]){

      if (n < 0){
        cmpt::error("n is out of the legal range");
      }

      if (n <= vecCapacity){
        for (int i = 0; i < n; i++){
          arr[i] = s;
        }
      }
    }

    //Copy constructor
    str_vec(const str_vec& other) 
    : vecSize(other.vecSize), vecCapacity(other.vecCapacity), arr(new string[vecCapacity]){

      for (int i = 0; i < vecSize; i++){
        arr[i] = other.arr[i];
      }

    }

    ~str_vec(){    
      delete[] arr;
    }

    int size() const{
      return vecSize;
    }

    int capacity() const{
      return vecCapacity;
    }

    int pct_used() const{
      double pct = (double) vecSize / vecCapacity; 

      return pct;
    }

    string to_str() const{
      string sentence = "[";

      for (int i = 0; i < vecSize; i++){

        string word;
        word = '"';
        word += arr[i];
        word += '"';

        if (i != vecSize - 1){
          word += ", ";
        }

        sentence.append(word);

      }

      sentence += "]";

      return sentence;
    }

    void print() const{
      string print = to_str();

      cout << print;
    }

    void println() const{
      string print = to_str();

      cout << print << "\n";
    }

    string get(int i) const{
      if (i < 0 || i > vecSize - 1){

        cmpt::error("i is out of legal range");

      }

      return arr[i];
    }

    void set(int i, string s){
      if (i < 0 || i > vecSize - 1){

        cmpt::error("i is out of legal range");

      }

      arr[i] = s;
    }

    void append(const string& s){
      if (vecSize == vecCapacity){

        vecCapacity = 2 * vecCapacity;

        string* new_arr = new string[vecCapacity];

        for (int i = 0; i < vecSize; i++){
          new_arr[i] = arr[i];
        }

        delete[] arr;

        arr = new_arr;
      }

      arr[vecSize++] = s;
      //Note to self for future reference:
      //arr[vecSize] = x;
      //vecSize++
    }

    void append(const str_vec other){
      
      for (int j = 0; j < other.vecSize; j++){
        if (vecSize == vecCapacity){

          vecCapacity = 2 * vecCapacity;

          string* new_arr = new string[vecCapacity];

          for (int i = 0; i < vecSize; i++){
            new_arr[i] = arr[i];
          }

          delete[] arr;

          arr = new_arr;
        }

        arr[vecSize++] = other.arr[j];

      }
    }

    void prepend(const string& s){
      if (vecSize == vecCapacity){

        vecCapacity = 2 * vecCapacity;

        string* new_arr = new string[vecCapacity];

        for (int i = 0; i < vecSize; i++){
          new_arr[i] = arr[i];
        }

        delete[] arr;

        arr = new_arr;
      }
      //shifts elements one index to the right
      for (int i = vecSize; i > 0; i--){
        arr[i] = arr[i - 1];
      }

      arr[0] = s;
      vecSize++;
    }

    void reverse(){
      string* new_arr = new string[vecCapacity];

      for (int i = 0; i < vecSize; i++){
        new_arr[i] = arr[(vecSize - 1) - i];
      }

      delete[] arr;
      arr = new_arr;
    }

    void sort(){
      std::sort(arr, arr + vecSize);
    }

    void clear(){
      delete[] arr; 
      vecSize = 0;
      arr = new string[vecCapacity];
    }

    //Makes the vecCapacity equal to the vecSize and alters array accordingly
    void squish(){
      string* new_arr = new string[vecSize];
      vecCapacity = vecSize;

      for (int i = 0; i < vecSize; i++){
        new_arr[i] = arr[i];
      }

      delete[] arr;
      arr = new_arr;
    }

    bool operator== (const str_vec& b){
      for (int i = 0; i < vecSize; i++){

        if (arr[i] != b.arr[i]){
          return false;
        }

      } 

      return true;
    }

    bool operator!= (const str_vec& b){

      for (int i = 0; i < vecSize; i++){

        if (arr[i] != b.arr[i]){
          return true;
        }

      } 

      return false;

    }

    

}; // class str_vec

//Testing Prototypes
void test_default();
void test_copy();
void size_test();
void capacity_test();
void pct_used_test();
void to_str_test();
void print_test();
void println_test();
void get_test();
void set_test();
void append_test();
void prepend_test();
void append_str_vec_test();
void reverse_test();
void sort_test();
void clear_test();
void squish_test();
void equal_test();
void not_equal_test();

int main() {
  cout << "Assignment 2 ... \n";

  //
  // ... put code that calls your functions here ...
  //

  test_default();
  test_copy();
  size_test();
  capacity_test();
  pct_used_test();
  to_str_test();
  print_test();
  println_test();
  get_test();
  set_test();
  append_test();
  prepend_test();
  append_str_vec_test();
  reverse_test();
  sort_test();
  clear_test();
  squish_test();
  equal_test();
  not_equal_test();

}

void test_default(){
  cout << "Testing test_default()...";

  str_vec sv; 

  assert(sv.size() == 0);

  assert(sv.capacity() == 10);

  cout << "   ... test_default() passed!\n";
}

void test_copy(){
  cout << "Testing test_copy()...";

  str_vec a(5, "<empty>");
  str_vec b(a);

  assert(a.size() == b.size());
  assert(b.capacity() == b.capacity());

  cout << "   ... test_copy() passed!\n";
}

void size_test(){
  cout << "Testing size_test()...";

  str_vec sv(6, "cat");

  assert(sv.size() == 6);

  cout << "   ... size_test() passed!\n";
}

void capacity_test(){
  cout << "Testing capacity_test()...";

  str_vec sv(12, "cat");

  assert(sv.capacity() == 12);

  cout << "   ... capacity_test() passed!\n";
}

void pct_used_test(){
  cout << "Testing pct_used_test()...";

  str_vec sv;

  assert(sv.pct_used() == 0.0);
  
  cout << "   ... pct_used_test() passed!\n";
}

void to_str_test(){
  cout << "Testing to_str_test()...";

  str_vec sv(3, "cat");

  string s = sv.to_str();

  string test = "[\"cat\", \"cat\", \"cat\"]";
  assert(sv.to_str() == test);

  cout << "   ... to_str_test() passed!\n";
}

void print_test(){
  cout << "Testing print_test()...";

  str_vec sv(3, "cat");

  sv.print();

  cout << "   ... print_test() passed!\n";
}

void println_test(){
  cout << "Testing println_test()...";

  str_vec sv(3, "cat");

  sv.println();
  
  cout << "   ... println_test() passed!\n";
}

void get_test(){
  cout << "Testing get_test()...";

  str_vec sv(4, "cat");

  string test = sv.get(2);

  assert(test == "cat");

  cout << "   ... get_test() passed!\n";
}

void set_test(){
  cout << "Testing set_test()...";

  str_vec sv(4, "cat");

  sv.set(2, "dog");

  string test = sv.get(2);
  
  assert(test == "dog");
  assert(sv.get(1) == "cat");

  cout << "   ... set_test() passed!\n";
}

void append_test(){
  cout << "Testing append_test()...";

  str_vec sv; 
  sv.append("apple");
  sv.append("orange");

  assert(sv.get(0) == "apple");
  assert(sv.get(1) == "orange");
  assert(sv.size() == 2);

  cout << "   ... append_test() passed!\n";
}

void prepend_test(){
  cout << "Testing prepend_test()...";

  str_vec sv; 
  sv.append("apple");
  sv.append("orange");

  sv.prepend("up");
  sv.prepend("down");

  assert(sv.get(0) == "down");
  assert(sv.get(1) == "up");

  cout << "   ... prepend_test() passed!\n";
}

void append_str_vec_test(){
  cout << "Testing append_str_vec_test()...";

  str_vec arr1;

  arr1.append("apple"); 
  arr1.append("orange");

  str_vec arr2;
  arr2.append(arr1);  
  arr2.append(arr2);

  assert(arr2.get(0) == "apple");
  assert(arr2.get(1) == "orange");
  assert(arr2.get(2) == "apple");
  assert(arr2.get(3) == "orange");

  cout << "   ... append_str_vec_test() passed!\n";
}

void reverse_test(){
  cout << "Testing reverse_test()...";

  str_vec arr;

  arr.append("d");
  arr.append("b");
  arr.append("a");
  arr.append("c");

  arr.reverse();

  assert(arr.get(0) == "c");
  assert(arr.get(1) == "a");

  cout << "   ... reverse_test() passed!\n";
}

void sort_test(){
  cout << "Testing sort_test()...";

  str_vec arr;

  arr.append("d");
  arr.append("b");
  arr.append("a");
  arr.append("c");

  arr.sort();

  assert(arr.get(0) == "a");
  assert(arr.get(1) == "b");

  cout << "   ... sort_test() passed!\n";
}

void clear_test(){
  cout << "Testing clear_test()...";

  str_vec arr;      
  arr.append("a");  
  arr.append("b");

  arr.clear();

  assert(arr.size() == 0);


  cout << "   ... clear_test() passed!\n";
}

void squish_test(){
  cout << "Testing squish_test()...";

  str_vec arr;      
  arr.append("a");  
  arr.append("b");

  arr.squish();

  assert(arr.capacity() == 2);

  cout << "   ... squish_test() passed!\n";
}

void equal_test(){
  cout << "Testing equal_test()...";

  str_vec a(3, "cat"); 
  str_vec b(3, "cat");

  assert(a == b);


  cout << "   ... equal_test() passed!\n";
}

void not_equal_test(){
  cout << "Testing not_equal_test()...";

  str_vec a(3, "cat"); 
  str_vec b(3, "cat");

  a.set(0, "feline");

  assert(a != b);

  cout << "   ... not_equal_test() passed!\n";
}