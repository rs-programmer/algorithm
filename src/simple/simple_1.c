#include "simple_1.h"

int largestSumAfterKNegations(int* nums, int numsSize, int k)
{
    /* fast_sort 从小到大排序 */
    fast_sort(nums, 0, numsSize - 1);

    /* 正数变负数 */
    for (int i = 0; i < numsSize; i++) {
        if (k <= 0) {
            break;
        }
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        } else if (nums[i] == 0) {
            k = 0;
            break;
        } else {
            break;
        }
    }

    if (k != 0) {
        fast_sort(nums, 0, numsSize - 1);
        if (k % 2 != 0) {
            nums[0] = -nums[0];
        }
    }

    /* 累加 */
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += nums[i];
    }

    return ans;
}

int bitwiseComplement(int n)
{
    if (n == 0) {
        return 1;
    }
    /* 使用链表的尾插法保存 n 的二进制数据 */
    link_t* link = create_link();
    while (n) {
        append_link(link, n % 2);
        n /= 2;
    }

    /* 链表元素取反 */
    link_node_t *tmp = link->head;
    while (tmp != NULL) {
        tmp->val = tmp->val == 0? 1 : 0;
        tmp = tmp->next;
    }

    /* 计算结果 */
    int ans = 0;
    int pw = 1;
    tmp = link->head;
    while (tmp != NULL) {
        ans += tmp->val * pw;
        pw *= 2;
        tmp = tmp->next;
    }

    free_link(link);
    return ans;
}
