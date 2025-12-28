#include <sstream>
#include "state.h"

using namespace state;

std::string State::describe() const {
  std::ostringstream out;
  out << "State... 00=" << digits[0][0].describe() << " 01=" << digits[0][1].describe() << " ...";
  return out.str();
}
