#include "home.hpp"
#include "text-config.hpp"
#include <cstdlib>
#include <iostream>


std::string Home::getHome(){
  const char* home = std::getenv("HOME");
  return home ? std::string(home) : "Unkown";
}

void Home::displayHome(const std::string& colour, const std::string& font){

  TextConfig::setStyle(colour, font);
  std::cout << "Home: ";
  TextConfig::resetStyle();
  std::cout << getHome() << std::endl;
  TextConfig::setStyle(colour, font);

}
 
