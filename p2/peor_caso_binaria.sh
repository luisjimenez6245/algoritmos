n_array=(10000000) 	# tamaño más grande del problema
x_array=(61396)		# este número no se encuentra 
mkdir "./$1/resultados"
echo ""  > "./$1/resultados/peor_caso.txt"
for n in ${n_array[*]}
do
    echo "VALOR DE N : $n"  >> "./$1/resultados/peor_caso.txt"
    for x in ${x_array[*]}
    do
	echo "$x : " >> "./$1/resultados/peor_caso.txt"
        echo "n:$n x:$x"
        ./$1/a.out "$n" "$x" < 10millones_ordenados.txt  >> "./$1/resultados/peor_caso.txt"
    done
done
