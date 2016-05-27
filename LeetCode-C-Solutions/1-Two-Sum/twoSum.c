// 0:49


/**
 * Solution 1: Assuming no repeated numbers, all positive. Implements a Hash Table with no collision detection.
 */
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

// 1:00

/**
 * Solution 2: Less efficient implementation. Supports repeated numbers and negative numbers.
 */
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

int main(){
 	int numArray[] = {2, 4, 6, 7, 11, 14, 16};
 	int target = 13;
 	int *sum = twoSum(numArray, 7, target);
    int *sum2 = twoSum2(numArray, 7, target);
 	printf("[%d, %d]\n", sum[0], sum[1]);
    printf("[%d, %d]\n", sum2[0], sum2[1]);
	return 0;
}

