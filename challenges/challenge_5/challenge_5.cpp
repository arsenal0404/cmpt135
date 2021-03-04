// challenge_5.cpp

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

double get_min(const vector<double>& numList){
	double smallest = numList.at(0);

	for (double i : numList){
		if (i < smallest){
			smallest = i;
		}
	}

	return smallest;
}

double get_max(const vector<double>& numList){
	double largest = numList.at(0);

	for (double i : numList){
		if (i > largest){
			largest = i;
		}
	}

	return largest;
}

vector<string> split(const string& line, char delimiter){

	vector<string> splitItems;
	string item;

	for (int i = 0; i < line.size(); i++){

		if (line.at(i) != delimiter && i != line.size() - 1 && line.at(i) != ' '){

			item.push_back(line.at(i));

		} else if (i == line.size() - 1){

			item.push_back(line.at(i));
			splitItems.push_back(item);
			item = "";

		} else if (line.at(i) == delimiter){

			splitItems.push_back(item);
			item = "";

		}

	}

	return splitItems;

}

void find(string fileName){
	ifstream file;
	file.open(fileName);

	if (file.fail()){
        cout << "Unable to read file. \n";
        exit(EXIT_FAILURE);
    }

	vector<double> overallMin;
	vector<double> overallMax;

	string line;

	while (getline(file, line)){

		vector<double> numbers;
		
		vector<string> itemsInLine = split(line, ',');

		for (string i : itemsInLine){

			double number; 
			number = stod(i);
			numbers.push_back(number);

		}

		overallMax.push_back(get_max(numbers));
		overallMin.push_back(get_min(numbers));

	}

	double max = get_max(overallMin);
	double min = get_min(overallMax);

	cout << "The minimum of the maximums is: " << min << "\n";
	cout << "The maximums of the minimums is: " << max << "\n";

}



int main() {
	cout << "Challenge 5 ...\n";
	// ...

	// vector<double> list = {2.09, 4, 3.72, -2.3};

	// double smallest = get_min(list);
	// cout << smallest << endl;

	// double largest = get_max(list);
	// cout << largest << endl;

	find("numbers5.txt");

}
