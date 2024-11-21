#include <stdio.h>

// Cek jika mid adalah limit, dapatkah angka angka di array bisa terbagi menjadi sesuai jumlah staff
int check(int P[], int City, int Staff, int mid)
{
    long long int count = 0;
    int i = 0;
    int staffCount = 1; // jumlah staff
    while (i < City)
    {
        if (P[i] > mid)
        {
            return 0;
        }
        if (count + P[i] > mid)
        {
            staffCount++;
            count = 0;
        }
        if (count <= mid)
        {
            count += P[i];
            i++;
        }
    }
    if (staffCount <= Staff) // Jika jumlah staff hasil perhitungan kurang dari sama dengan jumlah staff seharusnya
    {
        return 1;
    }
    return 0; // Jika jumlah staff hasil perhitungan lebih dari seharusnya
}

long long int limit(int P[], int City, int Staff, long long int Max) // Lakukan binary search sampai kita mendapat limit yang paling kecil
{
    long long int result = Max;
    long long int high = Max;
    long long int low = 1;
    long long int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        int flag = check(P, City, Staff, mid);
        if (flag)
        {
            if (result >= mid)
            {
                result = mid;
            }
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

void print(int arrayPosition, int P[], int Limit, int Staff)
{
    long long int count = 0;
    int printPosition = -1;
    // Program menghitung dari belakang
    for (int i = arrayPosition; i >= 0; i--)
    {
        if (count + P[i] > Limit || i == Staff - 2)
        {
            print(i, P, Limit, Staff - 1);
            printPosition = i;
            break;
        }
        count += P[i];
    }
    // Print Semicolon
    if (printPosition >= 0)
    {
        printf("; ");
    }
    // Print Angka
    for (int i = printPosition + 1; i <= arrayPosition; i++)
    {
        printf("%d ", P[i]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        // Input
        int C, S;
        scanf("%d %d", &C, &S);
        long long int max = 0;
        int P[S];
        for (int i = 0; i < C; i++)
        {
            scanf("%d", &P[i]);
            max += P[i];
        }
        // Find Limit
        long long int Limit = limit(P, C, S, max);
        print(C - 1, P, Limit, S);
        puts("");
    }
}