#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("testdata.in","r");

    int t,n;
    int i,j,k,l;
    char singkat[105][105],kata[105][105],input[105],save[105][105];
    int count, len;


    fscanf(file,"%d\n", &t); 
    // printf("%d\n", t);
    for(i = 0;i < t;i++){
        fscanf(file,"%[^#]#%[^\n]\n", singkat[i], kata[i]);
        // printf("%s %s\n", singkat[i],kata[i]);
    }   
    
    fscanf(file,"%d\n", &n); 
    // printf("%d\n", n);

    // for(j = 0;j < n;j++){
    //     fscanf(file,"%[^\n]\n", input);
    //     // printf("%s\n", input);
    //     int pan = strlen(input);
    //     count = 0;
    //     // printf("Case %d:\n", j);
    //     //MEMBUAT SUBSTRING
    //     for(i = 0;i < pan;i++){
    //         if(input[i] != ' ') strncat(save[count], &input[i], 1);
    //         if(input[i] == ' ' || i == pan-1){
    //             len = strlen(save[count]);
    //             save[count][len] = '\0';
    //             // printf("%s ", save[count]);
    //             count++;
    //         }
    //         // if(i == pan-1) printf("\n");
    //     }
    //     //SEARCHING Per Substring
    //     for(i = 0; i < count; i++){
    //         for(k = 0; k < t; k++){
    //             if(strcmp(save[i], singkat[k]) == 0){
    //                 printf("%s ", kata[k]);
    //                 break;
    //             } else if (strcmp(save[i], singkat[k]) != 0 && k == t-1){
    //                 printf("%s ", save[i]);
    //             }
    //         }
    //     }
    //     printf("\n");
    //     //RESET SAVE
    //     for(i = 0; i < count; i++){
    //         strcpy(save[i], "");
    //     }
    // }


    for(j = 1;j <= n;j++){
        count = 0;
        fscanf(file,"%[^\n]\n", input);
        printf("Case #%d:\n", j);
        // printf("%s\n", input);
        int pan = strlen(input);
        int start = 0, end = 0;
        char save[105];
        for(i = 0;i < pan;i++){
            strcpy(save,"");
            if(input[i] == ' ' || i == pan-1){
                if(input[i] == ' ') end = i - 1;
                else {
                    end = i;
                }
                    for(k = start; k <= end; k++){
                        save[count++] = input[k];
                    }
                    save[count] = '\0';
                for(k = 0; k < t; k++){
                    if(strcmp(save, singkat[k]) == 0){
                        printf("%s", kata[k]);
                        if (i == pan-1){
                            printf("\n");
                        } else {
                            printf(" ");
                        }
                        break;
                    } else if (strcmp(save, singkat[k]) != 0 && k == t-1){
                        printf("%s", save);
                        if (i == pan-1){
                            printf("\n");
                        } else {
                            printf(" ");
                        }
                    }
                }
                start = i+1;
                count = 0;
            } 
            
            // printf("%d %d", start, end);
            // printf("%s\n", save);
            
            // printf("%s", save);
        //         for(k = 0;k < t;k++){
        //         // printf("%s %s\n", save ,singkat[k]);
        //             if(strcmp(save,singkat[k]) == 0){
        //                 printf("%s", kata[k]);
        //             }
        //             break;
        //         }
        //         printf(" ");
        //         count = 0;
        //     } 
        }
        // printf("\n");
    // } 

    // for(j = 1;j <= n;j++){
    //     printf("Case #%d:\n", j);
    }

    fclose(file);
}