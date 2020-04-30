/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "common.h"
#include "text/text.h"

static void show_line(int index, string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, nullptr);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents.empty() != 1);
    unsigned int len = contents.length();
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    if(cursor >= 0){
        for(int i = 0; i < cursor && i < (int)len; i++){
          printf("%c", contents[i]);
        }
        printf("|");

	for(unsigned int i = cursor; i <= len; i++){
	    printf("%c",contents[i]);
	}
    }
    else
    	cout << contents;
}
