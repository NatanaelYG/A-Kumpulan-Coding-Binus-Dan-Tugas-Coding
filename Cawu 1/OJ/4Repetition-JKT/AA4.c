#include <stdio.h>

int main()
{
    int n, m, o = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &m);
        o += m;
        if(o == 9)
        {
            o = 21;
        }
        else if(o == 33){
            o = 42;
        }
        else if(o == 76){
            o = 92;
        } 
        else if(o == 53){
            o = 37;
        } 
        else if(o == 80){
            o = 59;
        } 
        else if(o == 97){
            o = 88;
        }
    }
    printf("%d\n", o);
    return 0;
}