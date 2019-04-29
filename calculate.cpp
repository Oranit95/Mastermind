#include <cstdio>
#include <string>
#include <iostream>
#include <math.h>
#include "calculate.hpp"

namespace bullpgia{

  string calculateBullAndPgia(string choice, string guess){

        if(choice == ""){
		throw std::invalid_argument( "The string is empty" );
	}
	if(guess == ""){
		throw std::invalid_argument( "The string is empty"  );
	}
	
	//get the bulls
	int bulls = getNumExactCharMatches(choice, guess);
	//get the cows
	int cows = getNumSimilarChars(choice, guess) - bulls;

       //output
        string s = "";
        return s;
 }

  int getNumExactCharMatches(string choice, string guess){
	int count = 0;
	int index = 0;
	while(index < choice.length() && index < guess.length()){
		if(choice[index] == guess[index]){
			count++;
		}
		index++;
	}
	return count;
 }

  int getNumSimilarChars(string choice, string guess){
	int* p1Counts = getCharCounts(choice);
	int* p2Counts = getCharCounts(guess);
	int count = 0;
	for(int i = 0; i < 9; i++){
		count+= min(p1Counts[i], p2Counts[i]);
	}

	return count;
 }

  int* getCharCounts(string str){

     int a = 2;
     int *counts = &a;
       
	return counts;
        
        
  }
}
