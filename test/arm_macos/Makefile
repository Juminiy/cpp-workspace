a.s: a.c
	clang -S $<
a.out: a.c
	clang -v $< -o $@

1.out: 1.c 1.h
	clang -Wall $< -o $@

2.out: 2.c 
	clang -Wall $< -o $@ 
	
nt.out: nt.c 
	clang -Wall $< -o $@ 

clean:
	rm -rf *.out 