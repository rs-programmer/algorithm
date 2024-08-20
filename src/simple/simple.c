#include "simple.h"

static void map_char_prosearch(map_char_t *map_char, char **p_str, int *minVal)
{
    if (map_char == NULL) {
        return;
    }

    if (map_char->val > *minVal) {
        // 找到较大值
        *minVal = map_char->val;
        *p_str = map_char->key;
    }

    map_char_prosearch(map_char->left, p_str, minVal);
    map_char_prosearch(map_char->right, p_str, minVal);
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize)
{
    // 字符串分割
    char *p_str = strtok(paragraph, " ");
    map_char_t *map_char = NULL;

    while (p_str != NULL) {
        int p_str_len = strlen(p_str);

        // 内容拷贝到数组中
        char *p_str_arr = (char*)malloc(sizeof(char) * (p_str_len + 1));
        strcpy(p_str_arr, p_str);
        toLower(p_str_arr, p_str_len);

        // 判断是否在banned数组中
        int i = 0;
        for (i = 0; i < bannedSize; i++) {
            if (strcmp(p_str_arr, banned[i]) == 0) {
                break;
            }
        }

        if (i < bannedSize) {
            // 是禁用字符串
            p_str = strtok(NULL, " ");
            continue;
        }

        // 添加到map中
        map_char = add_map_char(map_char, p_str_arr, 1);
        p_str = strtok(NULL, " ");
    }

    // 查询二叉树中 val最大的值
    char *min_p_str = NULL;
    int minVal = 0;
    map_char_prosearch(map_char, &min_p_str, &minVal);

    return min_p_str;
}

int* shortestToChar(char* s, char c, int* returnSize)
{
    int s_len = strlen(s);
    // 创建内存空间
    int *rets = (int*)malloc(sizeof(int) * s_len);
    int *temp = (int*)malloc(sizeof(int) * s_len);

    // 查询字符串中 c 所在的位置
    int c_id = 0;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == c) {
            temp[c_id++] = i;
        }
    }

    // 计算每个字符的最小距离
    for (int i = 0; i < s_len; i++) {
        int min_dest = s_len;

        for (int j = 0; j < c_id; j++) {
            if (abs(i - temp[j]) < min_dest) {
                min_dest = abs(i - temp[j]);
            }
        }

        rets[i] = min_dest;
    }

    *returnSize = s_len;
    return rets;
}

char* toGoatLatin(char* sentence)
{
    int sen_len = strlen(sentence);
    char *p_arr = (char*)malloc(sizeof(char) * (sen_len + 1));
    strcpy(p_arr, sentence);

    char op[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    // 创建一个大数组
    char *ans = (char*) malloc(sizeof(char) * 1024); // 1KB
    char *ma = "ma";
    int ma_len = strlen(ma);

    char *p_str = strtok(p_arr, " "); // 会修改 p_arr 元数据
    bool p_flag = false; // 是否首字母为元音字母
    int p_cnt = 1; // 当前第几个字符
    int p_len = 0; // 当前字符的长度
    int ans_id = 0; // ans 数组中已存入数据长度

    while (p_str != NULL) {
        p_flag = false;
        p_len = strlen(p_str);

        for (int i = 0; i < 10; i++) {
            if (op[i] == *p_str) {
                p_flag = true;
                break;
            }
        }

        if (p_flag == false) {
            // 元音字母开头，元素移动
            char p_char = *p_str;
            memmove(p_str, p_str + 1, p_len - 1);
            p_str[p_len - 1] = p_char;
        }

        // 拷贝
        memcpy(ans + ans_id, p_str, p_len);
        ans_id += p_len;

        // ma
        memcpy(ans + ans_id, ma, ma_len);
        ans_id += ma_len;

        // p_cnt 个 a
        memset(ans + ans_id, 'a', p_cnt);
        ans_id += p_cnt;

        // 空格
        ans[ans_id] = ' ';
        ans_id++;

        // 数据更新
        p_str = strtok(NULL, " ");
        p_cnt++;
    }

    // 取消最后一个字符的空格
    ans_id--;
    ans[ans_id] = '\0';

    free(p_arr);
    return ans;
}

int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes)
{
    int s_len = strlen(s);
    *returnSize = 0;

    int **ans_arr = (int**)malloc(sizeof(int*) * s_len);
    *returnColumnSizes = (int*)malloc(sizeof(int) * s_len);

    int j = 0, i = 1;
    for (i = 1; i < s_len; i++) {
        if (s[j] != s[i]) {
            if ((i - j) >= 3) {
                // 符合条件
                int *tmp_arr = (int*)malloc(sizeof(int) * 2);
                tmp_arr[0] = j;
                tmp_arr[1] = i - 1;
                ans_arr[*returnSize] = tmp_arr;
                (*returnColumnSizes)[*returnSize] = 2;

                *returnSize += 1;
            }

            j = i; // 更新 j
        }
    }

    if (i - j >= 3) {
        // 符合条件
        int *tmp_arr = (int*)malloc(sizeof(int) * 2);
        tmp_arr[0] = j;
        tmp_arr[1] = i - 1;
        ans_arr[*returnSize] = tmp_arr;
        (*returnColumnSizes)[*returnSize] = 2;

        *returnSize += 1;
    }

    return ans_arr;
}

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes)
{
    int row = imageSize;
    int col = *imageColSize;

    int **ans_arr = (int**)malloc(sizeof(int*) * row);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);

    // 循环每一行
    for (int i = 0; i < row; i++) {
        // copy
        int *tmp_arr = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            tmp_arr[j] = image[i][j];
        }

        int left = 0, right = col - 1;
        while (left < right) {
            // 反转
            tmp_arr[left] = tmp_arr[left] == 1? 0 : 1;
            tmp_arr[right] = tmp_arr[right] == 1? 0 : 1;

            //  交换
            int tmp = tmp_arr[left];
            tmp_arr[left] = tmp_arr[right];
            tmp_arr[right] = tmp;

            // 更新
            left++;
            right--;
        }

        // 判断最后
        if (left == right) {
            tmp_arr[left] = tmp_arr[left] == 1? 0 : 1;
        }

        // 数据添加
        ans_arr[*returnSize] = tmp_arr;
        (*returnColumnSizes)[*returnSize] = col;
        (*returnSize) += 1;
    }

    return ans_arr;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    int x1 = rec1[0], x2 = rec1[2], x3 = rec2[0], x4 = rec2[2];
    int y1 = rec1[1], y2 = rec1[3], y3 = rec2[1], y4 = rec2[3];

    bool isRow = (x2 > x3) && (x1 < x4);
    bool isCol = (y2 > y3) && (y1 < y4);

    return isRow && isCol;
}

