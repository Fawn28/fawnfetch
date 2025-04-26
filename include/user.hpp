#ifndef USER_HPP
#define USER_HPP

#include <string>

class User{
public:
  static void displayUser(const std::string& colour = "", const std::string& font = "");
  static std::string getName();
};
#endif
