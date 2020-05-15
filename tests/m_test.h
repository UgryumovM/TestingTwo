#ifndef M_TEST_H
#define M_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "func.h"

/* using namespace testing; */
extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}




TEST(moveTest, Pos){
    text txt = create_text();
    input(txt);

    m(txt, 1, 2);
    ASSERT_EQ(getcursorp(txt), 1);
    ASSERT_EQ(getcursorl(txt), 1);
}

TEST(moveTest, Neg){
    text txt = create_text();
    input(txt);

    m(txt, 0, 0);
    ASSERT_EQ(getcursorp(txt), 0);
    ASSERT_EQ(getcursorl(txt), 1);


    m(txt, 600, 600);
    ASSERT_EQ(getcursorp(txt), 1);
    ASSERT_EQ(getcursorl(txt), 7);

    m(txt, -1, -1);
    ASSERT_EQ(getcursorp(txt), 0);
    ASSERT_EQ(getcursorl(txt), 1);

    m(txt, 3, 14);
    ASSERT_EQ(getcursorp(txt), 12);
    ASSERT_EQ(getcursorl(txt), 3);

}

#endif // M_TEST_H
