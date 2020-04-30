/**
 * _text.h -- внутренние структуры представления текста
 *
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <list>
#include <iostream>

#include "text.h"

/**
 * @struct
 * @brief Представление одной строки текста как элемента линейного списка
 *
 */

/**
 * @struct
 * @brief Представление курсора
 *
 */
typedef struct _crsr {
    int line;         /**< номер строки с курсором */
    long position;               /**< позиция курсора в строке */
} crsr;

/**
 * @struct
 * @brief Представление списка
 *
 */
struct _lista {
  list<string> *node;
  struct _crsr *cursor;
};

#endif
