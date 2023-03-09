# gcc -c link files inorder, but new gcc make without thinking order
# make a static lib (suffix with .a) or shared lib (preffix with .b) 
# the static library is compiled to machine code and insert into executable file or called by other functions, purely static
# the dynamic library is a compiled .so in Linux or .dll in WindowsOS is a pointer to the called file, thus a shared lib 
# the .so shared lib is a table with the pointer information 
# the lib preload search method is: SYSTEM GLOBAL ENV VARIABLE; ld link -I -L parameter(relative/absolute path); the system lib(self machine)
objs = main.o defs.o tmp_func.o 
libs = libDEFS.a
dirs = lib include
cstd = -ansi -pedantic
gstd = -std=gnu99
opts = -Wall -v $(gstd)

.DEFAULT_GOAL: main
main: $(objs)
	$(CC) $(opts) main.o $(libs) -o main

main.o: defs.h tmp_func.h
defs.o: defs.h
tmp_func.o: tmp_func.h defs.h

libDEFS: defs.o tmp_func.o
	ar cr libDEFS.a defs.o tmp_func.o 

dir: 
	mkdir $(dirs) 

.PHONY: clean 
clean:
	rm $(objs) $(libs) main 