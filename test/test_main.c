#include "simple.h"
#include "simple_1.h"

int main()
{
    int size = 0;
    findOcurrences("alice is a good girl she is a good student",
                   "a", "good", &size);
    return 0;
}
