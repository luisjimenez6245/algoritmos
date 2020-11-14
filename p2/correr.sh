array=(5 10 20 4 30)

mkdir "./$1/resultados"
for i in ${array[*]}
do
    echo $i
    ./$1/a.out $2 "$i" < prueba.txt  >> "./$1/resultados/resultados.txt"
done
