#pragma once
#include <string>

namespace inventory_V_4_0_0 {

class part {
 public:
    virtual ~part() {}
    virtual int id() const = 0;
    virtual std::string name() const = 0;
};

class part_v2 : public part
{
public:
    using part::id;
    using part::name;

    virtual void id( int val ) = 0;
    virtual void name( const std::string & val ) = 0;
};

part * create_part();

}
