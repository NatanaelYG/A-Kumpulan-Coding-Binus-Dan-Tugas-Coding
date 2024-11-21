#include <stdio.h>

int main() {
    int n, m ,o;

    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d %d", &m, &o);
        if (m % 2 == 1 && o % 2 == 1){
            printf("Case #%d: Need more frogs\n",i);
        } else {
            printf("Case #%d: Party time!\n",i);
        }
    }
    return 0;
}