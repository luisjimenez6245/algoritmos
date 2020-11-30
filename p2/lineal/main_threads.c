#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

#include "../utils/util.h"
#include "../utils/tiempo.h"
#define MAXTHREADS 8

typedef struct informacion
{
    int inicio;
    int fin;
} informacion;

int *arr;
int posicion = -1;
int x = 0;

int create_threads(int x, int n);
int calc_hilos(int n);

int main(int argc, const char **argv)
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int n = 0;
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
    create_threads(x, n);
    uswtime(&utime1, &stime1, &wtime1);
    imprimir_resultado(posicion);
    imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);
    return 0;
}

void *thread_process(void *datos)
{
    informacion *info = datos;
    int i = info->inicio;
    while (i < info->fin && posicion == -1)
    {
        if (arr[i] == x)
        {
            posicion = i;
        }
        i++;
    }
    pthread_exit(0);
}

int create_threads(int x, int n)
{
    int hilos = calc_hilos(n);
    int actual = n / hilos;
    pthread_t threads[hilos];
    informacion *infos[hilos];
    int status, i, *exit_code;
    for (i = 0; i < (hilos - 1); ++i)
    {
        infos[i] = malloc(sizeof(*infos[i]));
        infos[i]->inicio = (i * actual);
        infos[i]->fin = ((i + 1) * actual - 1);
    }

    infos[hilos - 1] = malloc(sizeof(*infos[hilos]));
    infos[hilos - 1]->inicio = (i * actual);
    infos[hilos - 1]->fin = n;
    for (i = 0; i < hilos; ++i)
    {

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
    return 0;
}

int calc_hilos(int n)
{
    if (n < MAXTHREADS)
        return 1;
    int module = (n % MAXTHREADS);
    if (module == 0)
        return MAXTHREADS;
    return module;
}
