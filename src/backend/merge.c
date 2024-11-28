#include <stdio.h>

//mergeUp()

/*
 * Params:2D Array
 * Returns: New 2D Array
 */

#define ROWS 4
#define COLUMNS 4

int testGrid[ROWS][COLUMNS] = { {2,2,0,0}, {2,0,16,16}, {2,0,0,0}, {2,0,0,0} };


/*
 * Params: 2D Array
 * Return: Void
 */

void printArray(int matrix[ROWS][COLUMNS]){

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS ; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}


/*
 * Params: Pointer to Array of Ints
 * Return: Void
 */

void printRow(int *row){

    for(int i = 0; i < COLUMNS; i++){
        printf("%d", row[i]);
    }
    printf("\n");
}

/*
 * Params: 2D Array
 * Return: Single Row at specified index
 */

int *getRow(int matrix[ROWS][COLUMNS], int index){
    if (index < 0 || index >= ROWS){
        printf("Fix the index value");
        return NULL;
    } else {
        return matrix[index];
    }
}

/*
 * Params: 2D Array
 * Return: Void (changes Column value)
 */

void getColumn(int matrix[ROWS][COLUMNS], int index, int column[COLUMNS]){
    if (index < 0 || index >= COLUMNS){
        printf("Fix the index value");
    } else {
        for (int i = 0; i < COLUMNS; i++){
            //Get first index of all rows
            column[i] = matrix[i][index]; 
        }
    }
}

/*
 * Params: Pointer to Array of Ints
 * Return: Void
 */

void printColumn(int *column){

    for(int i = 0; i < ROWS; i++){
        printf("%d", column[i]);
    }
    printf("\n");
}

//Iterates from right to left, checking to see if its current value
//Is equal to the one behind it, if condition is met then add at the index infront
//And set its current index to 0

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Row)
 * Checks RIGHT to LEFT
 */

int *mergeRight(int *row){
    for (int i = (ROWS-1); i > 0; i--){
        if (row[i] == row[i-1]){
            row[i] += row[i-1];
            row[i-1] = 0;
        }
    }
    return row;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Row LEFT)
 * Checks LEFT to RIGHT 
 */

int *mergeLeft(int *row){
    for (int i = 0; i < ROWS; i++){
        if (row[i+1] == row[i]){
            row[i] += row[i+1];
            row[i+1] = 0;
        }
    }
    return row;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column)
 * Checks RIGHT to LEFT
 */

int *mergeUp(int *column){
    for (int i = (COLUMNS-1); i > 0; i--){
        if (column[i-1] == column[i]){
            column[i-1] += column[i];
            column[i] = 0;
        }
    }
    return column;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column Down)
 * Checks Right to Left
 */

int *mergeDown(int *column){
    for (int i = 0; i < COLUMNS; i++){
        if (column[i+1] == column[i]){
            column[i+1] += column[i];
            column[i] = 0;
        }
    }
    return column;
}

int main(){
    printArray(testGrid);
    int *row1 = getRow(testGrid, 0);
    int *row2 = getRow(testGrid, 1);
    int columnArr[COLUMNS];
    getColumn(testGrid, 0, columnArr);

    printf("\n");
    printColumn(columnArr);
    printf("\nMERGING DOWN\n");
    mergeDown(columnArr);
    //mergeUp(columnArr);
    printColumn(columnArr);

    printf("\n");
    mergeLeft(row1);
    printRow(row1);

    printf("\n");
    mergeRight(row2);
    printRow(row2);


    return 0;
}
