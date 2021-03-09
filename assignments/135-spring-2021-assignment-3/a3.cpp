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
    getline(cin, input);
    reply = input;
    return input;
  }

};

class Datetime_bot : public Chatbot {

  string botName;
  vector<string> standardReply;
  string input;

  string upperCase(string &input) {
    for (int i = 0; i < input.length(); i++) {
      input[i] = toupper(input[i]);
    }
    return input;
  }

  //foudn this function for getting the time for time
  //https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
  //credit goes to TrungTN 
  const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


public:

  Datetime_bot(const string& name, vector<string> replies) 
    : botName(name), standardReply(replies){ };

  string name() const{ return botName;}

  void tell (const string& s ){

    input = s;

  }

  string get_reply(){

    //Checks if the words "date" or "time" are in the string.
    if (upperCase(input).find("DATE") != string::npos || upperCase(input).find("TIME") != string::npos){
      return "The current date and time is: " + currentDateTime();
    } else {
      int randNum = ((rand() % standardReply.size() - 1) + 1);
      return standardReply.at(randNum);
    }

  }
};

class Turing_bot : public Chatbot {

  string botName;
  string reply;
  vector<string> emotionalSupport;
  string response;

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

  const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
  }

  string upperCase(string &input) {
    for (int i = 0; i < input.length(); i++) {
      input[i] = toupper(input[i]);
    }
    return input;
  }

  bool contains(string search){

    if (upperCase(reply).find(upperCase(search)) != string::npos){
      return true;
    } else {
      return false;
    }
  }

  void addToFile(string fileName, string s){

    ofstream file;
    file.open(fileName);
    
    if (file.fail()){
      cmpt::error("File not found!\n");
    }

    file << s;

    file.close();

  }

public: 

  Turing_bot(const string&name)
  : botName(name){ 

    emotionalSupport = readResponseFromFile("emotional_support.txt");

  };

  string name() const { return botName;}

  void tell (const string& s){

    reply = s;

  }

  string get_reply(){

    if (contains("hello") || contains("hey")){
      response = "Greetings adventurer";
    } else if (contains("weather")){
      response = "Knowing Vancouver, or should I say Raincover, it is probably raining";
    } else if (contains("name") && contains("your")){
      response = "My name is " + botName + ". I would ask for your name, "
      + "but I am really bad with names and forget anyways";
    } else if (contains("how") && contains("are") && contains("you")){
      response = "Pretty down bad. Spent a long time trying to create a simple bot";
    } else if (contains("what") && contains("games") && contains("play")){
      response = "Just some league of legends, minecraft, and a new game called valheim";
    } else if (contains("am") && contains("sad")){
      int randNum = ((rand() % emotionalSupport.size() - 1) + 1);
      response = emotionalSupport.at(randNum);
    } else if (contains("date") || contains("time")){
      response = "The current date and time is: " + currentDateTime();
    } else {

      response = "I didn't understand that, do you mind repeating that!";
    }

    return response;

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

// void converseUser(Chatbot* a, Chatbot* b, int max_turns = 50) {
//   for(int turn = 1; turn <= max_turns; turn++) {
//     string a_msg = a->get_reply();
//     cout << "(" << turn << ") " << a->name() << ": " << a_msg << "\n";
    
//     turn++;
//     if (turn > max_turns) return;

//     b->tell(a_msg);
//     string b_msg = b->get_reply();

//     cout << "(" << turn << ") " << b->name() << ": " << b_msg << "\n";
//     a->tell(b_msg);
//   } // for
// }

int main() {
  //
  // ... put code for testing your functions here ...
  //
  srand(time(nullptr));

  // Chatbot* mBot = new Mirror_bot("repeato", "repeato is ready to go!");
  // Chatbot* rBot = new Random_bot("rando", "dog_sounds.txt");
  Chatbot* uBot = new User_bot("stan");
  // Chatbot* dBot = new Datetime_bot("deetee", {"Ask me about the date or time!", 
  //                                             "I know the date and time!"});
  Chatbot* tBot = new Turing_bot("Alan");


  converse(uBot, tBot);


}