bool backspaceCompare(char* s, char* t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);

    stack_t *s_stack = create_stack(s_len);
    stack_t *t_stack = create_stack(t_len);

    // 处理 s
    for (int i = 0; i < s_len; i++) {
        if (s[i] == '#') {
            pop_stack(s_stack);
        } else {
            push_stack(s_stack, s[i]);
        }
    }

    // 处理 t
    for (int i = 0; i < t_len; i++) {
        if (t[i] == '#') {
            pop_stack(t_stack);
        } else {
            push_stack(t_stack, t[i]);
        }
    }

    // 对比
    while (!is_empty_stack(s_stack) && !is_empty_stack(t_stack)) {
        if (top_stack(s_stack) != top_stack(t_stack)) {
            return false;
        }

        pop_stack(s_stack);
        pop_stack(t_stack);
    }

    if (!is_empty_stack(s_stack) || !is_empty_stack(t_stack)) {
        return false;
    }

    return true;
}

bool buddyStrings(char* s, char* goal)
{
    // 等价于仅存在两个字符不相同
    int s_len = strlen(s);
    int goal_len = strlen(goal);

    if (s_len != goal_len) {
        return false;
    }

    int id_x[3];
    int hash_char[26] = {0};
    int cnt = 0; // 不相同字符的个数
    for (int i = 0; i < s_len; i++) {
        hash_char[s[i] - 'a'] += 1;
        if (s[i] != goal[i]) {
            id_x[cnt] = i;
            cnt++;
        }

        if (cnt == 3) {
            return false;
        }
    }

    if (cnt == 0) {
        // 完全相同的两个字符串，查看是否存在重复元素
        for (int j = 0; j < 26; j++) {
            if (hash_char[j] >= 2) {
                return true;
            }
        }

        return false;
    } else if (cnt != 2) {
        return false;
    }

    // 交换 对比
    if (s[id_x[0]] == goal[id_x[1]] && s[id_x[1]] == goal[id_x[0]]) {
        return true;
    }

    return false;
}

