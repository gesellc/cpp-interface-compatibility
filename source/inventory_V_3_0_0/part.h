#pragma once
#include <string>

namespace inventory_V_3_0_0 {

class part {
 public:
    virtual ~part() {}
    virtual int id() const = 0;
    virtual std::string name() const = 0;
};

part * create_part();

}
