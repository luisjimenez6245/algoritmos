#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

int fibonacci(int *arr, int x, int n);
int obtener_menor(int x, int y);

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
    pos = fibonacci(arr, x, n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("Valor de n: %d\n", n);
    printf("Valor de x: %d\n", x);
    imprimir_resultado(pos);
    imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);
    return 0;
}

int fibonacci(int *arr, int x, int n)
{
    int ultimo_fibo = 1;
    int penultimo_fibo = 0;
    int siguiente_fibo = penultimo_fibo + ultimo_fibo;

    while (siguiente_fibo < n)
    {
        penultimo_fibo = ultimo_fibo;
        ultimo_fibo = siguiente_fibo;
        siguiente_fibo = penultimo_fibo + ultimo_fibo;
    }

    int limite = 0;

    while (siguiente_fibo > 1)
    {
        int i = obtener_menor(limite + penultimo_fibo, n) - 1;

        if (arr[i] < x)
        {
            siguiente_fibo = ultimo_fibo;
            ultimo_fibo = penultimo_fibo;
            penultimo_fibo = siguiente_fibo - ultimo_fibo;
            limite = i + 1;
        }
        else
        {
            if (arr[i] > x)
            {
                siguiente_fibo = penultimo_fibo;
                ultimo_fibo = ultimo_fibo - penultimo_fibo;
                penultimo_fibo = siguiente_fibo - ultimo_fibo;
            }
            else
            {
                return i;
            }
        }
    }
    if (ultimo_fibo && arr[limite] == x)
        return limite;
    return -1;
}
