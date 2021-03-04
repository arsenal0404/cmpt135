// challenge_6.cpp

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

bool checkIndexUsed(vector<int> indexList, int index){
	for (int i : indexList){
		if (i == index){
			return false;
		}
	}
	return true;
}

int main() {
	cout << "Challenge 6 ...\n";
	// ...

	ifstream file;
	file.open("words6.txt");
	if (file.fail()){
		cout << "Failed to read file!\n";
		exit(EXIT_FAILURE);
	}

	int alphabet[26] = {0};
	string line;

	while (getline(file, line)){
		for (char ch : line){
			ch = toupper(ch);

			if (ch >= 'A' || ch <= 'Z'){
				alphabet[ch - 'A']++;
			}
		}
	}

	for (int i = 0; i < 26; i++){
		char aChar = 65 + i;
		cout << aChar << " is found: " << alphabet[i] << " times\n";
	}

	vector<int> orderedIndex;

	for (int i = 0; i < 26; i++){
		int largestValue = 0;
		int largestIndex;

		for (int j = 0; j < 26; j++){
			if (alphabet[j] > largestValue && checkIndexUsed(orderedIndex, j)){
				largestValue = alphabet[j];
				largestIndex = j;
			}
		}
		orderedIndex.push_back(largestIndex);
	}

	cout << "----------------------------------------------------------------\n";

	for (int i : orderedIndex){
		char aChar = 65 + i;
		cout << aChar << " is found: " << alphabet[i] << " times\n";
	}

}
