// a1.cpp

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

#include "a1.h"
#include "cmpt_error.h"
#include <iostream>      // no other #includes are allowed
#include <fstream>       // for this assignment
#include <string>
#include <cassert>

using namespace std;

//
// ... write your functions here ...
//

str_list make_new(int cap){ 

  str_list newStr; 
  newStr.size = 0;
  newStr.capacity = cap; 
  newStr.arr = new string[newStr.capacity];
  
  return newStr;
} 

str_list make_new(){
  return make_new(5);
}

void deallocate(str_list& list){


  if (list.arr != nullptr){
    delete[] list.arr;
    list.arr = nullptr;
  }
  
  
}

str_list clone(const str_list& other){

  str_list clone = make_new(other.capacity);
  for (int i = 0; i < other.size; i++){
    clone.arr[i] = other.arr[i];
  }
  clone.size = other.size;

  return clone;

}

string to_str(const str_list& arr){

  string sentence = "["; 

  for (int i = 0; i < arr.size; i++){

    string word;
    word = '"';
    word += arr.arr[i];
    word += '"';

    if (i != arr.size - 1){
      word += ", ";
    }

    sentence.append(word);

  }

  sentence += "]";

  return sentence;

}

void write(const str_list& arr){

  string print = to_str(arr);

  cout << print;

}

void writeln(const str_list& arr){

  string print = to_str(arr);

  cout << print << "\n";

}

string get(const str_list& arr, int i){

  string wordGotten;
  
  if (i < 0 || i >= arr.size){
    cmpt::error("Index is out of range");
  } else {
    wordGotten = arr.arr[i];
  }

  return wordGotten;
}

void set(str_list& arr, int i, const string& s){

  if (i < 0 || i >= arr.size){
    cmpt::error("Index if out of range");
  } else { 
    arr.arr[i] = s;
  }

}

void add_right(str_list& arr, const string& s){

  if (arr.size < arr.capacity){

    arr.arr[arr.size] = s;
    arr.size++;

  } else if (arr.size >= arr.capacity){

    
    string* holder = new string[arr.capacity * 2];

    for (int i = 0; i < arr.size; i++){
      holder[i] = arr.arr[i];
    }
    arr.capacity *= 2;
    deallocate(arr);
    arr.arr = holder;
  
    arr.arr[arr.size] = s;
    arr.size++;
    
  }

}

bool operator==(str_list a, str_list b){

  if (a.size == b.size){
    for (int i = 0; i < a.size; i++){
      if (a.arr[i] != b.arr[i]){
        return false;
      }
    }
    return true;
  }

  return false;

}

bool operator!= (str_list a, str_list b){

  if (a.capacity != b.capacity || a.size != b.size){
    for (int i = 0; i < a.size; i++){
      if (a.arr[i] != b.arr[i]){
        return true;
      } 
      
    }
  }  
  return false;
}

void clear(str_list& arr){

  arr.size = 0;

}

void add_left(str_list& arr, const string& s){

  if (arr.size < arr.capacity){

    string* holder = new string[arr.size];
    for (int i = 0; i < arr.size; i++){
      holder[i] = arr.arr[i];
      arr.arr[i + 1] = holder[i];
    }
    arr.arr[0] = s;

    delete[] holder;

  } else if (arr.size >= arr.capacity){

    
    string* holder = new string[arr.capacity * 2];

    for (int i = 0; i < arr.size; i++){
      holder[i] = arr.arr[i];
    }
    arr.capacity *= 2;
    deallocate(arr);
    arr.arr = holder;
  
    for (int i = 0; i < arr.size; i++){
      holder[i] = arr.arr[i];
      arr.arr[i + 1] = holder[i];
    }

    arr.arr[0] = s;

    delete[] holder;
    
  }
  

}

void shrink_to_fit(str_list& arr){

  string* holder = new string[arr.size];

  for (int i = 0; i < arr.size; i++){
    holder[i] = arr.arr[i];
  }

  arr.capacity = arr.size;
  deallocate(arr);
  arr.arr = holder;

}

str_list make_fromFile(const string& fname){

  ifstream wordFile(fname);
  if (wordFile.fail()){
    cout << "Unable to read file. \n";
    exit(EXIT_FAILURE);
  }

  str_list file = make_new();
  while (true){

    string word;
    wordFile >> word;
    if(wordFile.fail()){
      break;
    }

    add_right(file, word);

  }
  

  return file;
}

double avg_size(str_list& arr){


  double sum = 0; 
  double average = 0;

  for (int i = 0; i < arr.size; i++){

    sum += arr.arr[i].size();

  }

  average = sum / arr.size;

  return average;
}

str_list append(str_list a, str_list b){

  str_list final = make_new(a.size + b.size);

  for (int i = 0; i < a.size; i++ ){
    
    final.arr[i] = a.arr[i];
    final.size++;

  }
  
  for (int i = 0; i < b.size; i++){

    final.arr[i + a.size] = b.arr[i];
    final.size++;

  }

  return final;
}



//
// ... put your test functions here (one test function for each 
//     function above) ... 
// 

void make_new_test(){
  cout << "Running make_new_test() ... ";

  str_list a = make_new();
  assert(a.size == 0);
  assert(a.capacity == 5);

  for (int i = 0; i < 100; i += 2){
    str_list b = make_new(i);
    assert(b.size == 0);
    assert(b.capacity == i);

    deallocate(b);
    
  }

  deallocate(a);

  // ...

  cout << "make_new_test() passed\n";
}

void deallocate_test(){
  cout << "Running deallocate_test() ... ";
  
  str_list a = make_new();
  deallocate(a);
  
  cout << "deallocate() passed\n";
}

