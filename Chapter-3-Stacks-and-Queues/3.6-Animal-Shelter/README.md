# Animal Shelter

An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in LinkedList data structure.

*10:50*

**Idea 1:**
- Two global linked lists catLL and dogLL which hold the animals.
- Each node (animal) has a field indicating a timestamp in which it was added (a sequential number)
- Enqueue creates a new node in the proper list
- Dequeue cat/dog removes and returns the TAIL of the corresponding list
- DequeueAny compares the timestamp of the next dog and cat to be adopted and returns the oldest one.
- I will implement a Queue abstraction for simplicity, using linked lists.

````c
typedef struct Shelter{
    Queue_t *dogs;
    Queue_t *cats;
}Shelter_t;

Shelter_t *createShelter(){
    Shelter_t *shelter = (Shelter_t *)malloc(sizeof(Shelter_t));
    shelter->cats = createQueue();
    shelter->dogs = createQueue();
    return shelter;
}

void deleteShelter(Shelter_t *shelter){
    deleteQueue(shelter->cats);
    deleteQueue(shelter->dogs);
    free(shelter);
}

void enqueue(Shelter_t *shelter, int animalType, int timestamp, char name){
    if(shelter == NULL)
        return;         // Report some error
    switch(animalType){
        case DOG:
            pushQueue(shelter->dogs, name, timestamp);
            break;
        case CAT:
            pushQueue(shelter->cats, name, timestamp);
            break;
    }
}

Node_t *dequeueCat(Shelter_t *shelter){
    Node_t *pet = popQueue(shelter->cats);
    if(pet == NULL)
        printf("Sorry. There's no cats in the shelter at the moment.\n");
    return pet;
}

Node_t *dequeueDog(Shelter_t *shelter){
    Node_t *pet = popQueue(shelter->dogs);
    if(pet == NULL)
        printf("Sorry. There's no dogs in the shelter at the moment.\n");
    return pet;
}

Node_t *dequeueAny(Shelter_t *shelter){
    Node_t *cat = peekQueue(shelter->cats);
    Node_t *dog = peekQueue(shelter->dogs);
    if(cat == NULL && dog == NULL){
        printf("Sorry. The shelter is empty at the moment.\n");
        return NULL;        
    }
    else if(cat != NULL && dog != NULL)
        return cat->timestamp < dog->timestamp ? dequeueCat(shelter) : dequeueDog(shelter);
    else if(cat == NULL)
        return dequeueDog(shelter);
    else
        return dequeueCat(shelter);
}
````

*11:30*
