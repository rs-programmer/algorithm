#include "simple_1.h"

int largestSumAfterKNegations(int *nums, int numsSize, int k)
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
    link_t *link = create_link();
    while (n) {
        append_link(link, n % 2);
        n /= 2;
    }

    /* 链表元素取反 */
    link_node_t *tmp = link->head;
    while (tmp != NULL) {
        tmp->val = tmp->val == 0 ? 1 : 0;
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

bool canThreePartsEqualSum(int *arr, int arrSize)
{
    /* 计算和 */
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }

    if (sum % 3 != 0) {
        return false;
    }

    sum /= 3;
    /* 寻找 i */
    int i = 0;
    int sum_i = 0;
    for (i = 0; i < arrSize; i++) {
        sum_i += arr[i];
        if (sum_i == sum) {
            break;
        }
    }

    if (i >= arrSize - 2) {
        return false;
    }

    /* 寻找 j */
    int j = 0;
    int sum_j = 0;
    for (j = i + 1; j < arrSize; j++) {
        sum_j += arr[j];
        if (sum_j == sum) {
            break;
        }
    }

    if (j >= arrSize - 1) {
        return false;
    }

    /* 最后一段和 = sum */
    return true;
}

bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize)
{
    bool *ans = (bool *)malloc(sizeof(bool) * numsSize);
    int ans_len = 0;

    /* 循环计算 */
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = sum * 2 + nums[i];
        sum %= 10;
        if (sum % 5 == 0) {
            ans[ans_len] = true;
        } else {
            ans[ans_len] = false;
        }

        ans_len++;
    }

    *returnSize = ans_len;
    return ans;
}

char *removeOuterParentheses(char *s)
{
    int num = 0;
    int cur = 0;
    int s_len = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * s_len);
    int ans_len = 0;

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '(') {
            num++;
        } else if (s[i] == ')') {
            num--;
        }

        if (num == 0) {
            /* 当前是一个原语 */
            cur++;
            int next = i;
            next--;
            if (next > cur) {
                /* 还存在数据 */
                memcpy(ans + ans_len, s + cur, next - cur + 1);
                ans_len += next - cur + 1;
            }
            cur = i + 1;
        }
    }

    ans[ans_len] = '\0';
    return ans;
}

void sumNode(struct TreeNode *root, int sum, int *total)
{
    sum <<= 1;
    sum |= root->val;
    if (root->left == root->right && root->left == NULL) {
        /* 叶子节点 */
        *total += sum;
        return;
    }

    if (root->left != NULL) {
        sumNode(root->left, sum, total);
    }

    if (root->right != NULL) {
        sumNode(root->right, sum, total);
    }
}

int sumRootToLeaf(struct TreeNode *root)
{
    int total = 0;
    if (root == NULL) {
        return 0;
    }

    sumNode(root, 0, &total);
    return total;
}

bool divisorGame(int n)
{
    /* 偶数赢 奇数输 */
    return !(n & 1);
}

int *kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize)
{
    int row = matSize;
    int col = matColSize[0];
    /* 统计每一行的军人数目 */
    int *soldier_num = (int *)calloc((row + 1), sizeof(int));
    for (int i = 0; i < row; i++) {
        for (int j = 0; ((j < col) && (mat[i][j] != 0)); j++) {
            soldier_num[i]++;
        }
    }

    /* 增加一个哨兵 */
    soldier_num[row] = col + 1;

    /* 查找最弱的 k 行 */
    int *ans = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        int min_id = row;
        for (int j = 0; j < row; j++) {
            if (soldier_num[j] != -1 && soldier_num[j] < soldier_num[min_id]) {
                min_id = j;
            }
        }

        if (min_id == row) {
            break;
        }

        /* 保存数据 */
        ans[i] = min_id;
        soldier_num[min_id] = -1;
    }

    free(soldier_num);
    *returnSize = k;
    return ans;
}