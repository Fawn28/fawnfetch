#include <string>
#include <iostream>
#include <unordered_map>

class TextConfig {

public:
    static const std::unordered_map<std::string, std::string> colours;
    static const std::unordered_map<std::string, std::string> fonts;
    static void setStyle(const std::string& colour = "", const std::string& font = "");
    static void resetStyle();
};

