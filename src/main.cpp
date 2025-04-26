#include <iostream>
#include <map>
#include <vector>
#include "home.hpp"
#include "shell.hpp"
#include "pwd.hpp"
#include "user.hpp"
#include "cpu.hpp"
#include "config-manager.hpp"
#include "text-config.hpp"

constexpr uint64_t fnv1aHash(const char* str, size_t length, uint64_t hash = 14695981039346656037ULL) {
    return length == 0 ? hash : fnv1aHash(str + 1, length - 1, (hash ^ static_cast<unsigned char>(*str)) * 1099511628211ULL);
}

constexpr uint64_t hash(const char* str) {
    uint64_t hash = 14695981039346656037ULL;
    while (*str) {
        hash = (hash ^ static_cast<unsigned char>(*str)) * 1099511628211ULL;
        ++str;
    }
    return hash;
}



void displayModule(const std::vector<std::string>& module){
  std::string colour = "";
  std::string font = "";

  for(const auto& item: module){
    if(TextConfig::colours.find(item) != TextConfig::colours.end()){
      colour = item;

    }
    if(TextConfig::fonts.find(item) != TextConfig::fonts.end()){
      font = item;
    }
    
    switch(hash(item.c_str())){
      case hash("user"): User::displayUser(colour,font); break;
      case hash("shell"): Shell::displayShell(colour,font); break;
      case hash("home"): Home::displayHome(colour,font); break;
      case hash("pwd"): Pwd::displayPwd(colour, font); break;
      case hash("cpu"): Cpu::displayCpu(colour, font); break;


      default:
        //std::cout << "Unknown module: " << module << std::endl;
        break;
    }
  }
}
void display(const std::vector<std::vector<std::string>>& modules){
  
  for(const auto& module: modules){
    displayModule(module);
  }
}
int main(){
  
  ConfigManager configManager;
  std::vector<std::vector<std::string>> modules = configManager.getConfigModules();
  auto image = configManager.getImage();
  
  display(modules);
  return 0;

}
