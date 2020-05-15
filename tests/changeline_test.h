#ifndef CHANGELINE_TEST_H
#define CHANGELINE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fstream>
#include "func.h"

/* using namespace testing; */
extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}

TEST(clTest, Pos){
    string inputs = "sample text 2\nsample text\ns a m p l e\nt e x t   3\n\ns\n4\0";
    text txt = create_text();
    input(txt);

    m(txt, 1, 0);

    cn(txt);
    save(txt, "Poutput");

    string poside;
    std::ifstream f("Poutput");

    std::string fileo;

    poside.assign( (std::istreambuf_iterator<char>(f) ),
                            (std::istreambuf_iterator<char>()    ) );

    ASSERT_EQ(inputs, poside);
}

TEST(clTest, Neg){
    text txt = create_text();
    input(txt);

    string inputs;
    inputs = "sample text\nsample text 2\ns a m p l e\nt e x t   3\n\ns\n4\0";

    m(txt,10,0);


    cn(txt);
    save(txt, "negout");

    string negide;
    std::ifstream f("negout");

    std::string fileo;

    negide.assign( (std::istreambuf_iterator<char>(f) ),
                            (std::istreambuf_iterator<char>()    ) );

    ASSERT_EQ(negide, inputs);
}

#endif // CHANGELINE_TEST_H
