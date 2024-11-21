#include <stdio.h>

int asd(char input[1001][1001], int baris, int kolom, int n, int m) {
    if (baris < 1 || kolom < 1 || baris > n || kolom > m)
        return 0;
    
    if (input[baris][kolom] == 'S') {
        input[baris][kolom] = '#';
        return asd(input, baris - 1, kolom, n, m) + asd(input, baris + 1, kolom, n, m) + asd(input, baris, kolom - 1, n, m) + asd(input, baris, kolom + 1, n, m);
    }
    else if (input[baris][kolom] == '#')
        return 0;
    else {
        input[baris][kolom] = '#';
        return 1 + asd(input, baris - 1, kolom, n, m) + asd(input, baris + 1, kolom, n, m) + asd(input, baris, kolom - 1, n, m) + asd(input, baris, kolom + 1, n, m);
    }
}

int main() {
    int t, n, m, i, j, k;
    char input[1001][1001];
    int baris, kolom;

    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d", &n, &m);
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= m; k++) {
                scanf(" %c", &input[j][k]);
                if (input[j][k] == 'S') {
                    baris = j;
                    kolom = k;
                }
            }
        }
        printf("Case #%d: %d\n", i, asd(input, baris, kolom, n, m));
    }
    return 0;
}
