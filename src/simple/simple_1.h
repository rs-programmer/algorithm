#ifndef simple_1_h
#define simple_1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "tools.h"
#include "hash.h"
#include "map.h"
#include "stack.h"
#include "sort.h"
#include "queue.h"
#include "link.h"

#include "type.h"

int largestSumAfterKNegations(int *nums, int numsSize, int k);
int bitwiseComplement(int n);
bool canThreePartsEqualSum(int *arr, int arrSize);
bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize);
char *removeOuterParentheses(char *s);
int sumRootToLeaf(struct TreeNode *root);
bool divisorGame(int n);
int *kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize);
int numberOfSteps(int num);
bool checkIfExist(int *arr, int arrSize);
int countNegatives(int **grid, int gridSize, int *gridColSize);
int *sortByBits(int *arr, int arrSize, int *returnSize);
int daysBetweenDates(char *date1, char *date2);
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize);
char *sortString(char *s);
char* generateTheString(int n);
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d);
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize);
int findLucky(int *arr, int arrSize);
int countLargestGroup(int n);


#endif
