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


#endif
