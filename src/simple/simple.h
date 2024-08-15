#ifndef simple_h
#define simple_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "tools.h"
#include "hash.h"
#include "map.h"

#include "type.h"

char* mostCommonWord(char* paragraph, char** banned, int bannedSize);
int* shortestToChar(char* s, char c, int* returnSize);
char* toGoatLatin(char* sentence);

#endif
