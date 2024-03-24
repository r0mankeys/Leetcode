// This program will (given an array of integers) return an array of 
// the indices of the two numbers that add up to a specific target.

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int *two_sum_bad(int *nums, int nums_size, int target);

int *two_sum_bad(int *nums, int nums_size, int target)
{
    for (int i = 0; i < nums_size; ++i)
    {
        for (int j = i + 1; j < nums_size; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
}

int main(int argc, char *argv[])
{
    int numbers[] = {2, 7, 11, 15};
    int target = 9;

    int numbers2[] = {3, 2, 4};
    int target2 = 6;

    int *result1 = two_sum_bad(numbers, ARRAY_SIZE(numbers), target);
    int *result2 = two_sum_bad(numbers2, ARRAY_SIZE(numbers2), target2);

    if (result1)
    {
        printf("{%d, %d}\n", result1[0], result1[1]);
    } else 
    {
        printf("No two sum solution\n");
    }

    if (result2)
    {
        printf("{%d, %d}\n", result2[0], result2[1]);
    } else 
    {
        printf("No two sum solution\n");
    }

    return 0;
}
