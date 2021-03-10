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

int* getRowFromString(const string& s, int columns){

	int* row = new int[columns];
	
	int i = 0;

	for(char ch : s){

		if (ch != 32){
			row[i] = ch - '0';
			i++;
		} 

	}	

	return row;
}

void readFromFile(const string& fileName, int (&two_d_array)[1000][500], int columns){

	ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.fail()){
		cmpt::error("Fail failed to open. Possibly wrong file name!");
	}

	string line;
	int i = 0;
	while(getline(inputFile, line)){

		int* arr = getRowFromString(line, columns);
		for (int j = 0; j < columns; j++){
			two_d_array[i][j] = arr[j];
		}
		i++;
		delete[] arr;
		arr = NULL;
		
	}

	
	inputFile.close();
	
}

int* sumOfColumns(int (&two_d_array)[1000][500], int rows, int columns){

	int* columnSum = new int[columns];
	int currentSum;

	for (int i = 0; i < columns; i++){
		currentSum = 0;
		for (int j = 0; j < rows; j++){

			currentSum += two_d_array[j][i]; 

		}
		columnSum[i] = currentSum;
	}

	return columnSum;
}

void findGreatestSum(int *columnSums, int columns){
	int indexOfGreatestSum;
	int greatestSum = 0;

	for (int i = 0; i < columns; i++){

		if (greatestSum <= columnSums[i]){
			indexOfGreatestSum = i;
			greatestSum = columnSums[i];
		}

	}

	cout << "The column with the greatest sum is: " << indexOfGreatestSum + 1 << "\n";
	cout << "The sum of that column is: " << greatestSum << "\n";


}

int main() {
	cout << "Challenge 7 ...\n";
	// ...
	int rows = 1000;
	int columns = 500;
	int two_d_array[1000][500];
	readFromFile("bits_1000_500.txt", two_d_array, columns);

	// for (int i = 0; i < rows; i++){
	// 	for (int j = 0; j < columns; j++){

	// 		cout << two_d_array[i][j] << " ";

	// 	}

	// 	cout << endl;
	// }

	int* columnSums = sumOfColumns(two_d_array, rows, columns);
	cout << "--------------------------------\n";

	for (int i = 0; i < columns; i++){
		cout << "Sum of column " << i << ": " << columnSums[i] << endl;
	}

	findGreatestSum(columnSums, columns);

	delete[] columnSums;

}
