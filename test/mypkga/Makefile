a: a.c 
	gcc -std=gnu99 -Wall -O2 $< -o $@
1.out: 1.c
	gcc -c -fdump-tree-cfg=$@ $< 
2.out: 2.c 
	clang -S $<
i-full.out: i.c
	cc -S $< > i.s   
	as i.s -o i.o 
	ld -o $@ \
		--dynamic-linker /usr/lib64/ld-linux-x86-64.so.2 \
		/usr/lib/x86_64-linux-gnu/crt1.o \ 
		/usr/lib/x86_64-linux-gnu/crti.o \
		i.o \
		/usr/lib/x86_64-linux-gnu/crtn.o 
	strace -f ./$@
i.out: i.c 
	gcc $< -v -o $@ 
i.strace: i.out 	
	strace -f ./$<



.DEFUALT_GOAL: a
.PHONY: clean a 
clean:
	rm -f *.s *.o *out 