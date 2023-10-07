#include <gtest/gtest.h>
#include "myfunctions.h"

TEST(myfunctions, add)
{
    GTEST_ASSERT_EQ(add(10, 22), 32);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
according to documentatiion can use APIs of google test
TEST( , )
{
    //arrane
    //call
    //action

}
*/
/*
Example1 :-

TEST(sumfunction, test_1)
{
    EXPECT_EQ(5, sum(2.3));
    EXPECT_NE(5, sum(2.3));   
}
*/

/*
Example2 :-

TEST(func, test_1)
{
    ASSERT_TRUE(func());
    std::cout << "another test" << std::endl;
    EXPECT_TRUE(func());
}
*/


/*
Example3 :-
void fun()
{
    throw std::logic_error("running time erorr");
    throw std::runtime_error("running time erorr");

}

TEST(func, test_1)
{
    EXPECT_THROW(func(), std::runtimeerror);
}
*/


/*
Example4 :-
const char* fun()
{
    return "hello";
}

TEST(func, test_1)
{
    EXPECT_STREQ(func(), "hello");
}
*/