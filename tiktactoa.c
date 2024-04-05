#include <stdio.h>
#include <stdlib.h>



//  functions Prototypes


void displayTable(char[]);

void markPlaces(char[], int *, char);

int checkWinner(char[]);



int main() {

	// table 
	
	char table[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 

	//  game logic
	

	int checkForWinner = 0;
	int markForX, markForO;

	int *ptrMarkForX, *ptrMarkForO;

	ptrMarkForX = &markForX;
	ptrMarkForO = &markForO;

	displayTable(table);

	while (!checkForWinner) {
		printf("Enter Position X (1-9): ");
		scanf("%d", &markForX);
		markPlaces(table, ptrMarkForX, 'x');
		displayTable(table);
		checkForWinner = checkWinner(table);

		if (checkForWinner == 1) 
			break;

		printf("Enter Position O (1-9): ");
		scanf("%d", &markForO);
		markPlaces(table, ptrMarkForO, 'o');
		system("clear");
		displayTable(table);
		checkForWinner = checkWinner(table);
	}	


	return 0;
}

//  functions body

void displayTable(char tableArr[9]) {
	printf(" %c | %c | %c \n", tableArr[6], tableArr[7], tableArr[8]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", tableArr[3], tableArr[4], tableArr[5]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", tableArr[0], tableArr[1], tableArr[2]);
}

void markPlaces(char tableArr[9], int *index, char mark) {
	if (tableArr[*index-1] == 'x' || tableArr[*index-1] == 'o') {
		printf("This cell already used!!!\n");
	} else {
		tableArr[*index-1] = mark;
	}
}

int checkWinner(char tableArr[9]) {

	if (
		(tableArr[0] == 'x' && tableArr[1] == 'x' && tableArr[2] == 'x')
		||
		(tableArr[3] == 'x' && tableArr[4] == 'x' && tableArr[5] == 'x')
		||
		(tableArr[6] == 'x' && tableArr[7] == 'x' && tableArr[8] == 'x')
		||
		(tableArr[0] == 'x' && tableArr[3] == 'x' && tableArr[6] == 'x')
		||
		(tableArr[1] == 'x' && tableArr[4] == 'x' && tableArr[7] == 'x')
		||
		(tableArr[2] == 'x' && tableArr[5] == 'x' && tableArr[8] == 'x')
		||
		(tableArr[0] == 'x' && tableArr[4] == 'x' && tableArr[8] == 'x')
		||
		(tableArr[2] == 'x' && tableArr[4] == 'x' && tableArr[6] == 'x')
	) {
		printf("Winner is: x\n");
		return 1;
	}
	else if  (
		(tableArr[0] == 'o' && tableArr[1] == 'o' && tableArr[2] == 'o')
		||
		(tableArr[3] == 'o' && tableArr[4] == 'o' && tableArr[5] == 'o')
		||
		(tableArr[6] == 'o' && tableArr[7] == 'o' && tableArr[8] == 'o')
		||
		(tableArr[0] == 'o' && tableArr[3] == 'o' && tableArr[6] == 'o')
		||
		(tableArr[1] == 'o' && tableArr[4] == 'o' && tableArr[7] == 'o')
		||
		(tableArr[2] == 'o' && tableArr[5] == 'o' && tableArr[8] == 'o')
		||
		(tableArr[0] == 'o' && tableArr[4] == 'o' && tableArr[8] == 'o')
		||
		(tableArr[2] == 'o' && tableArr[4] == 'o' && tableArr[6] == 'o')
	) {
		printf("Winner is: o\n");
		return 1;
	}
	else {return 0;}

}
