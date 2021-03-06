# Remove Duplicates

Write a function that deletes duplicate nodes in an **unsorted** linked list.

*20:30*

**Brute force:** time: O(n<sup>2</sup>) space: O(1)
- For each element, traverse the linked list finding duplicates and delete them. 

**Idea 1:** time: O(n) space: O(n)
- Run the linked list, adding each element to a hash table.
    - Whenever a value is inserted and collides with a previous one, it means a duplicate was found. 
    -Delete the node that was tried to be inserted.

````c
void removeDups(Node *head){
    if(head == NULL)
        return;
    while(head != NULL){
        if(hashGet(head->key) == NULL){
            hashAdd(head->key, head->value);
            head = head->next;
        } 
        else{
            head = deleteNode(head);
        }
    }
}
````
*20:41*

## Follow up

What if no additional buffers are allowed?

**Idea 2:**
- Use brute force algorithm described above. (I did not implement it)
