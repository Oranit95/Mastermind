#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
using std::string;

namespace bullpgia{

class SmartGuesser: public bullpgia::Guesser{

   public:
   string guess() override;
   void startNewGame(uint length) override;
   void learn(string reply) override;
};
}
