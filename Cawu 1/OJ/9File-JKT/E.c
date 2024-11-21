#include <stdio.h>
#include <stdlib.h>

int main(){
    int t,n,x[105];
    int i,j;
    FILE *file = fopen("testdata.in","r");

    fscanf(file,"%d\n",&t);
    // printf("%d\n", t);
    for(i = 0;i < t;i++){
        fscanf(file,"%d\n",&n);
    int area = 0, perimeter = 0;
        // printf("%d\n", n);
        for(j = 0;j < n;j++){
            fscanf(file,"%d\n", &x[j]);
            // printf("%d", x[j]);
            area += x[j];
            // printf("%d\n",area);
            // perimeter++;
        }

        perimeter = n * 2;
        for(j = 0;j < n-1;j++){
            perimeter += abs(x[j]-x[j+1]);
        }
        perimeter += x[0] + x[n-1];
        printf("Case #%d: %d %d\n",i+1 ,perimeter* 2, area*4);
    }
    fclose(file);
    return 0;
}