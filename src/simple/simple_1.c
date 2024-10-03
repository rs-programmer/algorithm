#include "simple_1.h"

int largestSumAfterKNegations(int *nums, int numsSize, int k)
{
    /* fast_sort 从小到大排序 */
    fast_sort(nums, 0, numsSize - 1);

    /* 正数变负数 */
    for (int i = 0; i < numsSize; i++)
    {
        if (k <= 0)
        {
            break;
        }
        if (nums[i] < 0)
        {
            nums[i] = -nums[i];
            k--;
        }
        else if (nums[i] == 0)
        {
            k = 0;
            break;
        }
        else
        {
            break;
        }
    }

    if (k != 0)
    {
        fast_sort(nums, 0, numsSize - 1);
        if (k % 2 != 0)
        {
            nums[0] = -nums[0];
        }
    }

    /* 累加 */
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ans += nums[i];
    }

    return ans;
}

int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 1;
    }
    /* 使用链表的尾插法保存 n 的二进制数据 */
    link_t *link = create_link();
    while (n)
    {
        append_link(link, n % 2);
        n /= 2;
    }

    /* 链表元素取反 */
    link_node_t *tmp = link->head;
    while (tmp != NULL)
    {
        tmp->val = tmp->val == 0 ? 1 : 0;
        tmp = tmp->next;
    }

    /* 计算结果 */
    int ans = 0;
    int pw = 1;
    tmp = link->head;
    while (tmp != NULL)
    {
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
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }

    if (sum % 3 != 0)
    {
        return false;
    }

    sum /= 3;
    /* 寻找 i */
    int i = 0;
    int sum_i = 0;
    for (i = 0; i < arrSize; i++)
    {
        sum_i += arr[i];
        if (sum_i == sum)
        {
            break;
        }
    }

    if (i >= arrSize - 2)
    {
        return false;
    }

    /* 寻找 j */
    int j = 0;
    int sum_j = 0;
    for (j = i + 1; j < arrSize; j++)
    {
        sum_j += arr[j];
        if (sum_j == sum)
        {
            break;
        }
    }

    if (j >= arrSize - 1)
    {
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
    for (int i = 0; i < numsSize; i++)
    {
        sum = sum * 2 + nums[i];
        sum %= 10;
        if (sum % 5 == 0)
        {
            ans[ans_len] = true;
        }
        else
        {
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

    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == '(')
        {
            num++;
        }
        else if (s[i] == ')')
        {
            num--;
        }

        if (num == 0)
        {
            /* 当前是一个原语 */
            cur++;
            int next = i;
            next--;
            if (next > cur)
            {
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
    if (root->left == root->right && root->left == NULL)
    {
        /* 叶子节点 */
        *total += sum;
        return;
    }

    if (root->left != NULL)
    {
        sumNode(root->left, sum, total);
    }

    if (root->right != NULL)
    {
        sumNode(root->right, sum, total);
    }
}

int sumRootToLeaf(struct TreeNode *root)
{
    int total = 0;
    if (root == NULL)
    {
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

/* 自定义一个结构体 */
typedef struct cell
{
    int x;
    int y;
    int r; /* 距离 */
} cell_t;

int compar(cell_t *c1, cell_t *c2)
{
    return c1->r > c2->r;
}

int **allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int *returnSize, int **returnColumnSizes)
{
    int sum = rows * cols;
    *returnSize = sum;
    *returnColumnSizes = (int *)malloc(sizeof(int) * sum);
    for (int i = 0; i < sum; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }

    /* 计算每一个元素到 rc rr 的距离 */
    cell_t *ces = (cell_t *)malloc(sizeof(cell_t) * sum);
    int ces_len = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ces[ces_len].x = i;
            ces[ces_len].y = j;
            ces[ces_len].r = abs(i - rCenter) + abs(j - cCenter);
            ces_len++;
        }
    }

    /* 自定义排序规则 */
    qsort(ces, ces_len, sizeof(cell_t), compar);

    /* 数据拷贝 */
    int **ans = (int **)malloc(sizeof(int *) * sum);
    int ans_len = 0;
    for (int i = 0; i < ces_len; i++)
    {
        int *arr = (int *)malloc(sizeof(int) * 2);
        arr[0] = ces[i].x;
        arr[1] = ces[i].y;
        ans[ans_len++] = arr;
    }

    /* 数据销毁 */
    free(ces);

    return ans;
}

int lastStoneWeight(int *stones, int stonesSize)
{
    /* max1 < max2 */
    int max1, max2;
    int max1_id, max2_id;
    while (1)
    {
        max1 = -2, max2 = -1;
        max1_id = -2, max2_id = -1;
        for (int i = 0; i < stonesSize; i++)
        {
            if (stones[i] > max2)
            {
                max1 = max2;
                max1_id = max2_id;
                max2 = stones[i];
                max2_id = i;
            }
            else if (stones[i] > max1)
            {
                max1 = stones[i];
                max1_id = i;
            }
        }

        if (max2 == -1)
        {
            /* 全部是否都碎掉了 */
            return 0;
        }
        else if (max1 == -1)
        {
            /* 还剩下一块石头 */
            return max2;
        }
        else
        {
            /* 存在最大的两个石头 */
            int x = max2 - max1;
            stones[max1_id] = -1;
            if (x > 0)
            {
                stones[max2_id] = x;
            }
            else
            {
                stones[max2_id] = -1;
            }
        }
    }
}

char *removeDuplicates(char *s)
{
    int s_len = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * (s_len + 1));
    int ans_len = 0;
    for (int i = 0; i < s_len; i++)
    {
        ans[ans_len] = s[i];
        /* 判断是否重复 */
        if (ans_len > 0 && ans[ans_len - 1] == ans[ans_len])
        {
            ans_len--;
        }
        else
        {
            ans_len++;
        }
    }

    ans[ans_len] = '\0';
    return ans;
}

int heightChecker(int *heights, int heightsSize)
{
    int *ans = (int *)malloc(sizeof(int) * heightsSize);
    memcpy(ans, heights, sizeof(int) * heightsSize);
    /* 快排 */
    fast_sort(heights, 0, heightsSize - 1);
    int n = 0;
    for (int i = 0; i < heightsSize; i++)
    {
        if (ans[i] != heights[i])
        {
            n++;
        }
    }

    free(ans);
    return n;
}

bool check(char *tar, char *src)
{
    int tar_len = strlen(tar);
    int src_len = strlen(src);

    int n = src_len / tar_len;
    char *tmp = (char *)malloc(sizeof(char) * (src_len + 1));
    int tmp_id = 0;

    for (int i = 0; i < n; i++)
    {
        memcpy(tmp + i * tar_len, tar, tar_len);
        tmp_id += tar_len;
    }
    tmp[tmp_id] = '\0';
    int cmp = memcmp(tmp, src, src_len);
    free(tmp);
    return cmp == 0;
}

char *gcdOfStrings(char *str1, char *str2)
{
    /* 穷举法 */
    int s1_len = strlen(str1);
    int s2_len = strlen(str2);
    int min_len = 0;
    int max_len = 0;
    char *min_str = NULL;
    char *max_str = NULL;

    if (s1_len < s2_len)
    {
        min_len = s1_len;
        max_len = s2_len;
        min_str = str1;
        max_str = str2;
    }
    else
    {
        min_len = s2_len;
        max_len = s1_len;
        min_str = str2;
        max_str = str1;
    }

    char *ans = (char *)malloc(sizeof(char) * (min_len + 1));
    int ans_id = 0;
    char *tmp = (char *)malloc(sizeof(char) * (max_len + 1));
    int tmp_id = 0;

    for (int i = 1; i <= min_len; i++)
    {
        if (min_len % i != 0 || max_len % i != 0)
        {
            continue;
        }

        /* 复制 */
        memcpy(tmp, min_str, i);
        tmp[i] = '\0';

        /* 判断 */
        if (check(tmp, min_str) && check(tmp, max_str))
        {
            memcpy(ans, min_str, i);
            ans_id = i;
        }
    }

    free(tmp);
    ans[ans_id] = '\0';
    return ans;
}

char **findOcurrences(char *text, char *first, char *second, int *returnSize)
{
    *returnSize = 0;
    int text_len = strlen(text);

    char **text_arr = (char **)malloc(sizeof(char *) * text_len);
    int text_arr_len = 0;

    char *text_buf = (char *)malloc(sizeof(char) * (text_len + 1));
    strcpy(text_buf, text);

    /* 切割 */
    char *context = strtok(text_buf, " ");
    while (context != NULL)
    {
        char *tmp = (char *)malloc(sizeof(char) * (strlen(context) + 1));
        strcpy(tmp, context);
        text_arr[text_arr_len++] = tmp;
        context = strtok(NULL, " ");
    }

    /* 匹配 */
    char **ans = (char **)malloc(sizeof(char *) * text_len);
    for (int i = 0; i < text_arr_len - 2; i++)
    {
        if (strcmp(text_arr[i], first) == 0 &&
            strcmp(text_arr[i + 1], second) == 0)
        {
            char *p = (char*)malloc(sizeof(char) * (strlen(text_arr[i + 2]) + 1));
            strcpy(p, text_arr[i + 2]);
            ans[*returnSize] = p;
            *returnSize += 1;
        }
    }

    /* 销毁 */
    for (int i = 0; i < text_arr_len; i++)
    {
        free(text_arr[i]);
    }
    free(text_arr);
    free(text_buf);

    return ans;
}

void duplicateZeros(int* arr, int arrSize)
{
    int *ans = (int*)malloc(sizeof(int) * arrSize);
    int ans_len = 0;
    for (int i = 0; ans_len < arrSize; i++, ans_len++) {
        ans[ans_len] = arr[i];
        if (ans[ans_len] == 0 && ans_len < arrSize - 1) {
            ans_len++;
            ans[ans_len] = 0;
        }
    }

    /* 复制 */
    for (int i = 0; i < arrSize; i++) {
        arr[i] = ans[i];
    }

    free(ans);
}

int* distributeCandies(int candies, int num_people, int* returnSize)
{
    /* 分配 */
    int cnt = 0;
    int *ans = (int*)calloc(num_people, sizeof(int));
    *returnSize = num_people;

    while (candies) {
        ans[cnt % num_people] += min_int(candies, cnt + 1);
        candies -= min_int(candies, cnt + 1);
        cnt++;
    }

    return ans;
}

char * defangIPaddr(char * address)
{
    int len = strlen(address);
    char *ans = (char*)malloc(sizeof(char) * len * 2);
    int ans_len = 0;

    for (int i = 0; i < len; i++) {
        if (address[i] != '.') {
            ans[ans_len++] = address[i];
        } else {
            ans[ans_len++] = '[';
            ans[ans_len++] = '.';
            ans[ans_len++] = ']';
        }
    }

    ans[ans_len] = '\0';
    return ans;
}

bool cmp(void *a, void *b)
{
    return *(int*)a > *(int*)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int *ans = (int*)malloc(sizeof(int) * arr1Size);
    int ans_len = 0;

    /* 复制 */
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < arr1Size; j++) {
            if (arr2[i] == arr1[j]) {
                ans[ans_len++] = arr1[j];
                arr1[j] = -1;
            }
        }
    }

    /* 排序 */
    qsort(arr1, arr1Size, sizeof(int), cmp);

    /* 添加 */
    for (int i = ans_len; i < arr1Size; i++) {
        ans[ans_len++] = arr1[i];
    }

    *returnSize = ans_len;
    return ans;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
    int cnt[10][10] = {0};
    for (int i = 0; i < dominoesSize; ++i) {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        if (a < b) {
            cnt[a][b]++;
        } else {
            cnt[b][a]++;
        }
    }
    int ret = 0;
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            ret += cnt[i][j] * (cnt[i][j] - 1) / 2;
        }
    }
    return ret;
}

