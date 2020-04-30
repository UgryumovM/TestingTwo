/**
 * remove_all.c -- реализует функцию очистки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }    
    
    /* Если список изначально пуст, делать ничего не надо */
    if (txt->node->empty() == 0) {
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    
    /* Стартуем с первого элемента списка */


    /* Реинициализируем текст */
    txt->node->clear();
    txt->cursor->line = 0;
    txt->cursor->position = 0;
}
