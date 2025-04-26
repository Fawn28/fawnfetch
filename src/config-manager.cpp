#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "config-manager.hpp"

using json = nlohmann::json;

std::vector<std::vector<std::string>> ConfigManager::getConfigModules(){
  std::ifstream file(std::string(std::getenv("HOME")) + "/projects/fawnfetch/config/config.json");

  json configData;
  file >> configData;
  std::vector<std::vector<std::string>> modules;


  if (!file.is_open()) {
    std::cerr << "Error: Unable to open config file" << std::endl;
    return {};
  }

  if(configData.contains("modules")){

    for(const auto& [module, moduleItems]: configData["modules"].items()){
      std::vector<std::string> items;

      for(const auto& item: moduleItems){
        items.push_back(item.get<std::string>());
      }
       
      modules.push_back(items);
    }
      }

  file.close();
  return modules;

}

std::vector<std::string> ConfigManager::getImage(){
  std::ifstream file(std::string(std::getenv("HOME")) + "/projects/fawnfetch/image/test.txt");
  
  std::vector<std::string> fileLines;
  std::string line;
  while(getline(file, line)){
    fileLines.push_back(line);
  }

  file.close();
  return fileLines;

  
}
