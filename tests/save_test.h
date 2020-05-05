#ifndef SAVE_TEST_H
#define SAVE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fstream>
#include "func.h"

extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}


TEST(saveTest, pos){
    text txt = create_text();
    string inp = "testsfiles/input.txt";
    string outt = "testsfiles/output.txt";

    load(txt, inp);
    save(txt, outt.c_str());


    string outp = "testsfiles/input.txt";
    string ide = "testsfiles/output.txt";
    int cmp = compare(outp, ide);
    ASSERT_EQ(cmp, 1);
}


#endif // SAVE_TEST_H
