/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{  
    _lista *txt = new _lista;
    txt->node = new list<string>;
    txt->cursor = new crsr;
    if(txt->node == NULL){
        fprintf(stderr, "Memory error\n");
    }
    if(txt->cursor == NULL){
        fprintf(stderr, "Memory error\n");
    }
    /* Курсор не настроен ни на какой символ текста */
    txt->cursor->line = -1;
    txt->cursor->position = 0;
    
    return txt;
}
