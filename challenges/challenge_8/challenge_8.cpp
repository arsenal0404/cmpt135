// challenge_8.cpp

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

const string PLUS = "+";
const string MINUS = "-";
const string MULTIPLY = "*";
const string ABSOLUTE = "@";

int solveString(const string &equation){
	int answer, output;
	string number, expression;
	vector<string> parts;

	for (int i = 0; i < equation.size(); i++){
		//32 is the ASCII value for a space
		if (equation.at(i) != 32 && i != equation.size() - 1){
			number.push_back(equation.at(i));
		} else if (i == equation.size() - 1) {
			number.push_back(equation.at(i));
			parts.push_back(number);
			number = "";
		} else if (equation.at(i) == 32){
			parts.push_back(number);
			number = "";
		}
	}

	for (int i = 0; i < parts.size(); i++){
		if (i == 0){
			output = stoi(parts.at(i));
			answer = output;
		} else if ((i % 2) == 1){
			expression = parts.at(i);
		} else {
			output = stoi(parts.at(i));
			if (expression == PLUS){
				answer += output;
			} else if (expression == MINUS){
				answer -= output;
			} else if (expression == MULTIPLY){
				answer *= output;
			} else if (expression == ABSOLUTE){
				answer = abs(answer) % abs(output);
			}
		}
	} 

	return answer;
}

int* solveFile(const string &fileName, int size){

	ifstream file;
	file.open(fileName);

	if(file.fail()){
		cmpt::error("Could not read file!\n");
	}

	int* answers = new int[size];
	string line;
	int i = 0;

	while(getline(file, line)){
		answers[i] = solveString(line);
		i++;
	}

	file.close();
	return answers;
}

int main() {
	cout << "Challenge 8 ...\n";
	// ...
	int size = 1000;
	int* answers = solveFile("expr1000.txt", size);
	int count = 0;

	for (int i = 0; i < size; i++) {
		// cout << "The answer for equation " << i + 1 << " is " << answers[i] << "\n";
		if ((answers[i] % 5) == 0){
			count++;
		}
	}

	delete[] answers;

	cout << count << " expressions evalute to a number that is a multiple of 5!\n";
}
