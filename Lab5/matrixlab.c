#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int newMatrix[SIZE][SIZE]){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            newMatrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int newMatrix[SIZE][SIZE]){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            newMatrix[i][j] = m1[i][j] * m2[i][j];
        }
    }
}

void transposeMatrix(int m1[SIZE][SIZE], int newMatrix[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            newMatrix[j][i] = m1[i][j];
        }
    }
}

void printMatrix(int m1[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };
    int newMatrix[SIZE][SIZE];
    //add matrix
    printf("Add Matricies\n");
    addMatrices(m1, m2, newMatrix);
    printMatrix(newMatrix);
    
    //multiply matrix
    printf("Multiply Matricies\n");
    multiplyMatrices(m1, m2, newMatrix);
    printMatrix(newMatrix);
    
    //transpose Matrix
    printf("Transpone Matrix\n");
    transposeMatrix(m1, newMatrix);
    printMatrix(newMatrix);
    return 0;
};
