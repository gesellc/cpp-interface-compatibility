#include "part.h"


namespace {

class realpart : public inventory_V_3_0_0::part {
 public:
    realpart() {}
    int id() const;
    std::string name() const;
 private:
    int num;
    std::string namestr;
};

int realpart::id() const {
  return 42;
}

std::string realpart::name() const {
  return "Realpart";
}

}

namespace inventory_V_3_0_0 {

part * create_part() {
  return new realpart;
}

}
