#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

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

int main(){
	int nums[6] = {1, 4, 6, 7, 7, 8};
	int *returnSize = (int *)malloc(sizeof(int));
	int *ans = searchRange(nums, 6, 7, returnSize);

	printf("[");
	for(int i = 0; i < 6; i++){
		printf("%d, ", nums[i]);
	}
	printf("]\n");
	printf("[%d, %d]\n", ans[0], ans[1]);
	return 0;
}
