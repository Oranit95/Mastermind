#include <cstdio>
#include <string.h>
#include "calculate.hpp"

using namespace std;
namespace bullpgia{

calculate:: string calculateBullAndPgia(string choice, string guess){
        
	if(chosen == null){
		throw new NullPointerException("\"chosen\" may not be null");
	}
	if(guess == null){
		throw new NullPointerException("\"guess\" may not be null");
	}
	
	//get the bulls
	int bulls = getNumExactCharMatches(chose, guess);
	//get the cows
	int cows = getNumSimilarChars(chose, guess) - bulls;

	//output
        string s = "";
        s = s + bulls;
        s = s + ",";
        s = s + cows;
        //cout << s << endl;
        return s;
}

calculate:: int getNumExactCharMatches(string chosen, string guess){
	int count = 0;
	int index = 0;
	while(index < chosen.length() && index < guess.length()){
		if(chosen.charAt(index) == guess.charAt(index)){
			count++;
		}
		index++;
	}
	return count;
}

calculate:: int getNumSimilarChars(string chosen, string guess){
	int* p1Counts = getCharCounts(chosen);
	int* p2Counts = getCharCounts(guess);
	int count = 0;
	for(int i = 0; i < 9; i++){
		count+= Math.min(p1Counts[i], p2Counts[i]);
	}
	return count;
}

calculate:: int* getCharCounts(string str){
	int* counts = new int[9];
	char* chars = str.getCharArray();
	for(int i = 0; i < chars.length; i++){
		counts[chars[i]]++;
	}
	return counts;
}

};
