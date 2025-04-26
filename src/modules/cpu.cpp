#include "cpu.hpp"
#include "text-config.hpp"
#include <iostream>
#include <cstdlib>
#include <regex>

std::string executeCommand(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;

    // Open a pipe to read the command output
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output into the result string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

std::string Cpu::getCpu(){
  std::string cpu = executeCommand("sysctl -a | grep machdep.cpu.brand_string");
  std::regex r(R"(machdep\.cpu\.brand_string\s*:\s*)");

  return std::regex_replace(cpu, r, "");

}

void Cpu::displayCpu(const std::string& colour, const std::string& font){
  TextConfig::setStyle(colour, font);
  std::cout << "CPU";
  TextConfig::resetStyle();
  std::cout << ": " << getCpu() << std::endl;
}
