#include <stdio.h>

int main(){
    int a,b;

    FILE *file = fopen ("testdata.in","r");

    fscanf(file,"%d %d", &a, &b);

    printf("%d\n", a+b);

    fclose(file);
}