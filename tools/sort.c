#include "sort.h"

void bubble_sort(int *arr, int len)
{
    bool isSwap;
    for (int i = 0; i < len - 1; i++) {
        isSwap = false;

        /* 每一次冒泡，将最大值移动到后面 */
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                /* 从小到大排序 */
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;

                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}


void insert_sort(int *arr, int len)
{
    /* i 之前的所有数据均为有序 */
    for (int i = 1; i < len; i++) {
        /* 获取 arr[i]，并找到需要插入的位置 */
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[++j] = val;
    }
}


void search_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        /* 选择除最大值的下表，并保存在最后一位 */
        int max = 0;
        for (int j = 0; j < len - i; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }

        /* 交换 */
        if (max != len - i - 1) {
            int tmp = arr[max];
            arr[max] = arr[len - i - 1];
            arr[len - i - 1] = tmp;
        }
    }
}

void fast_sort(int *arr, int left, int right)
{
    if (left >= right) {
        return;
    }

    /* 基准值 */
    int key = arr[left];
    int i = left, j = right;

    while (i < j) {
        /* arr[j] < key 则移动到左边 */
        while ((i < j) && (arr[j] >= key)) {
            j--;
        }
        arr[i] = arr[j];

        /* arr[i] > key 则移动到右边 */
        while ((i < j) && (arr[i] <= key)) {
            i++;
        }
        arr[j] = arr[i];
    }

    /* i == j */
    arr[i] = key;

    /* 左边 */
    if (i - left > 1) {
        fast_sort(arr, left, i - 1);
    }
    /* 右边 */
    if (right - i > 1) {
        fast_sort(arr, i + 1, right);
    }
}