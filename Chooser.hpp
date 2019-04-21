#pragma once
using namespace std;
namespace bullpgia{

class Chooser{
 private:
 int NumOfChooser;
 uint length;

 public:
  Chooser();
  virtual string choose(uint length);

};
};
