#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using std::string;

uint length;
int bulls;
int cows;
int i;//represent the numbers 0 - 9 of the guess
int numChar;//represent the number of char we guessed right
int guessArray [4];//will contain all the chars the appear for sure in the answer
int indexArray;//will use as an index to guessArray
vector<string> guessVec;//will contain all the possible combinations 
char *guess;//temp guess which will be added to guessVec
int resIndex;//will go through the results in guessVec
bool notPermuted; //will tell us if we already permuted all the options from the chars we got.




bullpgia::SmartGuesser::SmartGuesser(){ 
   i=-1;
   numChar=0;
   for(int l = 0; l<4; l++) guessArray[l]=0;
   indexArray=0;
   resIndex=0;
   notPermuted=true;
}

string bullpgia::SmartGuesser::guess() {
//updating the results from the previous guess first, if we havn't got all the chars yet
 if(numChar<length) saveResults();

 if(i<9&&numChar<length){//trying 1111, 2222, till 9999
   i++;
   string firstGuess = to_string(i);
   int j = 1;
   while(j<length){//concatenating the i to itelf to match the length of the guess
	firstGuess+=firstGuess;
	j++;
   }
   return firstGuess;
 }
 //take the guess array and convert it to string according to it's size
  for(int m = 0; m<length;m++){
	guess+=to_string(guessArray[m]);
 }
//send it to permute
  if(notPermuted){
  	permute(0, length-1);
	notPermuted=false;
  }
  return guessVec.at(resIndex++);
}
void bullpgia::SmartGuesser::swap(char *x, char *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  
//creates all the possible permutation of a string, copied from geeksforgeeks(link in readme)
void bullpgia::SmartGuesser::permute(int l, int r)  
{  
    string tempGuess;
    int index;  
    if (l == r)  {
	guessVec.push_back(tempGuess(guess));
    }  
    else
    {  
        for (index = l; index <= r; index++)  
        {  
            swap((guess+l), (guess+index));  
            permute(l+1, r);  
            swap((guess+l), (guess+index)); //backtrack  
        }  
    }  
}

//updating the resultes from bull and pgia
void bullpgia::SmartGuesser::saveResults(){

 int k = 0;
 while(k<bulls){
	guessArray[indexArray] = i;
	indexArray++;
	k++;
	numChar++;
 }
 k=0;
 while(k<cows){
	guessArray[indexArray]= i;
	indexArray++;
	k++;
	numChar++;
 }
 k=0;

}

void bullpgia::SmartGuesser::startNewGame(uint slength){
	if(slength<=4)
	  length=slength;
	

}
void bullpgia::SmartGuesser::learn(string reply){
 
    int sign= reply.find(",");
    bulls = stod(reply.substr(0,sign));
    cows = stod(reply.substr(sign+1,reply.length()-1));

}
