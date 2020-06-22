#include <stdio.h>
#include <stdbool.h>

#define MAXELEMENTS 50

typedef int VALUE;

typedef struct{
	VALUE value;
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
	printf("List: \"");
	for (i=0; i < l->totalElements; i++){
		printf("%i ", l->ARR[i].value);
	}
	printf("\"\n");
}

int linearSearch(LIST* l, VALUE value){
/***************************************************************************//**
 * Finds position of a value in a LIST
 *
 * @param LIST pointer to the LIST
 * @param VALUE value that we want to find inside the LIST
 *
 * @return int position of the value in the list
 ******************************************************************************/
	int i = 0;

	while(i < l->totalElements){
		if(value == l->ARR[i].value) return i;
		else i++;
	}

	return i;
}

int binarySearch(LIST* l, VALUE value){
/***************************************************************************//**
 * Finds position of a value in an orderred list
 *
 * @param LIST pointer to the LIST
 * @param VALUE value that we want to find inside the LIST
 *
 * @return int position of the value in the list
 ******************************************************************************/
	int left, right, mid;
	left = 0;
	right = l->totalElements-1;

	while(left <= right){
		mid = ((left + right) / 2);

		if(l->ARR[mid].value == value){
			return mid;
		} else{
			if(l->ARR[mid].value < value){
				left = mid + 1;
			} else{
				right = mid - 1;
			}
		}
	}
	return -1;
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

bool insertOrderedElement(LIST* l, ELEMENT el){
/***************************************************************************//**
 * Insert an element in the list and keep its ordering
 *
 * @param LIST* pointer to the LIST
 * @param Element that will be inserted in the List
 *
 * @return bool true if element was inserted and false if element wasn't inserted
 ******************************************************************************/
	if(l->totalElements >= MAXELEMENTS) return false;

	int pos = l->totalElements;

	while(pos > 0 && l->ARR[pos-1].value > el.value){
		l->ARR[pos] = l->ARR[pos-1];
		pos--;
	}

	l->ARR[pos] = el;
	l->totalElements++;
	return true;
}

bool deleteElement(LIST* l, VALUE value){
/***************************************************************************//**
 * Delete an element in a specific position of a List
 *
 * @param LIST* pointer to the LIST
 * @param VALUE value that will be deleted in the List
 *
 * @return bool true if element was deleted and false if element wasn't deleted
 ******************************************************************************/
	int pos, j;

	pos = binarySearch(l, value);
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
	VALUE value1 = 333;
	VALUE value2 = 642;
	VALUE value3 = 33;
	VALUE value4 = 5;
	VALUE value5 = 55;

	ELEMENT e1 = (ELEMENT) {value1};
	ELEMENT e2 = (ELEMENT) {value2};
	ELEMENT e3 = (ELEMENT) {value3};
	ELEMENT e4 = (ELEMENT) {value4};
	ELEMENT e5 = (ELEMENT) {value5};

	initList(&l);
	insertOrderedElement(&l, e5);
	insertOrderedElement(&l, e4);
	insertOrderedElement(&l, e3);
	insertOrderedElement(&l, e2);
	insertOrderedElement(&l, e1);

	int totalElements = countElements(&l);
	printf("Total elements: %i \n", totalElements);

	int pos1 = binarySearch(&l, value1);
	int pos2 = binarySearch(&l, value2);
	int pos3 = binarySearch(&l, value3);
	int pos4 = binarySearch(&l, value4);
	int pos5 = binarySearch(&l, value5);

	printList(&l);
	printf("Position of %i in list is %i \n", value1, pos1);
	printf("Position of %i in list is %i \n", value2, pos2);
	printf("Position of %i in list is %i \n", value3, pos3);
	printf("Position of %i in list is %i \n", value4, pos4);
	printf("Position of %i in list is %i \n", value5, pos5);

}

