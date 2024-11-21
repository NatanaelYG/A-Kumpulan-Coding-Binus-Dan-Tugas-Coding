//#include <stdio.h>
//
//int main(){
//	int t;
//	char input;
//	int i,j,k;
//	
//	scanf("%d", &t);
//	for(i = 1;i <= t;i++){
//		scanf("%[^\n]", &input);
//		printf("%d", input);	
//	} 
//}

#include <stdio.h>

int main() {
    char inputChar;
    
    printf("Masukkan sebuah karakter: ");
    scanf(" %[^\n]", &inputChar); // Perhatikan spasi sebelum %c untuk mengabaikan spasi, tab, dan karakter newline (jika ada)

    int asciiValue = (int)inputChar; // Mengonversi karakter ke nilai ASCII

    printf("Nilai ASCII dari karakter '%c' adalah %d\n", inputChar, asciiValue);

    return 0;
}
