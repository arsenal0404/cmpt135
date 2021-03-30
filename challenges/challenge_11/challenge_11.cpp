// challenge_11.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

//
// ... add any helper functions (write them yourself!) here ...
//

int checkRow(char* row, int size, const char& c){
	int sum = 0;
	for (int i = 0; i < size; i++){
		if (row[i] == c){
			sum += 1;
		}
	}

	return sum;
}

int check_qwerty_letter(const char& s){
	char first_row[] = {'q', 'w', 'e',
            'r', 't', 'y', 'u', 'i',
            'o', 'p'};
	char second_row[] = {'a', 's', 'd', 'f',
            'g', 'h', 'j', 'k', 'l'};
	char third_row[] = {'z', 'x', 'c', 'v',
            'b', 'n', 'm'};

	if (checkRow(first_row, 10, s) > 0){
		return 1;
	} else if (checkRow(second_row, 9, s) > 0){
		return 2;
	} else if (checkRow(third_row, 7, s) > 0){
		return 3;
	} 

	return 0;
}

bool checkString(const string& str){
	char c = str[0];
	int row = check_qwerty_letter(c);
	for (int i = 0;i < str.length(); i++){
		c = str[i];
		if (row != check_qwerty_letter(c)){
			return false;
		}
	}
	return true;
}

void checkFile(const string& fileName){
	ifstream file;
	file.open(fileName);
	if (file.fail()){
		cmpt::error("File could not be opened! Check name!\n");
	}

	int sum = 0;
	string line;
	while (getline(file, line)){
		if (checkString(line)){
			sum += 1;
		}
	}

	cout << "The amount of qwerty words is: " << sum << "!\n";
}

int main() {
	cout << "Challenge 11 ...\n";
	// ...

	//answer == 755 words
	string fileName = "words11.txt";
	checkFile(fileName);
}
