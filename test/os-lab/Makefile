a.out: a.S
	gcc -S $< > a.s
	as a.s -o a.o
	ld a.o

a.trace: a.out 
	strace -f ./$<  

clean:
	rm -f a.o a.s a.out  