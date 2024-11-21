// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
    
//     FILE *file = fopen("testdata.in","r");

//     int t,j,process,i,k,jumlah[70];
//     char kata[105];
//     char origin, change;
//     int ubah[70];

//     fscanf(file,"%d\n", &t);

//     for(i = 0;i < t;i++){
//         for(i = 0;i < 26;i++){
//         jumlah[i] = 0;
//         ubah[i] = 0;
//         }

//         fscanf(file,"%s\n", kata);
//         fscanf(file,"%d\n", &process);
    
//         int len = strlen(kata);

    
//         for(j = 0;j < process;j++){
//             fscanf(file,"%c %c\n", &origin, &change);
//             for(k = 0;k < len;k++){
//                 if(kata[k] == origin && ubah[origin - 65] == 0){
//                     kata[k] = change;
//                 }
//             }
//             ubah[origin - 'A'] = 1;
//         }
    
//         for(j = 0;j < len;j++){
//             jumlah[kata[j] - 'A']++;
//         }

//         for(j = 0;j < 26;j++){
//             if(jumlah[j] == 0) {
//                 continue;
//             }
//             else {
//                 printf("%c %d\n", j + 'A', jumlah[j]);
//             }
//         }
//     }
    
    
//     fclose(file);
// }

#include<stdio.h>
#include<string.h>

int main(){
	int tc,proses,length;
	char text[105];
	char awal;
	char akhir;
	
	FILE *fin = fopen("testdata.in","r");
	
	fscanf(fin,"%d\n",&tc);
	for(int i = 0 ; i<tc;i++){
		fscanf(fin,"%[^\n]\n",text);
		length = strlen(text);
		fscanf(fin,"%d\n",&proses);
		int ubah[26] = {0};
		int ada[26] = {0};
			for(int j = 0 ; j<proses;j++){
				fscanf(fin,"%c %c\n",&awal,&akhir);
				for(int k = 0 ; k<length;k++){
					if(text[k] == awal && ubah[awal - 'A'] == 0){
						text[k] = akhir;
					}
				}
				ubah[awal - 'A'] = 1;
			}
			
			for(int j = 0 ; j<length;j++){
				ada[text[j] - 'A']++;
			}
			
			for(int j = 0 ; j<26;j++){
				if(ada[j] == 0){
					continue;
				} else {
					printf("%c %d\n", j +'A', ada[j]);
				}
			}
	}
	
	fclose(fin);
	
	return 0;
}