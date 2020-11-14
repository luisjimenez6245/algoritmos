# Practica 1

Cada una de las capertas tiene su respectivo algoritmo para ejecutarse.

Se requiere que el archivo de numeros10millones.txt esté ubicado en la raíz principal.

Para ejecutar los scripts correspondientes ejecutar los siguientes comandos:

    $ chmod +x compila.sh 


    $ chmod +x corre.sh




Para compilar todos los programas:

    $ ./compila.sh


Para correr los programas existen 2 opciones correr uno a la vez con una n dada o bien correr un ejemplo con los números solicitados:

Para correr un solo pograma con una n dada ejecuta el siguiente comando: (la n es opcional, si no se la ingresas te lo solicita el programa)

    $ ./correr.sh [carpeta_programa] [n]

Ejemplo:

    $ ./correr.sh burbuja_simple 1000


Para correr un algoritmo para todas las n dadas ejecuta el siguiente comando: (Los resultados los imprime en el archivo resultados.txt de la carpeta resultados que está adentro a  la carpteta de cada algorítmo)

    $ ./probar.sh [carpeta_programa]

Ejemplo:

    $ ./probar.sh burbuja_simple
