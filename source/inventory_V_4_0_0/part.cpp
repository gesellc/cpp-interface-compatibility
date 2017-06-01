#include "part.h"


namespace {

class realpart : public inventory_V_4_0_0::part_v2 {
 public:
    realpart() {}
    int id() const;
    std::string name() const;
    void id( int val );
    void name( const std::string & val );
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

void realpart::id(int val) {
  num = val;
}

void realpart::name(const std::string & val) {
  namestr = val;
}

}

namespace inventory_V_4_0_0 {

part * create_part() {
  return new realpart;
}

}
