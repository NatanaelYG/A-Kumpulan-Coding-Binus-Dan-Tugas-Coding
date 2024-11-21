#include <stdio.h>

int main(){
    int i,j,k;
    int n;
    int jojo,lili,bibi;
    int nilai, total=0;
    int hasil;

    scanf("%d",&n);
    
    scanf("%d %d %d",&jojo,&lili,&bibi);
    for (i=0;i<n;i++)
    {
        scanf("%d",&nilai);
        total += nilai;
    }
    hasil = (jojo+lili+bibi+total)/(n+3);
        if (jojo >= hasil){
			printf("Jojo lolos\n");
		} else if (jojo < hasil){
			printf("Jojo tidak lolos\n");
		} if (lili >= hasil){
			printf("Lili lolos\n");
		} else if(lili < hasil){
			printf("Lili tidak lolos\n");
		} if(bibi >= hasil){
			printf("Bibi lolos\n");
		} else if(bibi < hasil){
			printf("Bibi tidak lolos\n");
		};
        
}
