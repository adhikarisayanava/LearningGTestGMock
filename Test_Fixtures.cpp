#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class myClass {
    int baseValue;
public:
    myClass(int _bv) {

        baseValue = _bv;

    }

    void increment(int byValue) {

        baseValue += byValue;
    }

    int GetValue() {

        return baseValue;

    }
};

//By using Fixture, we can move the common part of the tests to a single place
struct MyClassTest : public testing::Test {
    myClass *mc;
    void SetUp() {
        cout << "Alive" << endl;
        mc = new myClass(100);
    }
    void TearDown() {
        cout << "Dead" << endl;
        delete mc;
    }

};

TEST_F (MyClassTest, increment_by_5) {
    //Act
    mc->increment(5);
    //Assert
    ASSERT_EQ(mc->GetValue(),105);
}

TEST_F (MyClassTest, increment_by_10) {
    //Act
    mc->increment(10);
    //Assert
    ASSERT_EQ(mc->GetValue(),110);
}


int main (int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

