/*
 * Created by gt on 10/14/21 - 9:32 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long int str_len(const char *s);
char *str_concat(const char *str1, const char *str2);
int str_cmp(const char *str1, const char *str2);
char *str_rev(const char *s);
char **str_sort(char **str_list, size_t size);

int main() {
    char gt[] = "Gurkan";
    printf("String: '%s' contains %li characters\n", gt, str_len(gt));
    printf("Length of the same string with strlen: %li\n", strlen(gt));

    char *str_concatd = str_concat("this is a string", ", this is also a string");
    printf("concatenated string: %s\n", str_concatd);

    int cmp_result;
    cmp_result = str_cmp("aA", "a");
    printf("%s\n", cmp_result == 0 ? "strings are equal" : cmp_result == 1 ? "str1 is greater than str2" : "str1 is smaller than str2");

    char *str_to_rev = "gurkan";
    char *str_revd = NULL;
    str_revd = str_rev(str_to_rev);
    printf("reverse of %s is %s\n", str_to_rev, str_revd);

    char *str_list[] = {"bca1111111111122223333", "bca", "abc", "09za", "bbb123", "bbb122", "abbb122", "A", "a", "Aa"};
    size_t str_list_w_cnt = sizeof str_list / sizeof *str_list;
    char **sorted = NULL;

    puts("str_list:");
    for (int i = 0; i < str_list_w_cnt; ++i) {
        printf("str_list[%i] : %s\n", i, str_list[i]);
    }
    sorted = str_sort(str_list, str_list_w_cnt);
    puts("sorted:");
    for (int i = 0; i < str_list_w_cnt; ++i) {
        printf("sorted[%i] : %s\n", i, sorted[i]);
    }

    if (str_concatd) free(str_concatd);
    if (str_revd) free(str_revd);
    if (sorted) free(sorted);

    return 0;
}