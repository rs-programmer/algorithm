#ifndef simple_h
#define simple_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "tools.h"
#include "hash.h"
#include "map.h"
#include "stack.h"
#include "sort.h"
#include "queue.h"

#include "type.h"

char* mostCommonWord(char* paragraph, char** banned, int bannedSize);
int* shortestToChar(char* s, char c, int* returnSize);
char* toGoatLatin(char* sentence);
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes);
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes);
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size);
bool backspaceCompare(char* s, char* t);
bool buddyStrings(char* s, char* goal);
bool lemonadeChange(int* bills, int billsSize);
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes);
int binaryGap(int n);
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2);
struct ListNode* middleNode(struct ListNode* head);
int projectionArea(int** grid, int gridSize, int* gridColSize);
char** uncommonFromSentences(char* s1, char* s2, int* returnSize);
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize);
int surfaceArea(int** grid, int gridSize, int* gridColSize);
bool isMonotonic(int* nums, int numsSize);
struct TreeNode* increasingBST(struct TreeNode* root);
int* sortArrayByParity(int* nums, int numsSize, int* returnSize);
int smallestRangeI(int* nums, int numsSize, int k);
bool hasGroupsSizeX(int* deck, int deckSize);
char* reverseOnlyLetters(char* s);
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize);
bool isLongPressedName(char* name, char* typed);
int numUniqueEmails(char** emails, int emailsSize);

typedef struct {
    loop_queue_int_t *queue;
} RecentCounter;
RecentCounter* recentCounterCreate();
int recentCounterPing(RecentCounter* obj, int t);
void recentCounterFree(RecentCounter* obj);

int rangeSumBST(struct TreeNode* root, int low, int high);
bool validMountainArray(int* arr, int arrSize);
int* diStringMatch(char* s, int* returnSize);
int minDeletionSize(char** strs, int strsSize);
bool isAlienSorted(char** words, int wordsSize, char* order);
int repeatedNTimes(int* nums, int numsSize);
bool isUnivalTree(struct TreeNode* root);
int largestPerimeter(int* nums, int numsSize);
int* sortedSquares(int* nums, int numsSize, int* returnSize);
int* addToArrayForm(int* num, int numSize, int k, int* returnSize);

#endif
