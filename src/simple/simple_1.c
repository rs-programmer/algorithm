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

int numberOfSteps(int num)
{
    int cnt = 0;
    while (num != 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num -= 1;
        }

        cnt++;
    }

    return cnt;
}

bool checkIfExist(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if ((i != j) && (arr[i] * 2 == arr[j])) {
                return true;
            }
        }
    }

    return false;
}

int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int row = gridSize;
    int col = gridColSize[0];
    int cnt = 0;

    int new_col = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < new_col; j++) {
            if (grid[i][j] < 0) {
                cnt += (new_col - j) * (row - i);
                new_col = j;
                break;
            }
        }
    }

    return cnt;
}

bool cmp_one(int *a, int *b)
{
    /* *a 中 1 的个数 */
    int one_a = 0, one_b = 0;
    int tmp_a = *a, tmp_b = *b;

    while (tmp_a != 0 || tmp_b != 0) {
        if (tmp_a != 0) {
            if (tmp_a & 0x01 == 1) {
                one_a++;
            }
            tmp_a >>= 1;
        }

        if (tmp_b != 0) {
            if (tmp_b & 0x01 == 1) {
                one_b++;
            }
            tmp_b >>= 1;
        }
    }

    if (one_a == one_b) {
        return (*a) > (*b);
    } else {
        return one_a > one_b;
    }
}

int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * arrSize);
    memcpy(ans, arr, sizeof(int) * arrSize);

    /* 自定义排序算法 */
    qsort(ans, arrSize, sizeof(int), cmp_one);
    *returnSize = arrSize;
    return ans;
}

int getDate(char *date)
{
    int y, m, d;
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    sscanf(date, "%d-%d-%d", &y, &m, &d);

    /* year */
    int sum = 0;
    for (int i = 1970; i < y; i++) {
        if (isLeap(i)) {
            sum += 366;
        } else {
            sum += 365;
        }
    }

    /* month */
    for (int i = 1; i < m; i++) {
        sum += month[i];
        if ((i == 2) && (isLeap(y))) {
            sum += 1;
        }
    }

    /* day */
    sum += d;

    return sum;
}

int daysBetweenDates(char *date1, char *date2)
{
    int sum1 = getDate(date1);
    int sum2 = getDate(date2);

    return abs(sum2 - sum1);
}

int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i != j && nums[j] < nums[i]) {
                cnt++;
            }
        }

        ans[*returnSize] = cnt;
        *returnSize += 1;
    }

    return ans;
}

bool cmp(char *a, char *b)
{
    return *a > *b;
}

char *sortString(char *s)
{
    // copy
    int s_len = strlen(s);
    char *str = (char *)malloc(sizeof(char) * (s_len + 1));
    strcpy(str, s);

    // qsort
    qsort(str, s_len, sizeof(char), cmp);
    char *ans = (char *)malloc(sizeof(char) * (s_len + 1));
    int ans_id = 0;
    int cnt = 0;

    while (cnt < s_len) {
        // 选择最小字符
        char min = '0';
        for (int i = 0; i < s_len; i++) {
            if (str[i] == '0') {
                continue;
            }

            if (min == '0' || str[i] > min) {
                min = str[i];
                ans[ans_id++] = min;
                str[i] = '0';
                cnt++;
            }
        }

        // 选择最大字符
        char max = '0';
        for (int i = s_len - 1; i >= 0; i--) {
            if (str[i] == '0') {
                continue;
            }

            if (max == '0' || str[i] < max) {
                // 首次找到了最大字符
                max = str[i];
                ans[ans_id++] = max;
                str[i] = '0';
                cnt++;
            }
        }
    }

    ans[ans_id++] = '\0';
    return ans;
}

char *generateTheString(int n)
{
    char *ans = (char *)malloc(sizeof(char) * (n + 1));
    memset(ans, 'a', n);
    if (n % 2 == 0) {
        ans[n - 1] = 'b';
    }

    ans[n] = '\0';
    return ans;
}

int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int row = matrixSize;
    int col = matrixColSize[0];
    int *ans = (int *)malloc(sizeof(int) * row);
    *returnSize = 0;

    int min_id;
    bool flag;
    for (int i = 0; i < row; i++) {
        min_id = 0;
        flag = true;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] < matrix[i][min_id]) {
                min_id = j;
            }
        }

        for (int r = 0; r < row; r++) {
            if (matrix[r][min_id] > matrix[i][min_id]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans[*returnSize] = matrix[i][min_id];
            *returnSize += 1;
        }
    }

    return ans;
}

bool cmp_up(int *a, int *b)
{
    return *a > *b;
}

int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
    int id2 = 1;
    int cnt = 0;
    for (int i = 0; i < arr1Size; i++) {
        int j = 0;
        for (j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                break;
            }
        }

        if (j == arr2Size) {
            cnt++;
        }
    }

    return cnt;
}

typedef struct target_arr {
    int val;
    struct target_arr *next;
} target_arr_link;

void insert(target_arr_link *head, int index, int val)
{
    int id = 0;
    target_arr_link *parent = head;
    target_arr_link *p = parent->next;

    while (id < index) {
        parent = p;
        p = p->next;
        id++;
    }

    // 插入
    target_arr_link *tmp = (target_arr_link *)malloc(sizeof(target_arr_link));
    tmp->val = val;
    tmp->next = p;
    parent->next = tmp;
}

int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize)
{
    target_arr_link head;
    head.next = NULL;

    for (int i = 0; i < indexSize; i++) {
        insert(&head, index[i], nums[i]);
    }

    int *ans = (int *)malloc(sizeof(int) * indexSize);
    *returnSize = 0;
    target_arr_link *p = head.next;
    target_arr_link *tmp;
    while (p != NULL) {
        tmp = p->next;
        ans[*returnSize] = p->val;
        *returnSize += 1;
        free(p);
        p = tmp;
    }

    return ans;
}

bool cmp_down(int *a, int *b)
{
    return *b > *a;
}

int findLucky(int *arr, int arrSize)
{
    // 从大到小
    qsort(arr, arrSize, sizeof(int), cmp_down);

    // 查询第一个幸运数字
    int id = 0, i;
    for (i = 1; i < arrSize; i++) {
        if (arr[i] != arr[id]) {
            // 计算频次
            if (arr[id] == (i - id)) {
                return arr[id];
            }

            id = i;
        }
    }

    // 计算频次
    if (arr[id] == (i - id)) {
        return arr[id];
    }

    return -1;
}

int countLargestGroup(int n)
{
}