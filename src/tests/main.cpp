#include "gtest/gtest.h"

TEST(GtestDependency, Should_Compile_if_gtest_was_found)
{
    ASSERT_TRUE(true);
}

// Had some Problems with the conan cmake_find_package generator, 
// it does not generate the correct targets therefore we dont have a gtest_main target
// so I write my own main.
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}