void clone_test(){
  cout << "Running clone_test() ... ";
  str_list a = make_new(22);

  str_list b = clone(a);

  assert(a.size == b.size);
  assert(a.capacity == b.capacity);
  
  bool same = true;
  for (int i = 0; i < a.capacity; i++){
    if (a.arr[i] != b.arr[i]){
      same = false;
    }
  }

  assert(same);
  assert(&a.arr != &b.arr);
  assert(&a.size != &b.size);
  assert(&a.capacity != &b.capacity);
  assert(a.arr != b.arr);

  deallocate(a);
  deallocate(b);

  cout << "clone_test() passed\n";
}

void to_str_test(){
  cout << "Running to_str() ... ";

  str_list a = make_new();
  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.size = 3;

  string test = to_str(a);
  cout << test;

  cout << "to_str() passed\n";

  deallocate(a);
}

void get_test(){
  cout << "Running get() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  string b = get(a, 2);
  assert(b == a.arr[2]);
  string c = get(a, 3);
  assert(c == a.arr[3]);

  try{
    string d = get(a, -1);
  } catch (exception& e){
    cout << "(Index out of range and function threw an error)";
  }

  deallocate(a);

  cout << " get() passed\n";
}

void set_test(){
  cout << "Running set() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  set(a, 2, "dog");

  assert(a.arr[2] == "dog");

  try {
    set(a, 8, "carrot");
  } catch (exception& e){
    cout << "(Index out of range and function threw an error)";
  }

  deallocate(a);

  cout << " set() passed\n";
}

void add_right_test(){
  cout << "Running add_right_test() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  add_right(a, "dog");
  assert(a.arr[4] == "dog");
  add_right(a, "bird");
  assert(a.capacity == 10);
  assert(a.arr[5] == "bird");
  assert(a.size == 6);
  add_right(a, "snake");
  assert(a.arr[6] == "snake");

  deallocate(a);
  

  cout << " add_right_test() passed\n";
}

void operator_equal_test(){
  cout << "Running operator_equal_test() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  str_list b = make_new();

  b.arr[0] = "owl";
  b.arr[1] = "bug";
  b.arr[2] = "cow";
  b.arr[3] = "cat";
  b.size = 4;

  assert(a == b);

  deallocate(a);
  deallocate(b);

  cout << " operator_equal_test() passed\n";
}

void operator_not_equal_test(){
  cout << "Running operator_not_equal_test() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  str_list b = make_new();
  b.size = 5;

  assert(a != b);

  b.arr[0] = "owl";
  b.arr[1] = "bug";
  b.arr[2] = "chicken";
  b.arr[3] = "cat";

  assert(a != b);

  deallocate(a);
  deallocate(b);

  cout << " operator_not_equal_test() passed\n";
}

void clear_test(){
  cout << "Running clear_test() ... ";

  str_list a = make_new();

  a.arr[0] = "owl";
  a.arr[1] = "bug";
  a.arr[2] = "cow";
  a.arr[3] = "cat";
  a.size = 4;

  clear(a);

  assert(a.size == 0);

  deallocate(a);

  cout << " clear_test() passed\n";
}

void add_left_test(){
  cout << "Running add_left_test() ... ";

  str_list a = make_new();

  a.arr[0] = "up";
  a.arr[1] = "down";
  a.arr[2] = "mouse";
  a.size = 3;

  add_left(a, "cat");

  assert(a.arr[0] == "cat");

  deallocate(a);

  cout << " add_left_test() passed\n";
}

void shrink_to_fit_test(){
  cout << "Running shrink_to_fit_test() ... ";

  str_list a = make_new();

  a.arr[0] = "up";
  a.arr[1] = "down";
  a.arr[2] = "mouse";
  a.size = 3;

  shrink_to_fit(a);
  assert(a.size == a.capacity);

  assert(a.arr[2] == "mouse");

  deallocate(a);

  cout << " shrink_to_fit_test() passed\n";
}

void make_fromFile_test(){
  cout << "Running make_fromFile() ... \n";

  str_list arr = make_fromFile("test_small.txt");
  cout << arr.size << " words added\n";
  writeln(arr);

  cout << " make_fromFile() passed\n";
  deallocate(arr);

}

void avg_size_test(){
  cout << "Running avg_size_test() ... ";

  str_list a = make_new();

  a.arr[0] = "up";
  a.arr[1] = "do";
  a.arr[2] = "cat";
  a.arr[3] = "dog";
  a.size = 4;

  double average = avg_size(a);

  double test = 2.5;

  assert(average == test);

  deallocate(a);

  cout << " avg_size_test() passed\n";
}

void append_test(){
  cout << "Running append_test() ... ";

  str_list a = make_new();

  a.arr[0] = "once";
  a.arr[1] = "upon";
  a.arr[2] = "a";
  
  a.size = 3;

  str_list b = make_new();

  b.arr[0] = "time";
  b.arr[1] = "Bob";
  b.arr[2] = "wondered";
  b.size = 3;

  str_list c = append(a,b);

  assert(c.arr[3] == "time");
  assert(c.arr[1] == "upon");
  assert(c.arr[4] == "Bob");
  assert(c.size == 6);


  deallocate(a);
  deallocate(b);
  deallocate(c);

  cout << " append_test() passed\n";
}


int main() {
  cout << "Assignment 1!\n";

  //
  // ... call your test functions here ...
  //

  make_new_test();
  deallocate_test();
  clone_test();
  to_str_test();
  get_test();
  set_test();
  add_right_test();
  operator_equal_test();
  operator_not_equal_test();
  add_left_test();
  make_fromFile_test();
  avg_size_test();
  append_test();

}
