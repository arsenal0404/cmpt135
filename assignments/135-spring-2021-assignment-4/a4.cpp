// a4.cpp

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

//Done by prof
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
		return true; // ensures that there won't be an out-of-range exception
	} else if (s.at(0) == s.at(1)){
		// returns a string that is from index 1 to end of original string
		return all_same(s.substr(1)); 
	} else {
		return false;
	}
}

bool all_digits(const string& s){
	if (s.size() == 0){
		return true; // Parses through all elements
	} else if (s.at(0) >= '0' && s.at(0) <= '9'){
		// returns a string that is from index 1 to end of original string
		return all_digits(s.substr(1)); 
	} else {
		return false;
	}
}

string ltrim(const string& s, int begin){
	string hold = s;
	if (begin < s.size() - 1){
		//checks the leading spaces and stops recursion when leading is found
		if (s.at(begin) == ' ' && s.at(begin + 1) != ' '){
			// s.substr(begin + 1) returns string without leading spaces
			hold = ltrim(s.substr(begin + 1), s.size() + 1); // s.size() + 1 breaks recursion
		} else {
			hold = ltrim(s, begin + 1); // Parses from left side to find all spaces
		}
	}
	return hold;
}

string rtrim(const string& s, int begin){
	string hold = s;
	if (begin > 0){
		//checks the trailing spaces and stops recursion when leading is found
		if (s.at(begin) == ' ' && s.at(begin - 1) != ' '){
			// removes all trailing spaces and stops recursion
			hold = rtrim(hold.erase(begin), -1);
		} else {
			hold = rtrim(s, begin - 1);
		}
	}
	return hold;
}

string trim(const string& s){
	string hold = s;
	// handles empty string
	if (!s.empty()){
		hold = ltrim(s, 0);
		hold = rtrim(hold, hold.size() - 1);
	} else {
		hold = "";
	}

	return hold;
}

int sum_neg(const vector<int>& v){
	// removes last element from v
	vector<int> tmp = v;
	tmp.pop_back();
	if (v.empty()){
		return 0; // base case;
	} else if (v.at(v.size() - 1) < 0){
		// adds all number according to condition
		return v.at(v.size() - 1) + sum_neg(tmp);
	} else {
		return sum_neg(tmp);
	}

}

vector<int> min_vec(const vector<int>& a, const vector<int>& b, int begin){
	// pre-condition
	assert(a.size() == b.size());
	assert(a.size() > 0);
	vector<int> tmp1 = a;

	if (begin >= a.size()){
		return tmp1;
	} else {
		tmp1.at(begin) = min(a.at(begin), b.at(begin));
		// uses first perameter to store answers
		return min_vec(tmp1,b, begin + 1);
	}
}

// overloaded function to allow indexing
vector<int> min_vec(const vector<int>& a, const vector<int>& b){
	return min_vec(a, b, 0);
}

int count(const vector<string>& v, const string& s, int begin){
	// This returned a segmentation fault
	// Keeping it as a reminder/showing my thought process for this question

	// vector<string> tmp = v;
	// tmp.pop_back();
	// if (v.empty()){
	// 	return 0;
	// } else if (v.at(v.size() - 1) == s){
	// 	return 1 + count(tmp, s);
	// } else {
	// 	return count(tmp, s);
	// }

	if (begin == v.size()){
		return 0; // base case
	} else if (v.at(begin) == s){
		// checks vector for matching strings
		return 1 + count(v,s,begin + 1);
	} else {
		return count(v,s,begin + 1);
	}
}

//overloaded function to implement indexing
int count(const vector<string>& v, const string& s){
	return count(v,s,0);
}


vector<string> zip(const string& s, const string& t, int end){
	assert(s.size() == t.size());
	vector<string> tmp;
	//puts the first char of both string together
	string hold;
	hold.push_back(s.at(end));
	hold.push_back(t.at(end));

	if (end > 0){
		//recursion goes from 0 - s.size()
		tmp = zip(s,t,end - 1);
	}

	//puts final string into vector
	tmp.push_back(hold);
	return tmp;
}

//overloaded to implement indexing
vector<string> zip(const string& s, const string& t){
	return zip(s, t, s.size() - 1);
}

string join(const vector<string>& v, const string& sep, int begin){
	//similar to zip but adds strings in v with given seperator

	string hold;
	if (begin == 0){
		//ensure proper formatting 
		hold.append(v.at(begin));
	} else {
		// adds to string with seperator 
		hold.append(sep);
		hold.append(v.at(begin));
	}
	
	if (begin < v.size() - 1){
		//joins all string together
		hold += join(v, sep, begin + 1);
	}

	return hold;
}

//overloaded to implement indexing
string join(const vector<string>& v, const string& sep){
	return join(v, sep, 0);
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

void sum_neg_test(){
	cout << "Testing sum_neg ... ";
	vector<int> v;
	assert(sum_neg(v) == 0);
	v = {2,5,-3,-7,5,-4};
	assert(sum_neg(v) == -14);
	v = {2,-3,5,-4, 6, 3, -3};
	assert(sum_neg(v) == -10);
	cout << "all sum_neg tests passed!\n";
}

void min_vec_test(){
	cout << "Testing min_vec ... ";
	vector<int> a {3, 4, 1};
	vector<int> b {2, 5, 2};
	vector<int> c {2, 4, 1};
	assert(min_vec(a,b) == c);
	cout << "all min_vec tests passed!\n";
}

void count_test(){
	cout << "Testing count ... ";
	vector<string> v {"abc", "abc", "abcd", "abcd", "abc"};
	assert(count(v, "abc") == 3);
	cout << "all count tests passed!\n";
}

void zip_test(){
	cout << "Testing zip ... ";
	vector<string> v = {"ax", "by", "cz"};
	assert(zip("abc", "xyz") == v);
	cout << "all zip tests passed!\n";
}

void join_test(){
	cout << "Testing join ... ";
	assert(join({"cat", "dog", "house"}, ", ") == "cat, dog, house");
	assert(join({"he", "we", "see"}, "") == "hewesee");
	assert(join({"abc", "abc", "abcd"}, "/") == "abc/abc/abcd");
	cout << "all join tests passed!\n";
}
