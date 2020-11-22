#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

int exponencial(int *arr, int x, int n);

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
    pos = exponencial(arr, x, n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("Valor de n: %d\n", n);
    printf("Valor de x: %d\n", x);
    imprimir_resultado(pos);
    imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);
    return 0;
}

int exponencial(int *arr, int x, int n)
{
    int i = 0;
    if (arr[i] == x)
        return i;

    while (i < n && arr[i] <= x)
    {
        i = i * 2;
    }
}