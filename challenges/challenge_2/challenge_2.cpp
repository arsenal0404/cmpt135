// challenge_2.cpp

//
// You may use only the following #includes in your code:
//
#include "cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
//
// You don't need to use them all, but you can't use any others. Don't change
// these in any way.

using namespace std;

//
// ... add any helper functions (write them yourself!) here ...
//

bool ifExactlyThreeNines(int number){

	int count = 0;

	while (number != 0){
		int checkNumber = number % 10;
		if (checkNumber == 9){
			count++;
		}
		number /= 10;
	}

	if (count == 3){
		return true;
	} else {
		return false;
	}

}

unsigned long int getSumThreeNineInAMillion(){

	unsigned long int sum = 0;


	for(int i = 1; i < 1000000; i++){
		if (ifExactlyThreeNines(i)){
			sum += i;
		}
	}

	return sum;
}

void ifExactlyThreeNines_test(){


	for (int i = 100000; i < 1000000; i++){
		if (ifExactlyThreeNines(i)){
			cout << i << endl;
		}
	}

}


int main() {
	cout << "Challenge 2 ...\n";
	// ...

	// ifExactlyThreeNines_test();

	unsigned long int num = getSumThreeNineInAMillion();

	cout << "The sum: " << num << "\n";

}
