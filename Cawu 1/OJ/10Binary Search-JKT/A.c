#include <stdio.h>

// void swap(int *x, int *y){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int part(int a[],int l, int h){
//     int pivot = a[h];
//     int i = l;

//     for(int j = l;j < h;j++){
//         if(a[j] <= pivot){
//             swap(&a[i],&a[j]);
//             i++;
//         }
//     }
//     swap(&a[h],&a[i]);
//     return i;
// }

// void qs(int a[],int l,int h){
//     if(l<h){
//         int pi = part(a,l,h);
//         qs(a,l,pi-1);
//         qs(a,pi+1,h);
//     }
// }

int save;

int bin(int a[],int q,int l, int r){
    // int mid = (l+r)/2;

    // if(l > r || a[mid] != q){
    //     return -1;
    // }


    // if(a[mid] > q){
    //     return bin(a,q,l,mid-1);
    // } 

    // if(a[mid] < q){
    //     return bin(a,q,mid+1,r);
    // }


    // if (l <= r){
    //     int mid = l + (r - l) / 2;

    //     if(a[mid] == e){
    //         return mid;
    //     } else if (a[mid] > e){
    //         return bin(a, e, l, mid -1);
    //     } else {
    //         return bin(a,e,mid+1,r);
    //     }
    // }
    // return -1;
    // int l = 0;
    // int h = m-1;
    // int mid = (l+h)/2;

    // while(l <= h){
    //     if(a[mid]<q)

    // }
    if(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] == q){
            save = mid+1;
            return bin(a,q,0,mid-1);
        }
        else if (a[mid] < q) return bin(a,q,mid+1,r);
        else if (a[mid] > q) return bin(a,q,0,mid-1);
    }
    else return save;
} 

int main(){
    int n,m,a[100005],q;
    int i,j;

    scanf("%d %d", &n, &m);
    for(i = 0;i < n;i++){
        scanf("%d", &a[i]);
    } 
    for(j = 0;j < m;j++){
        scanf("%d", &q);
        save = -1;
        save = bin(a,q,0,n-1);
        printf("%d\n", save); 
    }

    return 0;
}