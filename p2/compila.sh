gcc ./arbol/main.c ./arbol/pila.c ./arbol/arbol_binario_ordenado.c  ./utils/util.c ./utils/tiempo.c -o ./arbol/a.out
gcc ./fibbo/main.c ./utils/util.c ./utils/tiempo.c -o ./fibbo/a.out
gcc ./lineal/main.c ./utils/util.c ./utils/tiempo.c -o ./lineal/a.out
gcc ./exponencial/main.c ./utils/util.c ./utils/tiempo.c -o ./exponencial/a.out
gcc ./binaria/main.c ./utils/util.c ./utils/tiempo.c -o ./binaria/a.out
gcc ./lineal/main_threads.c ./utils/util.c ./utils/tiempo.c -o ./lineal/e.out
gcc ./binaria/main_threads.c ./utils/util.c ./utils/tiempo.c -o ./binaria/e.out
gcc ./exponencial/main_threads.c ./utils/util.c ./utils/tiempo.c -o ./exponencial/e.out
gcc ./fibbo/main_threads.c ./utils/util.c ./utils/tiempo.c -o ./fibbo/e.out
gcc ./arbol/main_threads.c ./arbol/pila.c ./arbol/arbol_binario_ordenado.c  ./utils/util.c ./utils/tiempo.c -o ./arbol/e.out
