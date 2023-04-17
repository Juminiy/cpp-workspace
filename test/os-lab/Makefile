a.out: a.S
	cc -S $< > a.s
	as a.s -o a.o
	ld a.o
	strace -f ./$@  

	

clean:
	rm -f a.o a.s a.out  