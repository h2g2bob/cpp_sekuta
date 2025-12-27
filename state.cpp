#include <sstream>
#include "state.h"

using namespace state;

std::string State::describe() const {
  std::ostringstream out;
  out << "State... a=" << a.describe() << " b=" << b.describe() << " ...";
  return out.str();
}
