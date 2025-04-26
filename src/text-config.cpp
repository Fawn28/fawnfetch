#include "text-config.hpp"


const std::unordered_map<std::string, std::string> TextConfig::colours = {
      {"red", "\u001b[31m"},
      {"green", "\u001b[32m"},
      {"yellow", "\u001b[33m"},
      {"blue", "\u001b[34m"},
      {"magenta", "\u001b[35m"},
      {"cyan", "\u001b[36m"},
      {"white", "\u001b[37m"},
      {"reset", "\u001b[0m"}
};
const std::unordered_map<std::string, std::string> TextConfig::fonts = {
    {"bold", "\u001b[1m"},
    {"italicize", "\u001b[3m"},
    {"underline", "\u001b[4m"},
};

void TextConfig::setStyle(const std::string& colour, const std::string& font) {
   
  if(!colour.empty() && colours.find(colour) != colours.end()){
    std::cout << colours.at(colour);
  }
  if(!font.empty() && fonts.find(colour) != fonts.end()){
    std::cout << fonts.at(font);
  }
  
}

void TextConfig::resetStyle(){
  std::cout << "\u001b[0m";
}

