#ifndef SAVE_TEST_H
#define SAVE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include "func.h"

extern "C++" {
    #include "text/_text.h"
    #include "text/text.h"
    #include "common.h"
}

TEST(saveTest, pos){
    text txt = create_text();
    input(txt);
    string inputs;
    inputs = "sample text\nsample text 2\ns a m p l e\nt e x t   3\n\ns\n4\0";


    save(txt, "Soutput.txt");

    std::ifstream f("Soutput.txt");
    std::string fileo;

    fileo.assign( (std::istreambuf_iterator<char>(f) ),
                            (std::istreambuf_iterator<char>()    ) );

    ASSERT_EQ(inputs, fileo);
    f.close();
}


#endif // SAVE_TEST_H
