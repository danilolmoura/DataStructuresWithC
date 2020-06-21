#include <stdio.h>
#include <stdbool.h>

#define MAXELEMENTS 50

typedef int KEY;

typedef struct{
	KEY key;
} ELEMENT;

typedef struct{
	ELEMENT ARR[MAXELEMENTS];
	int totalElements;
} LIST;

void initList(LIST* l){
/***************************************************************************//**
 * Set total elements of a LIST as 0
 *
 * @param l pointer to the LIST
 ******************************************************************************/
	l->totalElements = 0;
}

int countElements(LIST* l){
/***************************************************************************//**
 * Count total elements of a LIST
 *
 * @param l pointer to the LIST
 *
 * @return total elemements of the list
 ******************************************************************************/
	return l->totalElements;
}

void printList(LIST* l){
/***************************************************************************//**
 * Print all elements of a list
 *
 * @param l pointer to the LIST
 ******************************************************************************/
	int i;
	printf("List: \" ");
	for (i=0; i < l->totalElements; i++){
		printf("%i ", l->ARR[i].key);
	}
	printf("\n");
}

int linearSearch(LIST* l, KEY key){
/***************************************************************************//**
 * Finds position of a number in a LIST
 *
 * @param LIST pointer to the LIST
 * @param KEY value that we want to find inside the LIST
 *
 * @return int position of the key in the list
 ******************************************************************************/
	int i = 0;

	while(i < l->totalElements){
		if(key == l->ARR[i].key) return i;
		else i++;
	}

	return i;
}

bool insertElement(LIST* l, ELEMENT el, int pos){
/***************************************************************************//**
 * Insert an element in a specific position of a List
 *
 * @param LIST* pointer to the LIST
 * @param Element that will be inserted in the List
 * @param pos position of the LIST where element will be inserted
 *
 * @return bool true if element was inserted and false if element wasn't inserted
 ******************************************************************************/
	int j;

	if((l->totalElements == MAXELEMENTS) || (pos < 0) || (pos > l->totalElements)){
		return false;
	}

	for (j=0; j < l->totalElements; j++){
		l->ARR[j] = l->ARR[j-1];
	}

	l->ARR[pos] = el;
	l->totalElements++;
	return true;
}

bool deleteElement(LIST* l, KEY key){
/***************************************************************************//**
 * Delete an element in a specific position of a List
 *
 * @param LIST* pointer to the LIST
 * @param Element that will be deleted in the List
 *
 * @return bool true if element was deleted and false if element wasn't deleted
 ******************************************************************************/
	int pos, j;

	pos = linearSearch(l, key);
	if(pos == -1){
		return false;	
	}

	for(j = pos; j < l->totalElements; j++){
		l->ARR[j] = l->ARR[j+1];
	}

	l->totalElements--;

	return true;
}

void resetList(LIST* l){
/***************************************************************************//**
 * Reset elements of a LIST
 *
 * @param l pointer to the LIST
 ******************************************************************************/
	l->totalElements = 0;
}


int main(void) {
	LIST l = (LIST) {};
	initList(&l);
	int totalElements = countElements(&l);
	printf("%i \n", totalElements);
}

