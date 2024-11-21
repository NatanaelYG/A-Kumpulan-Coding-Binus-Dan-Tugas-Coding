#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int menu, i, size, produk, manage, del;
    char merk[5];
	char mineral[50][5];
	int ukuran[50];
	int jumlah = 0;
	int flag;
	
    do{
        printf("%50s", "Juragan Air\n\n");
        printf("Mineral Water\n");
        printf("=============================\n");
        printf("%-5s %5s %15s\n","No."," Merk"," Size\n");
        for (i = 0; i < jumlah;i++){
        	printf("%3d %5s %15d\n",i+1, mineral[i], ukuran[i]);
		}

        printf("\n\nMenu :\n");
        printf("=============================\n");
        printf("1. Insert New\n");
        printf("2. Manage Products\n");
        printf("3. Insert New Carbonated\n");
        printf("4. Manage Carbonated Products\n");
        printf("5. Exit\n");
        printf("Choice : ");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
        printf("\n\nMineral Water\n");
        printf("=============================\n");
        do {
        printf("Merk [2] ? ");
        scanf("%s", merk);
        getchar();
    	} while(strlen(merk) != 2);
    	
    	do {
        printf("Size [240/600/1500] ml? ");
        scanf("%d", &size); 
		getchar();
    	} while (size != 240 && size != 600 && size != 1500);
    	
    	flag = 1;
    	for (i = 0; i < jumlah;i++){
    		if(strcmp(merk, mineral[i]) == 0 && size == ukuran[i]){
    			flag = 0;
    			break;
			}
		}
		
		if(flag == 0){
			printf("Sudah ada minuman %s size %d\n", merk, size);
		} else {
			strcpy(mineral[jumlah], merk);
    		ukuran[jumlah] = size;
    		jumlah++;
    		printf("Minuman %s %d ml berhasil ditambahkan!\n",merk, size);
		}
			getchar();
            break;
        case 2:
        printf("\n\nManage Menu\n");
        printf("==================\n");
        printf("1. Edit\n");
        printf("2. Delete\n");
        printf("Choice : ");
        scanf("%d", &manage);
        getchar();
        
        switch(manage){
        	case 1:
        		do {
        		printf("\nProduk mana yang anda mau edit [] ?");
        		scanf("%d", &produk);
        		getchar();
        		} while(produk < 1 || produk > jumlah);
        		
        		do {
		        printf("Merk [2] ? ");
		        scanf("%s", merk);
		        getchar();
		    	} while(strlen(merk) != 2);
		    	
		    	do {
		        printf("Size [240/600/1500] ml? ");
		        scanf("%d", &size); 
				getchar();
		    	} while (size != 240 && size != 600 && size != 1500);
		    	
		    	
		    	
		    	strcpy(mineral[produk-1], merk);
		    	ukuran[produk-1] = size;
		    	
		        break;
        	case 2:
        		do {
        		printf("\nProduk mana yang anda mau del [] ?");
        		scanf("%d", &del);
        		getchar();
        	}while(del < 1 || del > jumlah);
        		
        		
        		for(i = del-1; i < jumlah;i++){
        			strcpy(mineral[i], mineral[i+1]);
        			ukuran[i] = ukuran[i+1];
				}
				jumlah--;
        		getchar();
        		break;
		
		}
        // case 3:
        //     menuTiga();
        //     break;
        // case 4:
        //     menuEmpat();
        //     break;
        case 5:
            system("cls");
            break;
        }
    } while (menu != 5);

    return 0;
}
