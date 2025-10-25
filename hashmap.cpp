#include <iostream>
#include <cstdlib>
#include <ostream>
#include <string>
#include <unordered_map>

int main() {

  std::unordered_map<std::string, int> hashMap;

  hashMap["apple"] = 10;
  hashMap["mango"] = 20;
  hashMap["cherry"] = 30;

  for (const auto &pair : hashMap) {
    std::cout << pair.first << "-> " << pair.second << std::endl;
  }
  
  return EXIT_SUCCESS;  
}  
