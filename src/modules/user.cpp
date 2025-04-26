#include "user.hpp"
#include "text-config.hpp"
#include <cstdlib>
#include <iostream>

std::string User::getName(){
  const char* user = std::getenv("USER");
  const char* host = std::getenv("HOSTNAME");

  std::string userStr = user ? user : "UnknownUser";
  std::string hostStr = host ? host : "UnknownHost";
  return userStr + "@" + hostStr;
}





void User::displayUser(const std::string& colour, const std::string& font){
  TextConfig::setStyle(colour, font);
  std::cout << "User: ";
  TextConfig::resetStyle();
  std::cout << getName() << std::endl;
  
}
