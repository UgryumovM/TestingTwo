#include "save_test.h"
#include "shownum_test.h"
#include "m_test.h"
#include "rch_test.h"
#include "changeline_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
