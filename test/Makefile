# default : -std=gnu99
cstd = -ansi -pedantic
gstd = -std=gnu99
xstd = -std=c++11
opts = -Wall -v 


.DEFAULT_GOALl: a
a: 
	gcc -v -c a.S
	ld a.o
# hanoi build 	
hanoi:
	gcc $(gstd) $(opts) -c hanoi.c 
	gcc hanoi.o -o hanoi.out

minimal:
	gcc -E -S $(gstd) $(opts) minimal.c

wps: 
	g++ $(xstd) $(opts) wps.cpp && ./a.out

fg:
	g++ $(xstd) $(opts) fg_function.cpp && ./a.out 

# echo_fg_log:
# 	echo g++ $(xstd) $(opts) fg_function.cpp && ./a.out > echo_fg_log.log

.PHONY: clean
clean:
	rm -f *.s 
	rm -f *.o
	rm -f *.out