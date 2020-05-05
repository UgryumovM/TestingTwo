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
    string testOutputFile = "testsfiles/tout.txt";
    int outFd = open(testOutputFile.c_str(),O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);
    int oldOutput = dup(1);
    int ret = dup2(outFd, 1);

    text txt = create_text();

    string file = "testsfiles/input.txt";

    load(txt, file);
    shownumspaces(txt);

    close(ret);
    close(outFd);
    dup2(oldOutput, 1);

    string outp = "testsfiles/tout.txt";
    string ide = "testsfiles/tcom.txt";
    int cmp = compare(outp, ide);

    ASSERT_EQ(cmp, 1);
}



#endif // SHOWNUM_TEST_H
