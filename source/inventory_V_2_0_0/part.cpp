#include "part.h"


namespace {

class realpart : public inventory_V_2_0_0::part {
 public:
    realpart() {}
    int id() const;
 private:
    int num;
};

int realpart::id() const {
  return 42;
}
}

namespace inventory_V_2_0_0 {

part * create_part() {
  return new realpart;
}

}
