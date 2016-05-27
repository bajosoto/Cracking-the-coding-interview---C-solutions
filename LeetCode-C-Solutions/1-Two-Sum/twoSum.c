// 0:49
#include "uthash.h"

struct number{
	int id;
	UT_hash_handle hh;
};

// void addNumber(int id) {
//     struct number *s;

//     s = malloc(sizeof(struct number));
//     s->id = id;
//     HASH_ADD_INT( users, id, s );  /* id: name of id field */
// }

//struct number *findNumber(int id) {
//    struct users *s;

//    HASH_FIND_INT( users, &id, s );  /* s: output pointer */
//    return s;
//}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct number *users = NULL;		// Hash Table

int* twoSum(int* nums, int numsSize, int target) {
    int *ret = (int *)malloc(sizeof(int) * 2);

    struct number *n;
    int i;

    for(i = 0; i < numsSize; i++){
    	HASH_FIND_INT( users, &id, n);
    	//n = findNumber(target - nums[i]);
    	if(n != NULL){
    		ret[0] = n->id;
    		ret[1] = i;
    	}
    	else{
    		struct number *s;

    		s = malloc(sizeof(struct number));
    		s->id = i;
   			HASH_ADD_INT(users, id, s);
    		//addNumber(i);
    	}
    }

    return ret;
}

// 1:00

int main(){
 	int numArray[] = {1, 4, 6, 7, 11, 14, 16};
 	int target = 25;
 	int *sum = twoSum(numArray, 7, target);
 	printf("[%d, %d]\n", numArray[0], numArray[1]);
	return 0;
}