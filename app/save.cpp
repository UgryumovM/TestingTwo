/**
 * save.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <iostream>

static void save_line(int index, string contents, int cursor, void *data);

/**
 * Сохраняет содержимое указанного файла
 */



void save(text txt,const char *filename)
{
    FILE *f;
    f = fopen(filename, "w");

    process_forward(txt, save_line, f);

    fclose(f);
}

static void save_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(!contents.empty());
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    FILE *f = static_cast<FILE*>(data);
    /* Выводим строку на экран */
    fprintf(f, "%s", contents.c_str());
}
