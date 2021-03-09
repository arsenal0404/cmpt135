// challenge_7.cpp

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

int* getRowFromString(const string& s){

	int row[500];
	string number;
	int i = 0;
	while(true){
	
		for(char ch : s){
			if (ch == " "){
				i = stoi(number);
				number = "";
			} else {
				number.push_back(ch);
			}

		}	

	}

}

int** readFromFile(const string& fileName){

	ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.fail()){
		cmpt::error("Fail failed to open. Possibly wrong file name!");
	}

	int row[500];
	string line;
	while(getline(inputFile, line)){



	}


}

int main() {
	cout << "Challenge 7 ...\n";
	// ...

	int two_d_arrya[1000][500] = readFromFile("test.txt");
}
