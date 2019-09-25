#pragma once

#include "Level_0.hpp"
#ifdef BUILD_REFERENCE
    #include "Level_0_Reference.hpp"
#endif

#include "gtest/gtest.h"

template <typename T>
class Level_0_Tests : public ::testing::Test
{

};
TYPED_TEST_CASE_P(Level_0_Tests);

/***************************************************************/
TYPED_TEST_P(Level_0_Tests, Should_Succeed) {
  // Inside a test, refer to TypeParam to get the type parameter.
  // TypeParam n = 0;
  SUCCEED();
}

// Register all test names, e.g. Should_Succeed
REGISTER_TYPED_TEST_CASE_P(Level_0_Tests,
                            Should_Succeed);

// Now we can instantiate it with our types.
#ifdef BUILD_REFERENCE
    typedef ::testing::Types<onions::SomeClass, reference::SomeClass> TestTypes;
    INSTANTIATE_TYPED_TEST_CASE_P(My, Level_0_Tests, TestTypes);
#else
    INSTANTIATE_TYPED_TEST_CASE_P(Level_0_Tests, onions::SomeClass);
#endif

