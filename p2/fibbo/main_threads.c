#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

#include "../utils/util.h"
#include "../utils/tiempo.h"

typedef struct informacion
{
    int inicio;
    int fin;
    int medio;
    int tope;
} informacion;

void fibonacci();
int obtener_menor(int x, int y);

int *arr;
int posicion = -1;
int x = 0;
int n;

int main(int argc, const char **argv)
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
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
    fibonacci(arr, x, n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("Valor de n: %d\n", n);
    printf("Valor de x: %d\n", x);
    imprimir_resultado(posicion);
    imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);
    return 0;
}

void *thread_process(void *datos)
{
    informacion *info = datos;

    int ultimo_fibo = info->inicio;
    int penultimo_fibo = info->medio;
    int siguiente_fibo = info->fin;

    int limite = 0;

    while (siguiente_fibo > info->tope && posicion == -1)
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
                posicion = i;
                pthread_exit(0);
            }
        }
    }
    if (ultimo_fibo && arr[limite] == x)
        posicion = limite;
    pthread_exit(0);
}

void fibonacci()
{
    int hilos = 2;

    int ultimo_fibo = 1;
    int penultimo_fibo = 0;
    int siguiente_fibo = penultimo_fibo + ultimo_fibo;

    while (siguiente_fibo < n)
    {
        penultimo_fibo = ultimo_fibo;
        ultimo_fibo = siguiente_fibo;
        siguiente_fibo = penultimo_fibo + ultimo_fibo;
    }

    pthread_t threads[hilos];
    informacion *infos[hilos];
    int status, i, *exit_code, aux;
    int actual = n / hilos;
    for (i = 0; i < hilos; ++i)
    {
        infos[i] = malloc(sizeof(*infos[i]));
        infos[i]->inicio = ultimo_fibo;
        infos[i]->medio = penultimo_fibo;
        infos[i]->fin = siguiente_fibo;

        siguiente_fibo = penultimo_fibo;
        ultimo_fibo = ultimo_fibo - penultimo_fibo;
        penultimo_fibo = siguiente_fibo - ultimo_fibo;

        infos[i]->tope = 1;

        status = pthread_create(&threads[i], NULL, thread_process, infos[i]);
        if (status)
        {
            printf("\nError en thread %i\n", status);
            exit(-1);
        }
    }
    for (i = 0; i < hilos; i++)
    {
        pthread_join(threads[i], (void **)&exit_code);
    }
}
