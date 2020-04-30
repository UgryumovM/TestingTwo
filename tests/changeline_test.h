#ifndef CHANGELINE_TEST_H
#define CHANGELINE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "func.h"

/* using namespace testing; */
extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}

TEST(clTest, Pos){
    string file2 = "input.txt";
    string posout = "output.txt";
    string poside = "clp.txt";

    text txt = create_text();
    load(txt, file2);

    m(txt, 1, 0);

    cn(txt);
    save(txt, posout.c_str());

    ASSERT_EQ(compare(posout, poside), 1);
}

TEST(clTest, Neg){
    string file2 = "input.txt";
    text txt = create_text();
    load(txt, file2);

    m(txt,10,0);

    string negout = "output.txt";
    string negide = "cln.txt";

    cn(txt);
    save(txt, negout.c_str());

    ASSERT_EQ(compare(negout, negide), 1);
}

#endif // CHANGELINE_TEST_H
