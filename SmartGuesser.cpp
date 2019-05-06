#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include "calculate.hpp"

using namespace std;

uint length;
int bulls;
int cows;
int i;//represent the numbers 0 - 9 of the guess
int numChar;//represent the number of char we guessed right
int guessArray [4];//will contain all the chars the appear for sure in the answer
int indexArray;//will use as an index to guessArray
vector<string> guessVec;//will contain all the possible combinations 
string gues;//temp guess which will be added to guessVec
int resIndex;//will go through the results in guessVec
bool notPermuted; //will tell us if we already permuted all the options from the chars we got.





bullpgia::SmartGuesser::SmartGuesser(){ 
   i=-1;
   numChar=0;
   for(int l = 0; l<4; l++) guessArray[l]=0;
   indexArray=0;
   resIndex=0;
   notPermuted=true; 
   bulls=0;
   cows=0;
   length=0;
}

string bullpgia::SmartGuesser::guess() {
//updating the results from the previous guess first, if we havn't got all the chars yet
cout<<"this is bulls:    "<<bulls<<endl<<"  this is cow:    "<<cows<<endl;
 if(numChar<length) saveResults();

 if(i<9&&numChar<length){//trying 1111, 2222, till 9999
   i++;
   string firstGuess = std::to_string(i);
   int j = 1;
   while(j<length){//concatenating the i to itelf to match the length of the guess
	firstGuess+=std::to_string(i);
	j++;
   }
cout<<"this is FIRSTGUESS:  "<< firstGuess<<" this is LENGTH: " << length<<endl;
   return firstGuess;
 }
	gues="";
if(numChar==length){
 //take the guess array and convert it to string according to it's size
  for(int m = 0; m<length;m++){
	gues+=std::to_string(guessArray[m]);
	cout<<"this is gues array number :"<<m<<"     "<< guessArray[m]<<endl;
 }
	numChar++;
}

//cout<<"THIS IS GUESS:"<<gues<<endl;
//send it to permute
  if(notPermuted&&numChar==length+1){
  	permute(gues, "");
	notPermuted=false;
	//cout<<"THIS IS GUESSVEC SIZE "<< guessVec.size()<<endl;
  }
  if(resIndex<guessVec.size()&&numChar==length+1) {
  cout<<"this is the guess AFTER PERMUTE number  "<<resIndex<<"  and the guess IS  "<<guessVec.at(resIndex)<<endl;
  return guessVec.at(resIndex++);
}
//cout<<"this is numChar "<< numChar<<" this is length : "<<length<<endl;
//cout<<"this is resIndex " <<resIndex<< " this is guessVecSize " << guessVec.size()<<endl;
//cout<<"EMPTY STRING"<<endl;
  return "";

}

void bullpgia::SmartGuesser::permute(string str, string out) 
{ 
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 
        guessVec.push_back(out); 
        return; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int m = 0; m < str.size(); m++) 
    { 
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]); 
  
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
} 

//updating the resultes from bull and pgia
void bullpgia::SmartGuesser::saveResults(){

 int k = 0;
 while(k<bulls){
cout<<"THIS IS BULLS: " <<i<<endl;
	guessArray[indexArray++] = i;

	k++;
	numChar++;
 }
 k=0;
 while(k<cows){
cout<<"THIS IS COWS: " <<i<<endl;
	guessArray[indexArray++]= i;
	k++;
	numChar++;
 }
}

void bullpgia::SmartGuesser::startNewGame(uint slength){
	if(slength<=4)
	  length=slength;
        guessVec.clear();
	gues="";
	bulls=0;
	cows=0;
	resIndex=0;
   	i=-1;
}
void bullpgia::SmartGuesser::learn(string reply){
  // cout<<"this is reply:  "<<reply<<endl;
    int sign= reply.find(',');
    bulls = stoi(reply.substr(0,sign));
    cows = stoi(reply.substr(sign+1,reply.length()));

}
