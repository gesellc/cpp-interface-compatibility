#pragma once

namespace inventory_V_2_0_0 {

class part {
 public:
    virtual ~part() {}
    virtual int id() const = 0;
};

part * create_part();

}
