#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class MyClass {
    string id;
    public:
        MyClass(string _id) : id(_id) {}
        string GetId() {
            return id;
        }

};

TEST(TestName, check_class_variable) {

    //Arrange
    MyClass mc("root");

    //Act
    string value = mc.GetId();

    //Assert
    ASSERT_STREQ(value.c_str(), "root");

}

void hello_world(){

    cout << "Hello_World" << endl;
}

TEST(TestName, increment_by_5) {

    //Arrange
    int value = 100;
    int increment = 5;

    //Act
    value = value + increment;

    //Assert
    ASSERT_EQ(value, 105);

}

TEST(TestName, increment_by_10) {

    //Arrange
    int value = 100;
    int increment = 10;

    //Act
    value = value + increment;

    //Assert
    ASSERT_EQ(value, 110);

}

int main(int argc, char **argv) {

    hello_world();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}