bool lemonadeChange(int* bills, int billsSize)
{
    int num_5 = 0, num_10 = 0, num_20 = 0;

    for (int i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5) {
            num_5++;
        } else if (bills[i] == 10) {
            num_5--;
            num_10++;
        } else if (bills[i] == 20) {
            // 尽量保留 num_5 的数据
            if (num_10 > 0) {
                num_10--;
                num_5--;
            } else {
                num_5 -= 3;
            }
        }

        // 判断 num_5
        if (num_5 < 0) {
            return false;
        }
    }

    return true;    
}

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int row = matrixSize;
    int col = *matrixColSize;

    // 创建 col 行，row 列 的数组
    *returnSize = 0;
    int **ans_arr = (int**)malloc(sizeof(int*) * col);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * col);
    for (int i = 0; i < col; i++) {
        int *tmp_arr = (int*)malloc(sizeof(int) * row);
        // 数据填充
        for (int r = 0; r < row; r++) {
            tmp_arr[r] = matrix[r][i];
        }

        ans_arr[*returnSize] = tmp_arr;
        (*returnColumnSizes)[*returnSize] = row;
        *returnSize += 1;
    }

    return ans_arr;
}

int binaryGap(int n)
{
    int i = 0, j = 0;
    int max_dest = 0;

    // 预处理 j i 指向第一个 1 的位置
    while (n != 0) {
        if (n & 1 == 1) {
            break;
        }

        i++;
        n >>= 1;
    }

    j = i;

    while (n != 0) {
        if (n & 1 == 1) {
            // 判断 j --> i 的距离
            if (j - i > max_dest) {
                max_dest = j - i;
            }
            i = j;
        }

        j++;
        n >>= 1;
    }

    return max_dest;
}

void pre_search_tree(struct TreeNode* root, int *arr, int *id)
{
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        // 叶子节点
        arr[*id] = root->val;
        *id += 1;
    }

    pre_search_tree(root->left, arr, id);
    pre_search_tree(root->right, arr, id);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int arr_1[200] = {0}, id_1 = 0;
    int arr_2[200] = {0}, id_2 = 0;

    pre_search_tree(root1, arr_1, &id_1);
    pre_search_tree(root2, arr_2, &id_2);

    if (id_1 != id_2) {
        return false;
    }

    // 遍历
    for (int i = 0; i < id_1; i++) {
        if (arr_1[i] != arr_2[i]) {
            return false;
        }
    }

    return true;
}

struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    // 定义
    struct ListNode *mid = head;

    int node_cnt = 1; // 节点个数
    while (head != NULL) {
        if (node_cnt % 2 == 0) {
            mid = mid->next;
        }

        node_cnt++;
        head = head->next;
    }

    return mid;
}

int projectionArea(int** grid, int gridSize, int* gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;

    // xy 平面面积 = 非零元素个数
    int area_xy = 0;
    
    // yz 平面面积 = 每一行的最大值之和
    int area_yz = 0;
    for (int i = 0; i < row; i++) {
        // 统计每行的最大值
        int max_row = 0;
        for (int j = 0; j < col; j++) {
            if (grid[i][j] > max_row) {
                max_row = grid[i][j];
            }

            if (grid[i][j] != 0) {
                area_xy++;
            }
        }

        area_yz += max_row;
    }

    // xz 平面面积 = 每列的最大值之和
    int area_xz = 0;
    for (int i = 0; i < col; i++) {
        // 统计每列的最大值
        int max_col = 0;
        for (int j = 0; j < row; j++) {
            if (grid[j][i] > max_col) {
                max_col = grid[j][i];
            }
        }

        area_xz += max_col;
    }

    return area_xy + area_yz + area_xz;
}

