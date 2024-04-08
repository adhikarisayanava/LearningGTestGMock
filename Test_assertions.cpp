#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST (Testname, Subtest_1) {

    EXPECT_EQ(1,2);
    cout << "After expect" << endl; //this is printed since EXPECT is non-fatal
}

TEST (Testname, Subtest_2) {

    ASSERT_TRUE(1 == 1);

}

TEST (Testname, Subtest_3) {

    ASSERT_EQ(1,2);
    //OR
    //ASSERT_FALSE(1 == 2);
    cout << "After assertion" << endl; //not executed since ASSERT is FATAL type so it stops execution here
    
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

/*
Assertions : 3 types
1)Success
2)Non-Fatal Failure : EXPECT_EQ(),EXPECT_NE(),EXPECT_LT(),EXPECT_GT(),EXPECT_GE(),EXPECT_LE()
3)Fatal Failure : ASSERT_EQ(),ASSERT_NE(),ASSERT_LT(),ASSERT_GT(),ASSERT_GE(),ASSERT_LE()
*/