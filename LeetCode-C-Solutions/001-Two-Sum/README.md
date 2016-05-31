# 1. Two Sum 

Difficulty: Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

````
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
````

UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

**My Solution:**
- I implemented an iterative O(*n*<sup>2</sup>) and a HashTable O(*n*) solution.

Hash Table:

````c
int* twoSum(int* nums, int numsSize, int target) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    int i;
    int hash[25536];
    for(i = 0; i < 25536; i++)
        hash[i] = -1;

    for(i = 0; i < numsSize; i++){
        int otherNumber = target - nums[i];
        if(hash[otherNumber] != -1){
            ret[0] = hash[otherNumber];
            ret[1] = i;
            break;
        }
        else{
            hash[nums[i]] = i;
        }
    }
    return ret;
}
````

Iterative:
````c
int* twoSum2(int* nums, int numsSize, int target) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    int i, j;

    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                ret[0] = i;
                ret[1] = j;
            }
        }
    }
    return ret;
}
````