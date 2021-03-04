// challenge_1.cpp

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

//Reads the file and gets numbers equal to or lower than the given number
vector<int> getSortedNumberList(){
	
	ifstream numberFile;
	numberFile.open("numbers1.txt");
	if (numberFile.fail()){
		cout << "Unable to read file.\n";
		exit(EXIT_FAILURE);
	}


	vector<int> numberList;
	while(true){
		int number;
		numberFile >> number;
		if (numberFile.fail()){
			break;
		}
		if (number <= 12345){
			numberList.push_back(number);
		} 
		
	}

	//Built in sorting to make finding permutations more efficient
	// sort(numberList.begin(), numberList.end());

	return numberList;
}

//Gets all possible sets including all the different orders 
vector<int*> getSetsOfThree(const vector<int> &numberList){

	vector<int*> list; 
	for (int a : numberList){
		for (int b : numberList){
			for (int c : numberList){
				if ((a + b + c) == 12345 && (a != b) && (b != c) && (a != c)){
					int* set = new int[3];
					set[0] = a;
					set[1] = b;
					set[2] = c;
					
					list.push_back(set);
					
				}
			}
		}
	}

	return list;

} 

//Tested the example give to check that the output is the same
vector<int*> test(){
	vector<int> numberList;
	numberList.push_back(4);
	numberList.push_back(1);
	numberList.push_back(2);
	numberList.push_back(9);
	numberList.push_back(3);
	numberList.push_back(6);
	numberList.push_back(11);


	vector<int*> list; 
	for (int a : numberList){
		for (int b : numberList){
			for (int c : numberList){
				if (a + b + c == 15 && (a != b) && (b != c) && (a != c)){
					int* set = new int[3];
					set[0] = a;
					set[1] = b;
					set[2] = c;
					
					list.push_back(set);
					
				}
			}
		}
	}

	return list;

} 

//Cleans up set where the order does not matter
vector<int*> getExactSet(const vector<int*> &setList){

	vector<int*> list; 

	for (int* set : setList){
		
		if (list.empty()){

			list.push_back(set);

		} else {

			bool first = false;
			bool second = false;
			bool third = false;
			
			//Ugg so many for-loops
			for (int* check : list){
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++){
						
						if (set[i] == check[j]){
							if (i == 0){
								first = true;
							} else if (i == 1){
								second = true;
							} else if (i == 2){
								third = true;
							}
						} 

					}
				}
			}

			if (!(first && second && third)){
				list.push_back(set);
			}		
		}
	}

	return list;

}

void printResults(const vector<int*> &list){
	for (int* set : list){
		for (int i = 0; i < 3; i++){
			if (i == 2){
				cout << set[i] << endl;
			} else {
				cout << set[i] << ", ";
			}
			
		}
	}
	
	cout << "Number of sets: " << list.size() << endl;
}

int main() {

	cout << "Challenge 1 ...\n";
	// ...

	//Eneded up creating multiple vectors, possible with just one vector where
	//you pop the set off 
	vector<int> sortedNumber = getSortedNumberList();
	
	vector<int*> setList = getSetsOfThree(sortedNumber);
	vector<int*> finalList = getExactSet(setList);

	vector<int*> testList = test();
	vector<int*> finalTest = getExactSet(testList);
	
	printResults(setList);
	printResults(finalList);
}