char** uncommonFromSentences(char* s1, char* s2, int* returnSize)
{
    *returnSize = 0;

    // 内容拷贝 常量字符串不可修改
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    *returnSize = 0;

    char **ans_arr = (char**)malloc(sizeof(char*) * (s1_len + s2_len));

    // 合并 s1 s2
    char *p_arr = (char*)malloc(sizeof(s1) * (s1_len + s2_len + 2));
    strcpy(p_arr, s1);
    p_arr[s1_len] = ' ';
    strcpy(p_arr + s1_len + 1, s2);

    // 整合为二维数组
    char **tar_arr = (char**)malloc(sizeof(char*) * (s1_len + s2_len));
    int tar_arr_len = 0;

    char *p_tok = strtok(p_arr, " ");
    while (p_tok != NULL) {
        char *tmp = (char*)malloc(sizeof(char) * (strlen(p_tok) + 1));
        strcpy(tmp, p_tok);
        tar_arr[tar_arr_len] = tmp;
        tar_arr_len++;
        p_tok = strtok(NULL, " ");
    }

    // 销毁 p_arr
    free(p_arr);
    p_arr = NULL;

    // 统计 tar_arr 中仅出现一次的字符串
    for (int i = 0; i < tar_arr_len; i++) {
        int j;
        for (j = 0; j < tar_arr_len; j++) {
            if (i == j) {
                continue;
            }

            if (strcmp(tar_arr[i], tar_arr[j]) == 0) {
                // 出现相同
                break;
            }
        }

        if (j == tar_arr_len) {
            // 仅出现一次
            char *tmp = (char*)malloc(sizeof(char) * (strlen(tar_arr[i]) + 1));
            strcpy(tmp, tar_arr[i]);
            ans_arr[*returnSize] = tmp;
            *returnSize += 1;
        }
    }

    // 销毁 tar_arr
    for (int i = 0; i < tar_arr_len; i++) {
        free(tar_arr[i]);
    }
    free(tar_arr);
    tar_arr = NULL;

    return ans_arr;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize)
{
    /* 由数学计算可知，2*(x1-x2) = k; (m1 + x1) - (m2 + x2) = k*/
    
    /* 采用 hash 数据结构实现 */
    int sum_alic = 0;
    int sum_bob = 0;

    hash_int_t *hash_bob = NULL;

    for (int i = 0; i < aliceSizesSize; i++) {
        sum_alic += aliceSizes[i];
    }

    for (int i = 0; i < bobSizesSize; i++) {
        hash_bob = add_hash_int(hash_bob, bobSizes[i]);
        sum_bob += bobSizes[i];
    }

    int k = sum_alic - sum_bob;

    /* 查找数据 */
    int *ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i <aliceSizesSize; i++) {
        int alic = aliceSizes[i];
        int bob = alic - (k / 2);

        if (find_hash_int(hash_bob, bob) == 0) {
            /* 找到相关元素 */
            ans[0] = alic;
            ans[1] = bob;
            break;
        }
    }

    free_hash_int(hash_bob);

    return ans;
}


int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
    int area_sum = 0;
    int min_hight = 0;

    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            /* 先计算总面积 */
            if (grid[row][col] > 0) {
                area_sum += (2 + grid[row][col] * 4);
            }

            /* 下一行需要剪掉的面积 */
            if (row < gridSize - 1) {
                min_hight = min_int(grid[row][col], grid[row+1][col]);
                area_sum -= min_hight * 2;
            }

            /* 下一列需要剪掉的面积 */
            if (col < gridColSize[row] - 1) {
                min_hight = min_int(grid[row][col], grid[row][col+1]);
                area_sum -= min_hight * 2;
            }
        }
    }

    return area_sum;
}

bool isMonotonic(int* nums, int numsSize)
{
    /* 数据趋势标志 */
    int k = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (k == 0) {
            if (nums[i + 1] > nums[i]) {
                k = 1; /* 升序 */
            } else if (nums[i + 1] < nums[i]) {
                k = -1; /* 降序 */
            } else {
                k = 0; /* 平序 */
            }
        } else if (k == 1) {
            /* 升序的情况 */
            if (nums[i + 1] < nums[i]) {
                return false;
            }
        } else if (k == -1) {
            /* 降序的情况 */
            if (nums[i + 1] > nums[i]) {
                return false;
            }
        }
    }

    return true;
}

/*  ================================ */
struct TreeNode* createRightTree(struct TreeNode* root, int val)
{
    /* 创建一个新的节点 */
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    if (root == NULL) {
        /* 当前为头节点 */
        return node;
    }

    root->right = node;
    return node;
}

void treeNodeBST(struct TreeNode* root, struct TreeNode** p, struct TreeNode** head)
{
    /* 中序遍历 */
    if (root == NULL) {
        return;
    }

    treeNodeBST(root->left, p, head);

    /* 中间 */
    if (*p == NULL) {
        *p = createRightTree(*p, root->val);
        *head = *p;
    } else {
        *p = createRightTree(*p, root->val);
    }

    treeNodeBST(root->right, p, head);
}

struct TreeNode* increasingBST(struct TreeNode* root)
{
    struct TreeNode *p = NULL;
    struct TreeNode *head = NULL;
    treeNodeBST(root, &p, &head);

    return head;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
    /* 双指针法 偶数在前，奇数在后 */
    int *ans_arr = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int left = 0, right = numsSize - 1;
    while (left <= right) {
        /* left 查询奇数 */
        while ((left <= right) && (nums[left] % 2 == 0)) {
            ans_arr[left] = nums[left];
            left++;
        }

        /* right 查询偶数 */
        while ((left <= right) && (nums[right] % 2 != 0)) {
            ans_arr[right] = nums[right];
            right--;
        }

        /* 交换 left right */
        if (left <= right) {
            ans_arr[left] = nums[right];
            ans_arr[right] = nums[left];
            left++;
            right--;
        }
    }

    return ans_arr;
}
