#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::Return;

class ICalculator {
public:
    //virtual ~ICalculator() {}
    virtual int add(int a, int b) = 0;
};

class MockCalculator : public ICalculator {
public:
    MOCK_METHOD2(add, int(int a, int b));
};

TEST(CalculatorTest, ADD_EXPECT_CALL) {
    int a = 5 , b = 10;
    MockCalculator mockCalculator;

    EXPECT_CALL(mockCalculator, add(a, b))
    .Times(1)
    .WillOnce(Return(15)); 

    ASSERT_EQ(mockCalculator.add(a, b), 15);
}

TEST(CalculatorTest, ADD_ON_CALL) {
    int a = 5 , b = 10;
    MockCalculator mockCalculator;

    ON_CALL(mockCalculator, add(a, b)).WillByDefault(Return(a + b));

    ASSERT_EQ(mockCalculator.add(a, b), a + b);
}