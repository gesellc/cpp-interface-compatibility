#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/inventory_V_1_0_0/part.h"

using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::Pointee;


TEST(inventory_V_1_0_0, part_id_is_42) {
  inventory_V_1_0_0::part p;
  ASSERT_EQ(42, p.id());
}
