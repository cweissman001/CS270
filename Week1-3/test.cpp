#include "gtest/gtest.h"
#include <string>
#include "factorial.h"

//TEST(test.category, testname) {
// EXPECT_WE(values; // check result and keep going
// ASSERT_WE(values); //check result and end//}

TEST(factorial, zero) {
    EXPECT_EQ(fact(0), 1);

}
TEST(factorial, regular) {
    EXPECT_EQ(fact(6), 720);
    EXPECT_EQ(fact(3), 6);
    EXPECT_EQ(fact(1), 1);
}
TEST(factorial, negative) {
    EXPECT_EQ(fact(-1), -1);
    EXPECT_EQ(fact(-5), -1);
}
                   
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}