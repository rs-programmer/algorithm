#ifndef simple_1_h
#define simple_1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <pthread.h>

#include "tools.h"
#include "hash.h"
#include "map.h"
#include "stack.h"
#include "sort.h"
#include "queue.h"
#include "link.h"

#include "type.h"

int largestSumAfterKNegations(int* nums, int numsSize, int k);
int bitwiseComplement(int n);
bool canThreePartsEqualSum(int* arr, int arrSize);
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize);
char* removeOuterParentheses(char* s);
int sumRootToLeaf(struct TreeNode* root);
bool divisorGame(int n);
int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes);
int lastStoneWeight(int* stones, int stonesSize);
char* removeDuplicates(char* s);
int heightChecker(int* heights, int heightsSize);
char* gcdOfStrings(char* str1, char* str2);
char** findOcurrences(char* text, char* first, char* second, int* returnSize);
void duplicateZeros(int* arr, int arrSize);
int* distributeCandies(int candies, int num_people, int* returnSize);
char * defangIPaddr(char * address);
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize);
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize);
int tribonacci(int n);
int dayOfYear(char* date);
int countCharacters(char** words, int wordsSize, char* chars);
int numPrimeArrangements(int n);
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination);




#endif
