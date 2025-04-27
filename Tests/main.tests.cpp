#include <gtest/gtest.h>

class GTestExample : public ::testing::Test
{
public:
    void SetUp() override
    {
    }
};


TEST_F(GTestExample, TestExample)
{
    EXPECT_EQ(1, 1);
}
