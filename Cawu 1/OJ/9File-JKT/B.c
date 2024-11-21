#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("testdata.in","r");

    int t,n,i,j,k,l,pan;
    char huruf[1005];
        pan = 0;

    fscanf(file,"%d\n", &t);
    for(i = 1;i <= t;i++){
        char input[1005] = "";
        fscanf(file,"%d\n", &n);    
        fscanf(file,"%[^\n]\n", input);
        pan = strlen(input);
        for(j = 0;j < pan;j++){
            if(input[j] == ' '){
                continue;
            }
            if(input[j] == '0'){
                input[j] = 'O';
            }
            if(input[j] == '1'){
                input[j] = 'I';
            }
            if(input[j] == '3'){
                input[j] = 'E';
            }
            if(input[j] == '4'){
                input[j] = 'A';
            }
            if(input[j] == '5'){
                input[j] = 'S';
            }
            if(input[j] == '6'){
                input[j] = 'G';
            }
            if(input[j] == '7'){
                input[j] = 'T';
            }
            if(input[j] == '8'){
                input[j] = 'B';
            }
        }

        for(j=0; j < pan; j++){
            if(input[j] == ' '){
                continue;
            } else {
                input[j] -= n;
            }
        }

        for(j=0; j < pan; j++){
            if(input[j] == ' '){
                continue;
            }else if(input[j] > 'Z'){
                input[j] = input[j] - 26;
            } else if(input[j] < 'A'){
                input[j] = input[j] + 26;
            }
        }
            printf("Case #%d: %s\n",i, input);
    }
    fclose(file);
}