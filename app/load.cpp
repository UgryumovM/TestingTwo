/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, string fi)
{
    const char *filename = fi.c_str();
    FILE *f;

    char buf[MAXLINE];

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "r")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);
    /* Считываем содержимое строка за строкой */
    while (fgets(buf, MAXLINE, f)) {
      append_line(txt, static_cast<string>(buf));
    }
    fclose(f);
}
