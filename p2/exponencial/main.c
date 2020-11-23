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
    i = 1;
    while (i < n && arr[i] <= x)
    {
        i = i * 2;
    }

    int anterior = i / 2;
    int siguiente = obtener_menor(i, n - 1);
    int centro = anterior + (siguiente - anterior) / 2;

    while ((anterior <= siguiente))
    {
        if (arr[centro] == x)
            return centro;
        else if (arr[centro] < x)
            anterior = centro + 1;
        else
            siguiente = centro - 1;
        centro = (siguiente + anterior) / 2;
    }

    return (arr[centro] != x) ? -1 : centro;
}
