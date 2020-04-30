#include <stdio.h>
#include <assert.h>
#include "_text.h"

void rch(text txt){
    int i = static_cast<int>(txt->cursor->position);
    int line = txt->cursor->line - 1;
    auto cur = txt->node->begin();
    for(int j = 0; j < line;j++){
        cur++;
    }
    if((*cur)[0] != '\n'){
    for(int j = i; (*cur)[j] != '\0'; j++){
        if((*cur)[j + 1] == '\n'){
            (*cur)[j] = '\n';
            (*cur)[j + 1] = '\0';
            break;
        }
        if((*cur)[j+1] == '\0'){
            (*cur)[j] = '\0';
            break;
        }
        (*cur)[j] = (*cur)[j + 1];
    }

    }
}
