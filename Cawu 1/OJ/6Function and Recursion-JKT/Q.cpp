#include <stdio.h>

int min;

void iwan(int x1, int y1, int x2, int y2, int count){
    if (x1 == x2 && y1 == y2 && count < min){
        min = count;
        return;
    } 
    else {
        count++;
        if(x1 + 1 <= 7 && y1 + 2 <= 7 && count < min) iwan(x1 + 1, y1 + 2, x2, y2, count); 
        if(x1 + 2 <= 7 && y1 + 1 <= 7 && count < min) iwan(x1 + 2, y1 + 1, x2, y2, count);
        if(x1 + 2 <= 7 && y1 - 1 >= 0 && count < min) iwan(x1 + 2, y1 - 1, x2, y2, count);
        if(x1 + 1 <= 7 && y1 - 2 >= 0 && count < min) iwan(x1 + 1, y1 - 2, x2, y2, count);
        if(x1 - 1 >= 0 && y1 - 2 >= 0 && count < min) iwan(x1 - 1, y1 - 2, x2, y2, count);
        if(x1 - 2 >= 0 && y1 - 1 >= 0 && count < min) iwan(x1 - 2, y1 - 1, x2, y2, count);
        if(x1 - 2 >= 0 && y1 + 1 <= 7 && count < min) iwan(x1 - 2, y1 + 1, x2, y2, count);
        if(x1 - 1 >= 0 && y1 + 2 <= 7 && count < min) iwan(x1 - 1, y1 + 2, x2, y2, count);
    }
}

int main(){
    int i,t;
    char move[105],black[105];
    int x1,y1,x2,y2;

    scanf("%d",&t);
    for (i = 1; i <= t; i++){
        scanf("%s %s", black,move);

        x1 = black[0] - 'A';
        y1 = black[1] - '1';
        x2 = move[0] - 'A';
        y2 = move[1] - '1';

        min = 6;
        iwan(x1,y1,x2,y2, 0);
        if (min < 6){
            printf("Case #%d: %d\n",i, min);
        } else {
            printf("Case #%d: 6\n",i);
        } 
    }
}