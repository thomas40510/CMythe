#include <stdio.h>

void exo3();
void exo4();
void estTriangle(float a, float b, float c);


float pivotGauss(float matrix[3][3]);

int main() {
    exo3();
    exo4();
    estTriangle(3, 4, 3);

    float matrix[3][3] = {
            {1.0, 22.0, 13.0},
            {19.0, 5.0, 6.0},
            {94.0, 85.0, 2.0}
    };

    pivotGauss(matrix);
    return 0;
}

float pivotGauss(float matrix[3][3]) {
    /*
     * Gauss-Jordan algorithm for 3x3 matrix
     */
    int i, j, k;
    float pivot;

    // gauss-jordan algorithm
    for (i = 0; i < 3; i++) {
        pivot = matrix[i][i];
        for (j = 0; j < 3; j++) {
            matrix[i][j] /= pivot;
        }
        for (k = 0; k < 3; k++) {
            if (k != i) {
                pivot = matrix[k][i];
                for (j = 0; j < 3; j++) {
                    matrix[k][j] -= pivot * matrix[i][j];
                }
            }
        }
    }
    //display matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void exo3() {
    /*
     * Exercice 3 (division à valeur entière)
     */
    int a,b,c;
    a = 10;
    b = 3;
    c = a / b;
    printf("Le résultat de la division de %d par %d est %d\n", a, b, c);
}

void exo4() {
    /*
     * Exercice 4 (division de flottants)
     */
    float a,b,c;
    a = 10;
    b = 3;
    c = a / b;
    printf("Le résultat de la division de %f par %f est %f\n", a, b, c);
}

void estTriangle(float a, float b, float c) {
    /*
     * Exercice 5 (vérifie si ABC peut être un triangle)
     */
    int triangle = (a > b + c) || (b > a + c) || (c > a + b);
    printf("ABC %s", !triangle ? "est un triangle" : "n'est pas un triangle");
}
