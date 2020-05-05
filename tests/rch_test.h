#ifndef RCH_TEST_H
#define RCH_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "func.h"

/* using namespace testing; */
extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}

TEST(rchTest, Pos){
    string file2 = "testsfiles/input.txt";

    string posro = "testsfiles/rpoutput.txt";
    string posri = "testsfiles/rchp.txt";

    text txt = create_text();
    load(txt, file2);

    show(txt);

    m(txt, 1, 1);

    rightcdel(txt);

    show(txt);

    save(txt, posro.c_str());
    ASSERT_EQ(compare(posro, posri), 1);
}

TEST(rchTest, Neg){
    string file2 = "testsfiles/input.txt";
    text txt = create_text();
    load(txt, file2);

    m(txt,10,0);

    string negro = "testsfiles/rnoutput.txt";
    string negri = "testsfiles/rchn.txt";

    rightcdel(txt);
    save(txt, negro.c_str());

    ASSERT_EQ(compare(negro, negri), 1);
}
#endif // RCH_TEST_H
