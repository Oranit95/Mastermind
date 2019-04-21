#include "Guesser.hpp"
#include <string>
using std::string;
namespace bullpgia{

uint length;
string reply;

string Guesser::virtual guess(){
 return "";
}

void Guesser::virtual startNewGame(uint length){
 cout<<length<<endl;
}

void Guesser::virtual learn(string reply){
 cout<<reply<<endl;
}
}
