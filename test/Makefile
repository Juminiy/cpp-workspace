# gcc -c link files inorder, but new gcc make without thinking order
# make a static lib (suffix with .a) or shared lib (preffix with .b) 
# the static library is compiled to machine code and insert into executable file or called by other functions, purely static
# the dynamic library is a compiled .so in Linux or .dll in WindowsOS is a pointer to the called file, thus a shared lib 
# the .so shared lib is a table with the pointer information 
# the lib preload search method is: SYSTEM GLOBAL ENV VARIABLE; ld link -I -L parameter(relative/absolute path); the system lib(self machine)

# cpp is the c preprocessor extends macro only

# a simple example: 
# main.c -(gcc c preprocessor)> main.i(extended file) -(gcc compiler)> main.s(assemble file) -(assember)> main.o(target file) -(linked to together)> main.out(01 file) 
# compiler optimization: CSE & FL
# CSE: Common Subexpression Elimination, use the used expression to decline the calculation
# FL: Function Inline, directly put the machine code to the location, not to call a real functon to be in a stack.
# time ./a.out 
objs = main.o defs.o tmp_func.o 
libs = libDEFS.a
dirs = lib include
cstd = -ansi -pedantic
gstd = -std=gnu99
opts = -Wall $(gstd)

opopts = -O2 
dbopts = -g 

dpopts = -DENV_PROD
dtopts = -DENV_TEST
dparm1 = -DPARM1=200
dparm2 = -DPARM2=500


.DEFAULT_GOAL: main
main: main.o libDEFS.a 
	$(CC) $^ -o $@

main.o: main.c defs.h tmp_func.h
	$(CC) -c $(dpopts) $(dparm1) $(opts) $<
defs.o: defs.c defs.h
	$(CC) -c $(opts) $<
tmp_func.o: tmp_func.c tmp_func.h defs.h
	$(CC) -c $(opts) $< 

libDEFS.a: defs.o tmp_func.o
	ar cr $@ $^  

dir: 
	mkdir $(dirs) 

coredump:
	ulimit -c unlimited
	# gdb a.out core.*
	# >gdb print 
	# >gdb backtrace

nq:
	g++ -std=c++11 NQueens.cpp && ./a.out > nq.res

syscall_test:
	gcc $(gstd) syscall_test.c && ./a.out 


.PHONY: clean 
clean:
	rm -f *.o *.lib *.out 