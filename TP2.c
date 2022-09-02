#include <stdio.h>
#include <stdlib.h>

float sum(float matrix[3][3], int rows, int cols);

float sumPositives(float matrix[3][3], int rows, int cols);

float sumUntilFirstNegative(float matrix[3][3], int rows, int cols);

char* backwards(char s[]);

void rectangle(int a, int b);

void triangle(int a);

//------========------//

int strLen(const char* str){
    /*
     * Calculates the length of a string
     */
    int len = 0;
    for (;str[len];len++); // simply loops doing nothing until the end of the string
    return len;
}

int main(){
    //4x5 matrix
    float matrix[4][5] = {
            {1.0, 2.0, 3.0, 4.0, 5.0},
            {-6.0, 7.0, 8.0, -9.0, 10.0},
            {11.0, -12.0, 13.0, 14.0, 15.0},
            {16.0, 17.0, 18.0, 19.0, 20.0}
    };

    int rows = sizeof(matrix)/sizeof(matrix[0]);
    int cols = sizeof(matrix[0])/sizeof(matrix[0][0]);
    printf("Sum: %f\n", sum(matrix, rows, cols));
    printf("Sum of positives: %f\n", sumPositives(matrix, rows, cols));
    printf("Sum until first negative number: %f\n", sumUntilFirstNegative(matrix, rows, cols));
    char s[] = "lorem ipsum";
    printf("String spelled backwards is: %s\n", backwards(s));
    rectangle(3, 4);
    triangle(5);
    return 0;
}

float sum(float matrix[3][3], int rows, int cols) {
    /*
     * Sum of all elements of a matrix
     * NB: param is typed as float[3][3] but any 2-dimensional matrix works
     */
    int i, j;
    float s = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            s += matrix[i][j];
        }
    }
    return s;
}

float sumPositives(float matrix[3][3], int rows, int cols) {
    /*
     * Sums only positive elements of a matrix
     * NB: param is typed as float[3][3] but any 2-dimensional matrix works
     */
    int i, j;
    float s = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] >= 0) {
                s += matrix[i][j];
            }
        }
    }
    return s;
}

float sumUntilFirstNegative(float matrix[3][3], int rows, int cols) {
    /*
     * Sums elements of a matrix until the first negative number
     * NB: param is typed as float[3][3] but any 2-dimensional matrix works
     */
    int i, j;
    float sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                return sum;
            }
            sum += matrix[i][j];
        }
    }
    return sum;
}

char* backwards(char s[]) {
    /*
     * Inverts letters of a string
     */
    int i, j;
    char c;
    for (i = 0, j = strLen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

void rectangle(int a, int b){
    /*
     * Draws a a x b rectangle using asterisks
     */
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void triangle(int a) {
    /*
     * Draws a triangle of sides a
     */
    int i, j;
    for (i = 0; i < a; i++) {
        system("clear");
        for (j = 0; j <= i; j++) {
            printf("*");
            system("sleep 1");
        }
        printf("\n");
    }
}
