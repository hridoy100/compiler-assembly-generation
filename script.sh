bison -d -y 1505010.y
echo '1'
g++ -w -c -o y.o y.tab.c
echo '2'
flex 1505010.l
echo '3'
#g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
g++ -fpermissive -w -c -o l.o lex.yy.c
echo '4'
g++ -o a.out y.o l.o -lfl -ly
echo '5'
./a.out exp.c 1505010_log.txt 1505010_error.txt
