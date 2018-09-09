for i in `seq 1 5` ; do
	echo $i > in.txt
	./a < in.txt
done
