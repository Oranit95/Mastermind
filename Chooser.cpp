#include "Chooser.hpp"
#include <string>
namespace bullpgia{

int NumOfChooser = 0;
uint length;
Chooser:: Chooser(){

this-> NumOfChooser = NumOfChooser++;

}

Chooser:: virtual string Choose(uint length){

string s;
this-> length = length;

return s;
}

}; 
