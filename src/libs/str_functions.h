/*
 * Created by gt on 11/19/21 - 1:24 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#ifndef LIB_GT_STR_FUNCTIONS_H
#define LIB_GT_STR_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * str: string to search
 * search_character: character to look for
 * return type: unsigned long int, count for the number of times that character was found
 */
unsigned long int number_of_characters_in_string(char *str, char search_character);

/**
 * source: source string
 * return type: _Bool, 1 on success
 */
_Bool remove_non_alpha_characters(char *source);

/**
 * source: source string
 * return type: unsigned long int, length of string
 */
unsigned long int str_length(char *source);

 /**
  * str1: string to concatenate to (resulting string)
  * str2: second string to concatenate from
  * return type: _Bool, 1 on success
  */
_Bool str_concat(char *str1, const char *str2);

/**
 * source: string to copy from
 * destination: second string to copy to
 * return type: _Bool, 1 on success
 */
_Bool str_copy(const char *source, char *destination);

/**
 * source: source string
 * from: starting index_ from where you want to get substring
 * node_: number of characters to be copied in substring
 * target: target string in which you want to store target string
 * return type: _Bool, 1 on success
 */
_Bool substring(const char *source, int from, int n, char *target);

#endif //LIB_GT_STR_FUNCTIONS_H
