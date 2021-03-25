// challenge_9.cpp

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

/////////////////////////////////////////
////////////Sort String//////////////////
/////////////////////////////////////////

void swap(char& x, char& y) {
    int temp = x;
    x = y;
    y = temp;
}

// returns index of the final location of pivot value
int partition(string& s, int begin, int end) {
    int p = begin;
    for (int i = begin + 1; i < end; ++i) {            
        if (s[i] <= s[p]) {
            swap(s[i], s[p + 1]);
            swap(s[p], s[p + 1]);
            ++p;
        }
    }
    return p;
}

// re-arranges the elements from v[begin] to v[end - 1] such that
// v[begin] <= v[begin + 1] <= ... <= v[end - 1]
void quicksort(string& s, int begin, int end) {
    const int n = end - begin;
    if (n <= 1) return;
    int p = partition(s, begin, end);
    quicksort(s, begin, p);
    quicksort(s, p + 1, end);
}

void quicksort(string& s) {
    quicksort(s, 0, s.size());
}
//////////////////////////////////////////
//////////////Sort array//////////////////
//////////////////////////////////////////

void swap(string& x, string& y) {
    string temp = x;
    x = y;
    y = temp;
}

// returns index of the final location of pivot value
int partition(string arr[] , int begin, int end) {
    int p = begin;
    for (int i = begin + 1; i < end; ++i) {            
        if (arr[i] <= arr[p]) {
            swap(arr[i], arr[p + 1]);
            swap(arr[p], arr[p + 1]);
            ++p;
        }
    }
    return p;
}

// re-arranges the elements from v[begin] to v[end - 1] such that
// v[begin] <= v[begin + 1] <= ... <= v[end - 1]
void quicksort(string arr[], int begin, int end) {
    const int n = end - begin;
    if (n <= 1) return;
    int p = partition(arr, begin, end);
    quicksort(arr, begin, p);
    quicksort(arr, p + 1, end);
}

void quicksort(string arr[], int size) {
    quicksort(arr, 0, size);
}

string* getStringFromFile(const string& fileName, int size){
	string* strArr = new string[size];

	ifstream file;
	file.open(fileName);

	if (file.fail()){
		cmpt::error("Couldn't get file! Check name!");
	}

	string line;
	int i = 0;
	while(getline(file, line)){
		strArr[i] = line;
		i++;
	}
	file.close();
	return strArr;
}

int binary_search(string x, string arr[], int begin, int end) {
	while (begin < end) {
		int mid = (begin + end) / 2;
		if (arr[mid] == x) {          // found x!
		return mid;
		} else if (x < arr[mid]) {
		end = mid;
		} else if (x > arr[mid]) {
		begin = mid + 1;
		}
	}
	return -1;                    // x not found
}

int linear_search(string x, string arr[], int begin, int end){
	for (int i = begin; i < end; i++){
		if (x == arr[i]){
			return i;
		}
	}

	return -1;
}


int main() {
	cout << "Challenge 9 ...\n";
	// ...

	int size = 79307; 
	string* strArr = getStringFromFile("words9.txt", size);

	string sortedStr[size]; 
	for (int i = 0; i < size; i++){
		sortedStr[i] = strArr[i];
	}
	for (int i = 0; i < size; i++){
		quicksort(sortedStr[i]);
	}

	string sortedArr[size];
	for (int i = 0; i < size; i++){
		sortedArr[i] = sortedStr[i];
	}
	// for (int i = 0; i < size; i++){
	// 	cout << strArr[i] << endl;
	// }
	
	quicksort(sortedArr, 0, size);
	// cout << sortedArr[50000 - 1] << endl;
	
	cout << strArr[linear_search(sortedArr[50000 - 1], sortedStr, 0, size)] << endl;
}
