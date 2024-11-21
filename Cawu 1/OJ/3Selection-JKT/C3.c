#include <stdio.h>

int main () 
{
    int n, m, o;

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf ("%d %d", &m, &o);
        if (m >= o){
            printf ("Case #%d: Go-Jo\n", i);
        } else {
            printf ("Case #%d: Bi-Pay\n", i);   
        }
    }
}