// challenge_3.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

//
// ... add any helper functions (write them yourself!) here ...
//


bool checkAllVowels(const string &str){

	bool a = false, e = false, i = false, o = false, u = false, y = false;

	for (char n : str){
		if (n == 'a'){
			a = true;
		} else if (n == 'e'){
			e = true;
		} else if (n == 'i'){
			i = true;
		} else if (n == 'o'){
			o = true;
		} else if (n == 'u'){
			u = true;
		} else if (n == 'y'){
			y = true;
		}
	}

	if (a && e && i && o && u && y ){
		return true;
	} else {
		return false;
	}

}

bool checkNoVowel(const string &str){

	bool a = false, e = false, i = false, o = false, u = false, y = false;

	for (char n : str){
		if (n == 'a'){
			a = true;
		} else if (n == 'e'){
			e = true;
		} else if (n == 'i'){
			i = true;
		} else if (n == 'o'){
			o = true;
		} else if (n == 'u'){
			u = true;
		} else if (n == 'y'){
			y = true;
		}
	}

	if (!a && !e && !i && !o && !u && !y ){
		return true;
	} else {
		return false;
	}

}



int main() {
	cout << "Challenge 3 ...\n";
	// ...

	string arr[172820];
	ifstream file; 
	file.open("enable1.txt");
	if (file.fail()){
		cout << "Could not read file\n";
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < 172820; i++){
		file >> arr[i];
	}

	signed long int allCount = 0;
	signed long int noCount = 0;

	for (string str : arr){
		if (checkAllVowels(str)){
			allCount++;
		} else if (checkNoVowel(str)){
			noCount++;
		}
	}

	cout << "The number of words that contain all the vowels is: " << allCount << "\n";
	cout << "The number of words that contain NO vowels is: " << noCount << "\n";
}
