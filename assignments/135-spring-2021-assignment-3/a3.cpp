// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jusitn Chiang
// St.# : 301431456
// Email: jpc13@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    // These are the only permitted includes!
#include "Chatbot.h"       //
#include <iostream>        // Don't include anything else.
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <ctime>     
#include <cassert>

using namespace std;

//
// ... write your code here here ...
//

class Mirror_bot : public Chatbot{

  string botName;
  string reply;

public:

  Mirror_bot(const string& name, const string& firstReply) : botName(name), reply(firstReply) { }

  string name() const { return botName; }

  void tell(const string& s){
    reply = s;
  }

  string get_reply() { return reply; }

};

class Random_bot : public Chatbot {

  string botName;
  vector<string> reply;

  vector<string> readResponseFromFile(string fileName){

    ifstream file;
    file.open(fileName);

    if (file.fail()){
      cmpt::error("File not found\n");
    }

    string line;
    vector<string> inputList;
    while(getline(file, line)){

      inputList.push_back(line);

    }

    if (inputList.empty()){
      cmpt::error("Vector is empty!\n");
    }

    return inputList;

  }

public:

  Random_bot(const string& name, vector<string> inputList) 
  : botName(name), reply(inputList){ 
    if (inputList.empty()){
      cmpt::error("Vector is empty!\n");
    } 
  }

  Random_bot(const string& name, const string& fileName) 
  : botName(name), reply(readResponseFromFile(fileName)) { }

  string name() const {return botName;}

  string get_reply(){ 

    int randNum = ((rand() % reply.size() - 1) + 1);
    
    return reply.at(randNum);

  }

  void tell(const string& s){

    (void)s;

  }


};

class User_bot : public Chatbot{

  string botName;
  string reply;

public:

  User_bot(const string& name) : botName(name) { };

  string name() const { return botName; }

  void tell(const string& s ){

    (void)s;
    cout << reply << endl;

  }

  string get_reply(){ 
    string input;
    cin >> input;
    reply = input;
    return input;
  }

};

class Datetime_bot : public Chatbot {

  string botName;
  vector<string> reply;

  bool searchDateOrTime(const string& s){

    string word;

    for (char c : s){

      
      
    }

  }

public:

  Datetime_bot(const string& name, vector<string> replies) 
    : botName(name), reply(replies){ };

  string name() const{ return botName;}

  void tell (const string& s ){



  }

  string get_reply(){



  }



};

// converse is a helper functuin that you can use if you like. You are free to
// modify it if you want to.
void converse(Chatbot* a, Chatbot* b, int max_turns = 50) {
  for(int turn = 1; turn <= max_turns; turn++) {
    string a_msg = a->get_reply();
    cout << "(" << turn << ") " << a->name() << ": " << a_msg << "\n";
    
    turn++;
    if (turn > max_turns) return;

    b->tell(a_msg);
    string b_msg = b->get_reply();

    cout << "(" << turn << ") " << b->name() << ": " << b_msg << "\n";
    a->tell(b_msg);
  } // for
}

int main() {
  //
  // ... put code for testing your functions here ...
  //
  srand(time(nullptr));

  // Chatbot* mBot = new Mirror_bot("repeato", "repeato is ready to go!");
  Chatbot* rBot = new Random_bot("rando", "dog_sounds.txt");
  Chatbot* uBot = new User_bot("stan");

  converse(rBot, uBot);



}
