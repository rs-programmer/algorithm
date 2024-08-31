#include "search.h"

int search_binary(int *nums, int numsSize, int target)
{
    /* 二分法查找 */
    int left = 0, right = numsSize - 1;
    int mid;

    /* left <= target <= right */
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            /* 1. 直接返回下标值 */
            // return mid;

            /* 2. 左边界 */
            if ((mid == 0) || (nums[mid - 1] != nums[mid])) {
                return mid;
            } else {
                right = mid - 1;
            }

            /* 3. 右边界 */
            // if ((mid == numsSize - 1) || (nums[mid + 1] != nums[mid])) {
            //     return mid;
            // } else {
            //     left = mid + 1;
            // }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    /* right < target < left */
    return -1;
}
