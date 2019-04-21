#pragma once
#include <string>
using std::string;
namespace bullpgia{

class Guesser{
 protected:
 uint length;
 string reply;
 
 public:
 virtual string guess()=0;
 virtual void startNewGame(uint length){};
 virtual void learn(string reply){};

};
}
