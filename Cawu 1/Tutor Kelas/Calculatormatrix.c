#include<stdio.h>
#include<stdlib.h>


void getCofactor(int q, int n, int matrix[][n], int temp[][n - 1]) {
    int i = 0;
    int j = 0;
    int p = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinante(int n, int matrix[][n]) {
    if (n == 1) {
        return matrix[0][0];
    }

    int temp[n - 1][n - 1];
    int sign = 1;
    int D = 0;

    for (int f = 0; f < n; f++) {
        getCofactor(f, n, matrix, temp);
        D += sign * matrix[0][f] * determinante(n - 1, temp);
        sign = -sign;
    }
    return D;
}

void addition(){
    int r, c;
    printf("Enter the number of rows : ");
    scanf("%d", &r);
    printf("Enter the number of columns : ");
    scanf("%d", &c);
    int a[100][100], b[100][100], sum[100][100];
    printf("\nEnter elements of 1st matrix:\n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
        scanf("%d", &a[i][j]);
        }

    printf("Enter elements of 2nd matrix:\n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
        scanf("%d", &b[i][j]);
        }

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
        sum[i][j] = a[i][j] + b[i][j];
        }
    printf("\nSum of two matrices: \n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
        printf("%d ", sum[i][j]);
        if (j == c - 1) {
            printf("\n");
        }
        }
}

void determinant(){
    int s;
    printf("Insert the size of the square matrix\n>> ");
    scanf("%d", &s);
    int matriks[s][s];
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
        scanf("%d", &matriks[i][j]);
        }
    }
    printf("Determinant of the square matrix : %d\n",determinante(s,matriks));
}

void multipication()
{
    int hA, wAhB, hB,wB;
    printf("Insert the size of the first and the second matrix\nA Row A Col B Row B Col\n>> ");
    scanf("%d %d %d %d", &hA, &wAhB , &hB, &wB);
    if(wAhB!=hB){
        printf("Multipication only alowed in m x n and n x p matrix!\n");
        return;
    }else{
        printf("insert the first matrix!\n");
    }
    int matriksa[100][100];
    int matriksb[100][100];
    for (int i = 0; i < hA; i++) {
        for (int j = 0; j < wAhB; j++) {
        scanf("%d", &matriksa[i][j]);
        }
    }
    printf("insert the second matrix!\n");
    for (int i = 0; i < wAhB; i++) {
        for (int j = 0; j < wB; j++) {
        scanf("%d", &matriksb[i][j]);
        }
    }

    printf("Result of the multipication:\n");

    for (int i = 0; i <hA ;i++) {
        for (int j = 0; j <wB; j++) {
            int index=0;
            for(int k=0;k<wAhB;k++) {
                index+=matriksa[i][k]*matriksb[k][j];
            }
            printf("%d", index);
            if(j<wB-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
}

int main(){
    int option;
    do{
        printf("\nMatrix Calculator\n================================================\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multipication\n");
        printf("3. Matrix Determinant\n");
        printf("4. Exit\n>> ");
        scanf("%d",&option);
        switch(option){
            case 1:
                addition();
                break;
            case 2:
                multipication();
                break;
            case 3:
                determinant();
                break;
            case 4:
                printf("program finished!");
                return 0;
        }
    }while(option!=4);
}

