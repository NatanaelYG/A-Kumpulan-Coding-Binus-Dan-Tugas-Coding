//#include <stdio.h>
//
//void swap(int *x,int *y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//int part(int m[], int low, int high){
//	int pivot = m[high];
//	int i = low;
//	
//	for(int j=low;j < high;j++){
//		if(m[j] <= pivot){
//			swap(&m[i],&m[j]);
//			i++;
//		}
//	}
//	swap(&m[high],&m[i]);
//	return i;
//}
//
//void qs(int m[],int low,int high){
//	if(low<high){
//		int pi = part(m,low,high);
//		qs(m,low,pi-1);
//		qs(m,pi+1,high);
//	}
//}
//
//
//
//int main(){
//    int t,m[200005],s,n=25, count1, count2, count3 , count4, count5, count6;
//    int i,j,k,l;
//
//    scanf("%d", &t);
//    for(i = 1;i <= t;i++){
//        for(j = 1;j <= n; j++){
//            scanf("%d", &m[j]);
//        }
//    	qs(m,1,n);
////    	for(j = 1;j <= n; j++){
////            printf("%d ", m[j]);
////        }
////        printf("\n");
//    	
//    int satu,dua,tiga,empat,lima;
//    satu = m[1]/2;
//    m[1] = 0;
//    dua = m[2]-satu;
//    m[2] = m[3] = 0;
//    lima = m[25]/2;
//    m[25] = 0;
//    empat = m[24]-lima;
//    m[24] = m[23] = 0;
////    count1 = count2 = count3 = count4 = count5 = count6 = 0;
////    for(j = 1; j <= 25; j++){
////    	if(m[j] == satu + empat && count1 < 2){
////    		m[j] = 0;
////    		count1++;
////		} else if(m[j] == satu + lima && count2 < 2){
////    		m[j] = 0;
////    		count2++;
////		} else if(m[j] == dua + empat && count3 < 2){
////    		m[j] = 0;
////    		count3++;
////		} else if(m[j] == dua + lima && count4 < 2){
////    		m[j] = 0;
////    		count4++;
////		} else if(m[j] == dua*2 && count5 < 1){
////    		m[j] = 0;
////    		count5++;
////		} else if(m[j] == empat*2 && count6 < 1){
////    		m[j] = 0;
////    		count6++;
////		}
////	}
////	for(j = 1;j <= n; j++){
////            printf("%d ", m[j]);
////        }
////        printf("\n");
////    for(j = 1; j<= 25; j++){
////    	if(m[j] > 0){
////    		tiga = m[j] - satu;
////    		break;
////		}
////	}
//	tiga = m[(25/2)+1]/2;
//    printf("Case #%d: %d %d %d %d %d\n",i, satu, dua, tiga, empat, lima);
//    }
//}

#include <stdio.h>

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int part(int m[], int low, int high){
	int pivot = m[high];
	int i = low;
	
	for(int j=low;j < high;j++){
		if(m[j] <= pivot){
			swap(&m[i],&m[j]);
			i++;
		}
	}
	swap(&m[high],&m[i]);
	return i;
}

void qs(int m[],int low,int high){
	if(low<high){
		int pi = part(m,low,high);
		qs(m,low,pi-1);
		qs(m,pi+1,high);
	}
}



int main(){
    int t,m[200005],s,n=25, count1, count2, count3 , count4, count5, count6;
    int i,j,k,l;

    scanf("%d", &t);
    for(i = 1;i <= t;i++){
        for(j = 1;j <= n; j++){
            scanf("%d", &m[j]);
        }
    	qs(m,1,n);
//    	for(j = 1;j <= n; j++){
//            printf("%d ", m[j]);
//        }
//        printf("\n");
    	
    int satu,dua,tiga,empat,lima;
    satu = m[1]/2;
    m[1] = 0;
    dua = m[2]-satu;
    m[2] = m[3] = 0;
    lima = m[25]/2;
    m[25] = 0;
    empat = m[24]-lima;
    m[24] = m[23] = 0;
//    count1 = count2 = count3 = count4 = count5 = count6 = 0;
//    for(j = 1; j <= 25; j++){
//    	if(m[j] == satu + empat && count1 < 2){
//    		m[j] = 0;
//    		count1++;
//		} else if(m[j] == satu + lima && count2 < 2){
//    		m[j] = 0;
//    		count2++;
//		} else if(m[j] == dua + empat && count3 < 2){
//    		m[j] = 0;
//    		count3++;
//		} else if(m[j] == dua + lima && count4 < 2){
//    		m[j] = 0;
//    		count4++;
//		} else if(m[j] == dua*2 && count5 < 1){
//    		m[j] = 0;
//    		count5++;
//		} else if(m[j] == empat*2 && count6 < 1){
//    		m[j] = 0;
//    		count6++;
//		}
//	}
//	for(j = 1;j <= n; j++){
//            printf("%d ", m[j]);
//        }
//        printf("\n");
//    for(j = 1; j<= 25; j++){
//    	if(m[j] > 0){
//    		tiga = m[j] - satu;
//    		break;
//		}
//	}
	tiga = m[(25/2)+1]/2;
    printf("Case #%d: %d %d %d %d %d\n",i, satu, dua, tiga, empat, lima);
    }
}
