#include "shell.hpp"
#include "text-config.hpp"
#include <cstdlib>
#include <iostream>


std::string Shell::getShell(){
  const char* shell = std::getenv("SHELL");
  if (shell) {
        std::string shellPath(shell);
        // Find the last '/' and extract the substring after it
        size_t pos = shellPath.find_last_of('/');
        return shellPath.substr(pos + 1);
  }
  return "Unknown";

}

void Shell::displayShell(const std::string& colour, const std::string& font){ 
  TextConfig::setStyle(colour, font);
  std::cout << "Shell: ";
  TextConfig::resetStyle();
  std::cout << getShell() << std::endl;

}
