#include <stdio.h>
#include <assert.h>
#include "_text.h"

void move_cursor(text txt, int line, int pos){
    if(line <= 0){
        txt->cursor->line = 1;
        txt->cursor->position = 0;
        return;
    }
    std::list<string>::iterator current = txt->node->begin();
    int i = 1;
    for(;i < line; i++){
        current++;
        if(current == txt->node->end()){
            current --;
            break;
        }
    }
    txt->cursor->line = i;
    unsigned int length;
    for(length = 0; length < current->length(); length++);
    if (pos <= (int)length)
        txt->cursor->position = pos - 1;
    else{
        txt->cursor->position = current->length();
    }
}
