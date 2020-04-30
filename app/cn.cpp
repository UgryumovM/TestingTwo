#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

void cn(text txt){
    changeline(getcursorl(txt), txt);
}
