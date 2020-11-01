array=(4000000 5000000 6000000 7000000 8000000 9000000 10000000)

mkdir "./$1/resultados"
for i in ${array[*]}
do
    echo $i
    ./$1/a.out "$i" > "./$1/resultados/res-$i.txt"
done