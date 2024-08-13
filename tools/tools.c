#include "tools.h"

void toLower(char *p_str, int p_str_len)
{
    if (p_str == NULL) return;
    for (int i = 0; i < p_str_len; i++)
    {
        p_str[i] = tolower(p_str[i]);
    }
}
