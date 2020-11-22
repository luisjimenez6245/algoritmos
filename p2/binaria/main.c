#include <stdio.h>
#include <math.h>  
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

int binaria(int *arr, int x, int n);

int main(int argc, const char **argv)
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int n = 0;
    int x = 0;
    int *arr;
    int pos = -1;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
        if (argc > 2)
        {
            x = atoi(argv[2]);
        }
        else
        {
            x = obtener_n();
        }
    }
    else
    {
        n = obtener_n();
        x = obtener_n();
    }
    arr = leer_archivo(arr, n);
    uswtime(&utime0, &stime0, &wtime0);
    pos = binaria(arr, x, n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("Valor de n: %d\n", n);
    printf("Valor de x: %d\n", x);
    imprimir_resultado(pos);
    imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);
    return 0;
}

int binaria(int *arr, int n, int key)
{
    int lg = log2(n - 1) + 1;
    int pos = 0;
    for (int i = lg; i >= 0; i--)
    {
        if (arr[pos] == key)
        {
            return pos;
        }
        int np = pos | (1 << i);
        if ((np < n) && (arr[np] <= key))
            pos = np;
    }
    return (arr[pos] == key) ? pos : -1;
}