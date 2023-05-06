#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/**
    @brief Функция isOperator() проверяет, является ли символ оператором.
    @param c символ, который нужно проверить на оператор.
    @return Возвращает 1, если символ является оператором, и 0, если нет.
*/
int isOperator(char c);

/**
    @brief Функция priority() определяет приоритет оператора.
    @param op символ оператора, для которого нужно определить приоритет.
    @return Возвращает значение приоритета оператора (от 1 до 3).
*/
int priority(char op);

/**
    @brief Функция addoperator() применяет оператор к двум числам.
    @param op оператор, который нужно применить.
    @param b первое число.
    @param a второе число.
    @return Возвращает результат вычисления.
*/
double addoperator(char op, double b, double a);

/**
    @brief Функция calculator() вычисляет значение математического выражения, заданного строкой.
    @param expr строка, содержащая математическое выражение.
    @return Возвращает результат вычисления выражения.
*/
double calculator(char* expr);


