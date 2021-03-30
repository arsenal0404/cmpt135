// challenge_10.cpp

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

//n.size() == 3

// answer = 12335547

void cleanUpString(string& s){

	for (int i = 0; i < s.length(); i++){
		if (s.at(i) != '0' && !(s.at(0) >= '1' && s.at(0) <= '9')){
			s.erase(0, i);
			break;
		}
	}

}

vector<int> getPermutations(const int& n){	
	string hold = to_string(n);
	string permute = hold;
	vector<int> permutations;
	
	if (hold.size() > 1){
		permutations.push_back(stoi(permute));
		for (int i = 0; i < hold.size(); i++){
			permute.erase(permute.begin() + i);
			cleanUpString(permute);
			permutations.push_back(stoi(permute));
			permute = hold;
		}
	}

	return permutations;
}

bool isPrime(const int& n){
	if (n <= 1){
		return false;
	} 

	for (int i = 2; i <= n / 2; i++){
		if (n % i == 0){
			return false;
		}
	}

	return true;
}

bool isToughPrime(int n){
	vector<int> permutations = getPermutations(n);
	if (!permutations.empty()){
		for (int i : permutations){
			if (!isPrime(i)){
				return false;
			}
		}
	}

	if (n < 10){
		return false;
	}

	return true;
}

int sum_of_tough_prime(int n){
	int sum = 0;

	for (int i = 1; i <= n; i++){
		if (isToughPrime(i)){
			sum += i;
		}
	}

	return sum;
}

int main() {
	cout << "Challenge 10 ...\n";
	// ...

	int sum = sum_of_tough_prime(1000000);
	cout << sum << endl;

}
