array=('arbol' 'binaria' 'fibbo' 'lineal' 'exponencial')

for i in ${array[*]}
do
    echo $i
    mkdir "./$i/resultados"
    ./$i/a.out $2 "$1" < prueba.txt  > "./$i/resultados/resultados.txt"
done
