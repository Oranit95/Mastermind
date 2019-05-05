#include <cstdio>
#include <string>
#include <iostream>
#include <math.h>
#include "calculate.hpp"

namespace bullpgia{

  string calculateBullAndPgia(string choice, string guess){

	//if any of the strings are empty, the game cannot be played
	if( choice == "" || guess == "" ) throw std::invalid_argument( "The string is empty" );
	int bulls = 0;
	int cows = 0;

	for( int i = 0; i < choice.length(); i++ ){
            if(choice[i] == guess[i]){
            bulls++;
            guess[i] = '!';
            choice[i] = '!';
		}
          } 
		
	if(bulls == choice.length()){
           string b = to_string(bulls);
           string c = to_string(cows);
           string s = b + "," + c;
	   return s;
	}

		for( int j = 0; j < choice.length(); j++){
                 for(int k = 0; k < guess.length(); k++){
			if(choice[j]==guess[k] && choice[j]!='!' && guess[k]!='!'){
				cows++;
                                guess[k]='!';
                                break;
                      }				
			
		}      

	}
	
	string b = to_string(bulls);
        string c = to_string(cows);
        string s = b + "," + c;

        return s;

	}

}
