#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Stack {

    vector<int> vstack = {};
    public:
        void push(int value) {
            vstack.push_back(value);
        }
        int pop() {

            if (vstack.size() > 0) {
            int value = vstack.back();
            vstack.pop_back();
            return value;           
            } else {
                return -1;
            } 
        }
        int size() {
            return vstack.size();
        }

};

struct StackTest : public testing::Test {
    Stack s1;
    void SetUp() {
        cout << "Alive" << endl;
        int values[]= {1,2,3,4,5,6,7,8,9};
        for(auto &val : values) {
            s1.push(val);
        }
    }
    void TearDown() {
        cout << "Dead" << endl;
    }

};

TEST_F (StackTest, PopTest) {
    int lastPoppedValue = 9;
    while (lastPoppedValue != 1)
    {
        cout << "Last popped Value is" << lastPoppedValue << endl;
        //cout << "s1.pop() is" << s1.pop() << endl;
        ASSERT_EQ(s1.pop(), lastPoppedValue--);
    }
}
 
int main (int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}