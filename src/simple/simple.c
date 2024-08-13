#include "simple.h"

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    // 字符串分割
    char *p_str = strtok(paragraph, " ");

    while (p_str != NULL) {
        // 内容拷贝到数组中
        char *p_str_arr = (char*)malloc(sizeof(char) * (strlen(p_str) + 1));
        strcpy(p_str_arr, p_str);
        toLower(p_str_arr, strlen(p_str) + 1);


        // 判断是否在banned数组中
        int i = 0;
        for (i = 0; i < bannedSize; i++) {
            if (strcmp(p_str_arr, banned[i]) == 0) {
                break;
            }
        }

        if (i >= bannedSize) {
            continue;
        }
    }
}