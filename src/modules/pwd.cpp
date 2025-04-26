#include "pwd.hpp"
#include "text-config.hpp"
#include <cstdlib>
#include <iostream>


std::string Pwd::getPwd(){
  const char* pwd = std::getenv("PWD");
  return pwd ? std::string(pwd) : "Unkown";

}

void Pwd::displayPwd(const std::string& colour, const std::string& font){
  
  TextConfig::setStyle(colour, font);
  std::cout << "PWD: ";
  TextConfig::resetStyle();
  std::cout << getPwd() << std::endl;
  
}
