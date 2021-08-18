#include <iostream>
#include "person.h"

int main() {
  //person john("John", "Smith", 1, 1, 1990); 
  //std::cout << john << "\n";

  person input;
  input.inputPerson();
  std::cout << input << "\n";
}
