#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {ENQUEUE, DEQUEUE, INVALID, EXIT, PRINT} command;
typedef enum animalType {DOG, CAT, ANY, INVALIDPET} animalType;

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
		return;			// Report some error
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
	return pet;
}

Node_t *dequeueDog(Shelter_t *shelter){
	Node_t *pet = popQueue(shelter->dogs);
	return pet;
}

Node_t *dequeueAny(Shelter_t *shelter){
	Node_t *cat = peekQueue(shelter->cats);
	Node_t *dog = peekQueue(shelter->dogs);
	if(cat == NULL && dog == NULL)
 		return NULL;		
	else if(cat != NULL && dog != NULL)
		return cat->timestamp < dog->timestamp ? dequeueCat(shelter) : dequeueDog(shelter);
	else if(cat == NULL)
		return dequeueDog(shelter);
	else
		return dequeueCat(shelter);
}

command parseCmd(char *cmd){
	command parsedAns;
 	if(!strcmp(cmd, "exit"))
 		parsedAns = EXIT;
 	else if(!strcmp(cmd, "enqueue"))
 		parsedAns = ENQUEUE;
 	else if(!strcmp(cmd, "dequeue"))
 		parsedAns = DEQUEUE;
 	else if(!strcmp(cmd, "print"))
 		parsedAns = PRINT;
 	else
 		parsedAns = INVALID;

 	return parsedAns;
}

animalType parsePet(char *petbuffer){
	animalType parsedPet;
 	if(!strcmp(petbuffer, "cat"))
 		parsedPet = CAT;
 	else if(!strcmp(petbuffer, "dog"))
 		parsedPet = DOG;
  	else if(!strcmp(petbuffer, "any"))
 		parsedPet = ANY;
 	else
 		parsedPet = INVALIDPET;

 	return parsedPet;
}

int main(int argc, char *argv[]){
 	command cmd;
 	animalType pet;
 	char buffer[20];
 	char charbuff;
 	char animalbuff[20];
 	Shelter_t *myShelter = createShelter();
 	int timestamp = 0;
 	Node_t *adoptedPet;

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == ENQUEUE)
 			scanf(" %s %c", animalbuff, &charbuff);
 		else if(cmd == DEQUEUE)
 			scanf(" %s", animalbuff);
 		pet = parsePet(animalbuff);
 		switch(cmd){
 			case ENQUEUE:
 				if(pet == CAT || pet == DOG)
 					enqueue(myShelter, pet, timestamp++, charbuff);
 				else
 					printf("Shelter can only take cats or dogs!\n");
 			 	break;
 			case DEQUEUE:
 				switch(pet){
 					case CAT:
 						adoptedPet = dequeueCat(myShelter);
 						if(adoptedPet != NULL)
 							printf("You have adopted the cat %c (%d)!\n", adoptedPet->data, adoptedPet->timestamp);
 						else
 							printf("Sorry. There's no cats in the shelter at the moment.\n");
 						break;
 					case DOG:
 						adoptedPet = dequeueDog(myShelter);
 						if(adoptedPet != NULL)
 							printf("You have adopted the dog %c (%d)!\n", adoptedPet->data, adoptedPet->timestamp);
 						else
 							printf("Sorry. There's no dogs in the shelter at the moment.\n");
 					 	break;
 					case ANY:
 						adoptedPet = dequeueAny(myShelter);
 						if(adoptedPet != NULL)
 							printf("You have adopted the animal %c (%d)!\n", adoptedPet->data, adoptedPet->timestamp);
 						else
 							printf("Sorry. The shelter is empty at the moment.\n");
 					 	break;
 					default:
 					 	printf("The shelter only has cats and dogs for adoption!\n");
 				}
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	printf("Current animal shelter status: \n");
 			 	printf("DOGS: ");
 			 	printList(myShelter->dogs->list);
 			 	printf("CATS: ");
 			 	printList(myShelter->cats->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deleteShelter(myShelter);
	return 0;
}