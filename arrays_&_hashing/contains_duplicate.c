// Given an input array of integers
// The script should determine if there are any duplicates in the array
// If there are duplicates, return true
// If there are no duplicates, return false

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// bad solution 
bool contains_duplicate_bad(int *nums, size_t size_nums);
// good solution with helper sorting and swap functions
void swap(int *a, int *b);
void quick_sort(int *nums, size_t size_nums);
bool contains_duplicate_good(int *nums, size_t size_nums);

bool contains_duplicate_bad(int *nums, size_t size_nums)
{
    for (size_t i = 0; i < size_nums; ++i)
    {
        for (size_t j = i + 1; j < size_nums; ++j)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}   

void quick_sort(int *nums, size_t size_nums)
{
    // If the array contains one or no elements, it does not need to be sorted
    if (size_nums <= 1)
    {
        return;
    } else if (size_nums == 2)
    // If the array contains two elements, they can be swapped if necessary
    {
        if (nums[0] > nums[1])
        {
            swap(&nums[0], &nums[1]);
        }
        return;
    }

    int pivot = nums[0];
    int left = 1;
    int right = size_nums - 1;

    while (left <= right)
    {
        if (nums[left] <= pivot)
        {
            ++left;
        } else if (nums[right] > pivot)
        {
            --right;
        } else
        {
            swap(&nums[left], &nums[right]);
            ++left;
            --right;
        }
    }

    // Put the pivot in the correct position
    swap(&nums[0], &nums[right]);

    quick_sort(nums, right);
    quick_sort(nums + left, size_nums - left);
}

bool contains_duplicate_good(int *nums, size_t size_nums)
{
    quick_sort(nums, size_nums);
    for (size_t i = 0; i < size_nums - 1; ++i)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
    // Time complexity: O(nlogn)
    // Space complexity: O(1)
}

int main(int argc, char *argv[])
{
    int test1[] = {1,2,3,1};
    int test2[] = {1,2,3,4};
    int test3[] = {1,1,1,3,3,4,3,2,4,2};

    printf("Test 1 (with bad time complex algorithm): %s\n", contains_duplicate_bad(test1, ARRAY_SIZE(test1)) ? "true" : "false");
    printf("Test 2 (with bad time complex algorithm): %s\n", contains_duplicate_bad(test2, ARRAY_SIZE(test2)) ? "true" : "false");
    printf("Test 3 (with bad time complex algorithm): %s\n", contains_duplicate_bad(test3, ARRAY_SIZE(test3)) ? "true" : "false");

    printf("Test 1 (with good time complex algorithm): %s\n", contains_duplicate_good(test1, ARRAY_SIZE(test1)) ? "true" : "false");
    printf("Test 2 (with good time complex algorithm): %s\n", contains_duplicate_good(test2, ARRAY_SIZE(test2)) ? "true" : "false");
    printf("Test 3 (with good time complex algorithm): %s\n", contains_duplicate_good(test3, ARRAY_SIZE(test3)) ? "true" : "false");

    return 0;
}

// The best general solution would be to use a hash map, however this would result
// in a lot of C code. 
