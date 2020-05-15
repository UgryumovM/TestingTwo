#ifndef SHOWNUM_TEST_H
#define SHOWNUM_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include "func.h"


/* using namespace testing; */
extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}



TEST(shownTest, Pos){
    text txt = create_text();
    input(txt);

    string eoutput = "1\n2\n5\n6\n0\n0\n0\n";

    testing::internal::CaptureStdout();
    shownumspaces(txt);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(eoutput, output);
}



#endif // SHOWNUM_TEST_H