int tribonacci(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    }

    int a = 0, b = 1, c = 1;
    int s;
    for (int i = 3; i <= n; i++) {
        s = a + b + c;
        a = b;
        b = c;
        c = s;
    }

    return s;
}

int dayOfYear(char* date)
{
    /* m 月之前的所有天数，未加闰年 */
    int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    char *buf = (char*)malloc(sizeof(char) * (strlen(date) + 1));
    strcpy(buf, date);

    char *str = strtok(buf, "-");
    int y = atoi(str);
    str = strtok(NULL, "-");
    int m = atoi(str);
    str = strtok(NULL, "-");
    int d = atoi(str);

    int dy = days[m - 1] + d;
    if (isRyear(y) && m > 2) {
        dy += 1;
    }

    return dy;
}

int countCharacters(char** words, int wordsSize, char* chars)
{
    /* 构建 chars 哈希表 */
    int chars_hash[26] = {0};
    for (int i = 0; i < strlen(chars); i++) {
        chars_hash[chars[i] - 'a']++;
    }

    int ans = 0;
    int chars_hash_tmp[26];
    for (int i = 0; i < wordsSize; i++) {
        memcpy(chars_hash_tmp, chars_hash, sizeof(int) * 26);
        char *str = words[i];
        int len = strlen(str);
        int k;
        for (k = 0; k < len; k++) {
            if (chars_hash_tmp[str[k] - 'a'] == 0) {
                break;
            }
            chars_hash_tmp[str[k] - 'a']--;
        }

        if (k >= len) {
            ans += len;
        }
    }

    return ans;
}

int numPrimeArrangements(int n)
{
    /* 统计 [1, n] 中质数的个数 */
    int cnt = 0;
    int N = 1000000007;
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            cnt++;
        }
    }

    /* [1, n] 中质数也就是对应的下标保持一致 */
    /* 全排列组合 */
    int n1 = cnt;
    long s1 = 1;
    int n2 = n - n1;
    long s2 = 1;

    while (n1 > 1) {
        s1 = s1 * n1 % N;
        n1 -= 1;
    }

    while (n2 > 1) {
        s2 *= n2;
        s2 %= N;
        n2 -= 1;
    }

    return s1 * s2 % N;
}

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
{
    /* 计算 start --> des */
    int sum1 = 0;
    for (int i = start; i != destination; i = (i + 1) % distanceSize) {
        sum1 += distance[i];
    }

    /* 计算 des ---> start */
    int sum2 = 0;
    for (int i = destination; i != start; i = (i + 1) % distanceSize) {
        sum2 += distance[i];
    }

    return sum1 < sum2? sum1 : sum2;
}

