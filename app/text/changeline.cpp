#include "_text.h"
#include <iterator>

void changeline(int line, text txt){
    string buf, buf2;
    std::list<string>::iterator current = txt->node->begin();
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
