#pragma once
#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include "calculate.hpp"


using namespace std;

namespace bullpgia{

class SmartGuesser: public bullpgia::Guesser{
   private:
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
   public:
   string guess() override;
   void startNewGame(uint length) override;
   void learn(string reply) override;
   SmartGuesser();
   void saveResults();
   //void swap(char *x, char *y);
   void permute(string str, string out);  
};
}
