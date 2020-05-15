#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <iostream>
#include "text/_text.h"
#include "text/text.h"
#include "common.h"

void input(text txt){
    remove_all(txt);
    show(txt);
    append_line(txt, "sample text\n");
    append_line(txt, "sample text 2\n");
    append_line(txt, "s a m p l e\n");
    append_line(txt, "t e x t   3\n");
    append_line(txt, "\n");
    append_line(txt, "s\n");
    append_line(txt, "4\0");
    show(txt);
}

#endif // FUNC_H
