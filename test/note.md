### C语言编译

```c
// 预编译 深度递归预编译
gcc -E main.c -o main.i

// 编译
gcc -S main.i -o main.s

// 汇编
gcc -c main.s -o main.o
gcc -c main.c -o main.o

// 链接
gcc main.o main