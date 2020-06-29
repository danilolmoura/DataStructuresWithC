#include <stdio.h>
#include <stdbool.h>

#define LAST -1
#define INVALID -1
#define MAXELEMENTS 50

typedef int VALUE;

typedef struct 
{
	VALUE value;
} REGISTER;

typedef struct{
	REGISTER reg;
	int next;
} ELEMENT;

typedef struct{
	ELEMENT ARR[MAXELEMENTS];
	int first;
	int available;
} LIST;

void initList(LIST* l){
/***************************************************************************//**
 * Set total elements of a LIST as 0
 *
 * @param l pointer to the LIST
 ******************************************************************************/
	int i;

	for (i = 0; i < MAXELEMENTS -1; i++){
		l->ARR[i].next = i+1;
	}

	l->ARR[MAXELEMENTS-1].next = LAST;
	l->first = LAST;
	l->available = 0;
}

int countValidElements(LIST* l){
/***************************************************************************//**
 * Count total elements of a LIST
 *
 * @param l pointer to the LIST
 *
 * @return total elemements of the list
 ******************************************************************************/
	int i = l->first;
	int size = 0;

	while(i != LAST){
		size++;
		i = l->ARR[i].next;
	}

	return size;
}

void printList(LIST* l){
/***************************************************************************//**
 * Print all elements of a list
 *
 * @param l pointer to the LIST
 ******************************************************************************/
	int i = l->first;

	printf("List: \"");
	while(i != LAST){
		printf("%i ", l->ARR[i].reg.value);
		i = l->ARR[i].next;
	}
	printf("\"\n");
}

int linearSearch(LIST* l, VALUE value){
/***************************************************************************//**
 * Finds position of a value in a ordered list
 *
 * @param l pointer to the LIST
 * @param value that we want to find inside the LIST
 *
 * @return int position of the value in the list
 ******************************************************************************/
	int i = l->first;

	while(i != LAST && l->ARR[i].reg.value < value){
		i = l->ARR[i].next;
	}

	if(i != LAST && l->ARR[i].reg.value == value){
		return i;
	}

	return LAST;
}


int auxGetAvailableElement(LIST* l){
/***************************************************************************//**
 * Find and return the index of the next available ELEMENT

 *
 * @param l pointer to the LIST
 *
 * @return int index of the next available ELEMENT
 ******************************************************************************/
	int result = l->available;
	if(l->available != LAST){
		l->available = l->ARR[l->available].next;
	}

	return result;
}

bool insertElement(LIST* l, REGISTER reg){
/***************************************************************************//**
 * Insert yheFinds position of a value in a ordered list
 *
 * @param l pointer to the LIST
 * @param reg register that we want to insert in LIST
 *
 * @return bool true if element was inserted and false if element wasn't inserted
 ******************************************************************************/
	if(l->available == INVALID) return false;

	int previous = INVALID;
	int i = l->first;

	VALUE value = reg.value;

	while((i != INVALID) && (l->ARR[i].reg.value < value)){
		previous = i;
		i = l->ARR[i].next;
	}

	if(i != INVALID && l->ARR[i].reg.value == value) return false;

	i = auxGetAvailableElement(l);
	l->ARR[i].reg = reg;
	if (previous == INVALID){
		l->ARR[i].next = l->first;
		l->first = i;
	}
	else{
		l->ARR[i].next = l->ARR[previous].next;
		l->ARR[previous].next = i;
	}
	return true;
}

void auxResetElement(LIST* l, int j){
/***************************************************************************//**
 * Set an element of the list as available
 *
 * @param l pointer to the LIST
 * @param j index of the element we want to reset
 *
 ******************************************************************************/
	l->ARR[j].next = l->available;
	l->available = j;
}

bool deleteRegister(LIST* l, REGISTER reg){
/***************************************************************************//**
 * Delete an register from the LIS
 *
 * @param l pointer to an LIST
 * @param reg value that will be deleted in the List
 *
 * @return bool true if element was deleted and false if element wasn't deleted or if its not exists
 ******************************************************************************/
	int previous = INVALID;
	int i = l->first;

	VALUE value = reg.value;
	while((i != INVALID) && (l->ARR[i].reg.value < value)){
		previous = i;
		i = l->ARR[i].next;
	}

	if(i == INVALID || l->ARR[i].reg.value != value) return false;
	if(previous == INVALID) l->first = l->ARR[i].next;
	else l->ARR[previous].next = l->ARR[i].next;
	auxResetElement(l, i);
	return true;
}

void resetList(LIST* l){
/***************************************************************************//**
 * Set all elements of a list as available
 *
 * @param l pointer to a LIST
 *
 ******************************************************************************/
	initList(l);
}

int main(void) {
	LIST l = (LIST) {};

	initList(&l);
	countValidElements(&l);
	printList(&l);
}

