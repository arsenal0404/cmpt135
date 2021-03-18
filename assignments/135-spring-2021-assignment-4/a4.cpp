// a4.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <put your full name here!>
// St.# : <put your full SFU student number here>
// Email: <put your SFU email address here>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "a4.h"  // no other includes are allowed!

using namespace std;

//
// Put your implementations of the functions specified in "a4.h" here.
//

//
// Don't put main() in this file. It goes in a4_main.cpp.
//

int sum_of_squares(int n) {
	assert(n >= 0);
	if (n == 0) {
		return 0;
	} else {
		return n*n + sum_of_squares(n - 1);
	}
}


int sum_strange(int n){
	assert(n > 0);
	if (n < 2){  // base case
		return 0;
	} else if (n % 3 == 0 && n % 5 != 0){
		//adds one when condition is true
		return 1 + sum_strange(n - 1);
	} else {
		//does nothing when condition is false
		return sum_strange(n - 1);
	}
}

bool all_same(const string& s){
	if (s.size() <= 1){
		return true;
	} else if (s.at(0) == s.at(1)){
		// returns a string that is from index 1 to end of original string
		return all_same(s.substr(1)); 
	} else {
		return false;
	}
}

bool all_digits(const string& s){
	if (s.size() == 0){
		return true;
	} else if (s.at(0) >= '0' && s.at(0) <= '9'){
		// returns a string that is from index 1 to end of original string
		return all_digits(s.substr(1)); 
	} else {
		return false;
	}
}

string trim(const string& s){



}



///////////////////////////////////////////////////////////////////////////////
////////////////////////////////Tests//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void sum_of_squares_test(){
	cout << "Testing sum_of_squares ... ";
	assert(sum_of_squares(3) == 14);
    assert(sum_of_squares(5) == 55);

	cout << "all sum_of_squares tests passed!\n";
}

void sum_strange_test(){
	cout << "Testing sum_strange ... ";
	assert(sum_strange(20) == 5);
	assert(sum_strange(30) == 8);
	assert(sum_strange(50) == 13);
	cout << "all sum_strange tests passed!\n";
}

void all_same_test(){
	cout << "Testing all_same ... ";
	assert(all_same("ssssss") == true);
	assert(all_same("asdfa") == false);
	assert(all_same("33333333333") == true);
	assert(all_same("hji897") == false);
	assert(all_same("") == true);
	cout << "all all_same tests passed!\n";
}

void all_digits_test(){
	cout << "Testing all_digits ... ";
	assert(all_digits("234572345") == true);
	assert(all_digits("") == true);
	assert(all_digits("ajikhklaj") == false);
	assert(all_digits("987h89789") == false);
	cout << "all all_digits tests passed!\n";
}

void trim_test(){
	cout << "Testing trim ... ";
	assert(trim("  ab c  d ") == "ab c  d");
	assert(trim("") == "");
	assert(trim("   456 2 d 3 w asdf 23dg1      ") == "456 2 d 3 w asdf 23dg1");
	cout << "all trim tests passed!\n";
}
