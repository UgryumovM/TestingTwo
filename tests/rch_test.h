#ifndef RCH_TEST_H
#define RCH_TEST_H

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

TEST(rchTest, Pos){
    text txt = create_text();
    input(txt);

    string inputs = "ample text\nsample text 2\ns a m p l e\nt e x t   3\n\ns\n4\0";

    m(txt, 1, 1);

    rightcdel(txt);

    save(txt, "POut");

    std::ifstream f("POut");

    std::string fileo;

    fileo.assign( (std::istreambuf_iterator<char>(f) ),
                            (std::istreambuf_iterator<char>()    ) );

    ASSERT_EQ(inputs, fileo);
}

TEST(rchTest, Neg){
    text txt = create_text();
    input(txt);

    string inputs = "sample text\nsample text 2\ns a m p l e\nt e x t   3\n\ns\n4\0";

    m(txt,10,0);

    rightcdel(txt);
    save(txt, "NOut");

    std::ifstream f("NOut");
    std::string fileo;
    fileo.assign( (std::istreambuf_iterator<char>(f) ),
                            (std::istreambuf_iterator<char>()    ) );

    ASSERT_EQ(inputs, fileo);
}
#endif // RCH_TEST_H
