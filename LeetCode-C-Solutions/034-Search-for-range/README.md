# 34. Search for a range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
````
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
````


**My answer:** 

- Using bsearch from stdlib.h, which runs in O(log*n*)

````c
int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2);
    int a = 0;
    int b = 0;
    int *pivot = (int*) bsearch(&target, nums, numsSize, sizeof (int), cmpfunc);
    int i;

    if(pivot == NULL){
        res[0] = -1;
        res[1] = -1;
    }
    else{
        a = (pivot - nums);
        b = a;
        while((a - 1) >= 0){
            printf("nums[a - 1] = %d\n", nums[a-1]);
            if(nums[a - 1] != target)
                break;
            else
                a--;
        }
        while((b + 1) < numsSize){
            printf("nums[b + 1] = %d\n", nums[b + 1]);
            if(nums[b + 1] != target)
                break;
            else
                b++;
        }
        res[0] = a;
        res[1] = b;     
    }
    *(int *)returnSize = 2;
    return res;
}
````

However, my solution was not O(log*n*). I realized this after submitting. Worst case is still O(*n*)
