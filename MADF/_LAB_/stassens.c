#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 32 // can be changed

void add(int a[N][N], int b[N][N], int c[N][N], int n, int sn)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = sn ? a[i][j] - b[i][j] : a[i][j] + b[i][j];
}

void copy(int a[N][N], int b[N][N], int r1, int r2, int c1, int c2)
{
    int n = r2 - r1;
    for (int i = r1, k = 0; i < r2 && k < n; i++, k++)
        for (int j = c1, l = 0; j < c2 && l < n; j++, l++)
            b[k][l] = a[i][j];
}

void combine(int C11[N][N], int C12[N][N], int C21[N][N], int C22[N][N], int C[N][N], int n)
{
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            C[i][j] = C11[i][j];

    for (int i = 0; i < n / 2; i++)
        for (int j = 0, k = n / 2; j < n / 2 && k < n; j++, k++)
            C[i][k] = C12[i][j];

    for (int i = 0, k = n / 2; i < n / 2 && k < n; i++, k++)
        for (int j = 0; j < n / 2; j++)
            C[k][j] = C21[i][j];

    for (int i = 0, k = n / 2; i < n / 2 && k < n; i++, k++)
        for (int j = 0, l = n / 2; j < n / 2 && l < n; j++, l++)
            C[k][l] = C22[i][j];
}

void strassen(int a[N][N], int b[N][N], int c[N][N], int n)
{
    if (n == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
    }
    else
    {
        int mid = n / 2;
        int P[N][N], Q[N][N], R[N][N], S[N][N], T[N][N], U[N][N], V[N][N];
        int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
        int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
        int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
        int buf1[N][N], buf2[N][N];

        copy(a, A11, 0, mid, 0, mid);
        copy(a, A12, 0, mid, mid, n);
        copy(a, A21, mid, n, 0, mid);
        copy(a, A22, mid, n, mid, n);

        copy(b, B11, 0, mid, 0, mid);
        copy(b, B12, 0, mid, mid, n);
        copy(b, B21, mid, n, 0, mid);
        copy(b, B22, mid, n, mid, n);

        add(A11, A22, buf1, mid, 0), add(B11, B22, buf2, mid, 0), strassen(buf1, buf2, P, mid);
        add(A21, A22, buf1, mid, 0), strassen(buf1, B11, Q, mid);
        add(B12, B22, buf2, mid, 1), strassen(A11, buf2, R, mid);
        add(B21, B11, buf2, mid, 1), strassen(A22, buf2, S, mid);
        add(A11, A12, buf1, mid, 0), strassen(buf1, B22, T, mid);
        add(A21, A11, buf1, mid, 1), add(B11, B12, buf2, mid, 0), strassen(buf1, buf2, U, mid);
        add(A12, A22, buf1, mid, 1), add(B21, B22, buf2, mid, 0), strassen(buf1, buf2, V, mid);

        add(P, S, buf1, mid, 0), add(V, T, buf2, mid, 1), add(buf1, buf2, C11, mid, 0);
        add(R, T, C12, mid, 0);
        add(Q, S, C21, mid, 0);
        add(P, R, buf1, mid, 0), add(U, Q, buf2, mid, 1), add(buf1, buf2, C22, mid, 0);

        combine(C11, C12, C21, C22, c, n);
    }
}

int main()
{
    int size = 8;
    int arr[N][N] = {{3, -7, 1, -9, 3, -7, 1, -9}, {6, -4, 8, -3, 6, -4, 8, -3}, {-2, 1, -3, 8, -2, 1, -3, 8}, {5, 9, -6, 5, 5, 9, -6, 5}, {3, -7, 1, -9, 3, -7, 1, -9}, {6, -4, 8, -3, 6, -4, 8, -3}, {-2, 1, -3, 8, -2, 1, -3, 8}, {5, 9, -6, 5, 5, 9, -6, 5}};
    int brr[N][N] = {{-6, 4, -6, 9, -6, 4, -6, 9}, {8, -2, 7, 3, 8, -2, 7, 3}, {-9, 4, 5, -2, -9, 4, 5, -2}, {5, -3, 8, -7, 5, -3, 8, -7}, {-6, 4, -6, 9, -6, 4, -6, 9}, {8, -2, 7, 3, 8, -2, 7, 3}, {-9, 4, 5, -2, -9, 4, 5, -2}, {5, -3, 8, -7, 5, -3, 8, -7}};
    int crr[N][N];

    strassen(arr, brr, crr, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%4d ", crr[i][j]);
        printf("\n");
    }

    return 0;
}
