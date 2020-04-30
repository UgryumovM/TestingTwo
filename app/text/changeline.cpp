#include "_text.h"

void changeline(int line, text txt){
    string buf, buf2;
    auto current = txt->node->begin();
    for(int lp = 0; lp != line - 1; lp++){
        current++;
    }
    buf = *current;
    current++;
    if(current == txt->node->end())
	return;
    buf2 = *current;
    *current = buf;
    current--;
    *current = buf2;
}
