#include "simple.h"
#include "simple_1.h"

int main()
{
    char *s = "(()())(())()()())()()()()())";
    int sum = 100;
    removeOuterParentheses(s);
    return 0;
}

