#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
#include <iostream>
#include <sstream>
using std::string;


string bullpgia::SmartGuesser::guess() {
 return "";
}
void bullpgia::SmartGuesser::startNewGame(uint length){

}
void bullpgia::SmartGuesser::learn(string reply){
 
    int sign= reply.find(",");
    int bulls = stod(reply.substr(0,sign));
    int cows = stod(reply.substr(sign+1,reply.length()-1));
    cout<<bulls;
    cout<<cows;

}
