#include <stdio.h>

int count;

void kuda(int x1, int y1, int x2, int y2, int move){
    if (x1 == x2 && y1 == y2){
        count++;
        return;
    } else if (move == 0){
        return;
    }

    if(x1 + 1 <= 7 && y1 + 2 <= 7 && count == 0){
        kuda(x1 + 1, y1 + 2, x2, y2, move-1);
    } 
    if(x1 + 2 <= 7 && y1 + 1 <= 7 && count == 0){
        kuda(x1 + 2, y1 + 1, x2, y2, move-1);
    } 
    if(x1 + 2 <= 7 && y1 - 1 >= 0 && count == 0){
        kuda(x1 + 2, y1 - 1, x2, y2, move-1);
    }
    if(x1 + 1 <= 7 && y1 - 2 >= 0 && count == 0){
        kuda(x1 + 1, y1 -2, x2, y2, move-1);
    }
    if(x1 - 1 >= 0 && y1 - 2 >= 0 && count == 0){
        kuda(x1 - 1, y1 - 2, x2, y2, move-1);
    }
    if(x1 - 2 >= 0 && y1 - 1 >= 0 && count == 0){
        kuda(x1 - 2, y1 - 1, x2, y2, move-1);
    }
    if(x1 - 2 >= 0 && y1 + 1 <= 7 && count == 0){
        kuda(x1 - 2, y1 + 1, x2, y2, move-1);
    }
    if(x1 - 1 >= 0 && y1 + 2 <= 7 && count == 0){
        kuda(x1 - 1, y1 + 2, x2, y2, move-1);
    }
}

int main(){
    int i;
    int move;
    int t,x1,y1,x2,y2;
    char white[257], black[257];

    scanf("%d",&t);
    for (i = 1; i <= t; i++){
        scanf("%d", &move);
        scanf("%s %s", white, black);

        x1 = white[0] - 'A';
        y1 = white[1] - '1';
        x2 = black[0] - 'A';
        y2 = black[1] - '1';

        count = 0;
        kuda(x1,y1,x2,y2,move*2);
        if (count == 1){
            printf("Case #%d: YES\n", i);
        } else {
            printf("Case #%d: NO\n", i);
        }
    }
    return 0;
}