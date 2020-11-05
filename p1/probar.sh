array=(500000)

mkdir "./$1/resultados"
for i in ${array[*]}
do
    echo $i
    ./$1/a.out "$i" > "./$1/resultados/res-$i.txt"
done