// challenge_4.cpp

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

vector<string> getItemsFromFile(const string &filename){

	ifstream file;
	file.open(filename);

	if(file.fail()){
		cout << "Could not read file \n";
		exit(EXIT_FAILURE);
	}

	vector<string> items;

	while(true){
		string word; 
		file >> word;
		if(file.fail()){
			break;
		}
		items.push_back(word);
	}

	return items;

}

vector<string> getUniqueItems(vector<string> items){

	vector<string> uniqueItems; 
	
	for (string item : items){
		bool isUnique = true;
		if (uniqueItems.empty()){
			uniqueItems.push_back(item);
		} else {
			for (string uniqueItem : uniqueItems){
				if (uniqueItem == item){
					isUnique = false;
				}
			}

			if(isUnique){
				uniqueItems.push_back(item);
			}
		}
	}

	return uniqueItems;

}

void printOccurances(const vector<string> &items, const vector<string> &uniqueItems){


	for (string uniqueItem : uniqueItems){
		unsigned int counter = 0;

		for (string item : items){
			if (uniqueItem == item){
				counter ++;
			}
		}

		if (counter > 12){
			cout << counter << "  " << uniqueItem << "\n"; 
		}

		// cout << counter << "  " << uniqueItem << "\n"; ;
		
	}

}

void usingArraysToPrint(const vector<string> &items, const vector<string> &uniqueItems){


	int* count;
	count = new int[uniqueItems.size()];

	for (int i = 0; i < uniqueItems.size(); i++){
		count[i] = 0;

		for (string item : items){
			if (uniqueItems.at(i) == item){
				count[i] += 1;
			}
		}

	}

	for (int i = 0; i < uniqueItems.size(); i++){


		if (count[i] > 12){
			cout << count[i] << "  " << uniqueItems.at(i) << "\n";
		}
		
	}

	delete[] count;
}



int main() {
	cout << "Challenge 4 ...\n";
	// ...

	vector<string> items = getItemsFromFile("baskets.txt");
	vector<string> uniqueItems = getUniqueItems(items);

	// for (string item : uniqueItems){
	// 	cout << item << "\n";
	// }

	printOccurances(items, uniqueItems);
	cout << "--------------------------------" << endl;
	usingArraysToPrint(items, uniqueItems);



}
