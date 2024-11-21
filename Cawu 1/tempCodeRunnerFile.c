#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open the file.\n");
        return 1;
    }

    int t, n;
    fscanf(file, "%d", &t);

    for (int testCase = 1; testCase <= t; testCase++) {
        fscanf(file, "%d", &n);

        int *values = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &values[i]);
        }

        // Sorting the values for easier grouping
        qsort(values, n, sizeof(int), compare);

        // Calculate the minimum difference between two groups
        int group1 = 0, group2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                group1 += values[i];
            } else {
                group2 += values[i];
            }
        }

        int difference = abs(group1 - group2);

        printf("Kasus #%d: %d\n", testCase, difference);

        free(values);
    }

    fclose(file);

    return 0;
}
