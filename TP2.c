#include <stdio.h>
#include <stdlib.h>

float sum(float matrix[3][3], int rows, int cols);

float sumPositives(float matrix[3][3], int rows, int cols);

float sumUntilFirstNegative(float matrix[3][3], int rows, int cols);

char* backwards(char s[]);

void rectangle(int a, int b);

void triangle(int a);

void partieDeux();
void partieTrois();
void partieQuatre();


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
    //partieDeux();
    //partieTrois();
    partieQuatre();
    return 0;
}

void  partieDeux(){
    /*
     * Partie II -- Tableau et boucles
     */
    float matrix[4][5] = {
            {1.0f, 2.0f, 3.0f, 4.0f, 5.0f},
            {-6.0f, 7.0f, 8.0f, -9.0f, 10.0f},
            {11.0f, -12.0f, 13.0f, 14.0f, 15.0f},
            {16.0f, 17.0f, 18.0f, 19.0f, 20.0f}
    };

    int rows = sizeof(matrix)/sizeof(matrix[0]);
    int cols = sizeof(matrix[0])/sizeof(matrix[0][0]);
    printf("Sum: %f\n", sum(matrix, rows, cols));
    printf("Sum of positives: %f\n", sumPositives(matrix, rows, cols));
    printf("Sum until first negative number: %f\n", sumUntilFirstNegative(matrix, rows, cols));
    char s[] = "lorem ipsum";
    printf("String spelled backwards is: %s\n", backwards(s));
}

void partieTrois(){
    /*
     * Partie III -- Appels système et affichage
     */
    rectangle(3, 4);
    triangle(5);
}

void partieQuatre() {
    /*
     * Partie IV -- Pointeurs
     */
    int a = 9;
    int * pa = &a;
    printf("a = %d\n", *pa);
    *pa = 5;
    printf("a = %d\n", *pa);

    char s[] = {'u', 'n', ' ', 'p', 'o', 'i', 'n', 't','e', 'u', 'r', '\0'};
    char * ps = s;
    printf("Adresse de s : %p\n", ps);

    // Calculate length of string via pointers
    while (*ps++); // moves pointer until the end of the string
    int len = ps - s - 1;
    printf("Longueur de s : %d\n", len);

    ps = s + 8;
    *ps = '\0';
    printf("s = %s\n", s);

    // set pointer on 9th element of s

    //TODO: make it work!
    char * pN = s + 9;
    char * res = (char *) malloc((strLen(ps) + strLen(pN) + 1) * sizeof(char));
    char * pRes = res;
    //concatenate s and pN
    while (*ps != '\0'){
        *pRes++ = *ps++;
    }
    while (*pN != '\0'){
        *pRes++ = *pN++;
    }
    *pRes = '\0';
    printf("s = %s\n", pRes);


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
     * Draws an a x b rectangle using asterisks
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
