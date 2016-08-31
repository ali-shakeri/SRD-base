#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>

template <typename T>
std::string number_to_string (T Number) {
  std::ostringstream ss;
  ss << Number;
  return ss.str();
}
  
#endif