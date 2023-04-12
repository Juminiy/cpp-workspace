compile_gcc= gcc 
compile_gxx= g++
compile_clang= clang
compile_clangxx= clang++

c_args= -std=gnu99 -Wall -O2 
cxx_args= -std=c++11 -Wall -O2 
c_ast_dump= -fdump-tree-all -g

compile_test_args= -DCOMPILE_TEST
run_test_args= -DRUN_TEST
run_debug_args= -DRUNTIME_DEBUG

ccl= $(compile_gcc)
ccl_args= $(c_args)
ccl_debug= -g
ccl_verbose_arg = -v

llvm_ir= -emit-llvm 
llvm_cl= -ccc-print-phases



# main all 
main: main.o lib0.a 
	$(ccl) $(ccl_args) -o $@ $^
0.o: 0.c 0.h
	$(ccl) -c $(ccl_args) -o $@ $< 
1.o: 1.c 1.h
	$(ccl) -c $(ccl_args) -o $@ $<
2.o: 2.c 2.h
	$(ccl) -c $(ccl_args) -o $@ $<
3.o: 3.c 3.h
	$(ccl) -c $(ccl_args) -o $@ $<
main.o: main.c 0.h 1.h 2.h 3.h 
	$(ccl) -c $(ccl_args) -o $@ $< 

lib0.a: 0.o 1.o 2.o 3.o
	ar cr $@ $^     



# test all 
test: test.o 0_test.o 0.o 1_test.o 1.o 2_test.o 2.o 3_test.o 3.o  
	$(ccl) $(ccl_args) -o $@ $^
0_test.o: 0_test.c 0.h
	$(ccl) -c $(ccl_args) $(compile_test_args) -o $@ $< 
1_test.o: 1_test.c 1.h
	$(ccl) -c $(ccl_args) $(compile_test_args) -o $@ $<
2_test.o: 2_test.c 2.h
	$(ccl) -c $(ccl_args) $(compile_test_args) -o $@ $<
3_test.o: 3_test.c 3.h
	$(ccl) -c $(ccl_args) $(compile_test_args) -o $@ $<
test.o: test.c 0.h 1.h 2.h 3.h 
	$(ccl) -c $(ccl_args) $(compile_test_args) $(run_test_args) -o $@ $< 



# cxx compile 
maincpp: maincpp.o lib0hpp.so 
	cd cpp && $(compile_clangxx) $(cxx_args) -L./ -o $@ $< -l0hpp
lib0hpp.so: 0.hpp
	cd cpp && $(compile_clangxx) -shared -fpic -x c++ $(cxx_args) -o $@ $<
maincpp.o: main.cpp 
	cd cpp && $(compile_clangxx) -c $(cxx_args) -o $@ $<  



# clang phases compile  
0.i: 0.c 0.h
	$(ccl) -E $(ccl_args) $< -o $@ 
0.s: 0.c 0.h 
	$(ccl) $(ccl_args) -S $< 
0.ll: 0.c 0.h
	$(ccl) $(llvm_ir) -S -o $@ $<
0.phases: 0.c 0.h
	$(ccl) $(llvm_cl) $< 
0.ast: 0.c 0.h 
	$(compile_gcc) $(c_ast_dump) $<
0.out: 0.c 0.h
	$(ccl) $(ccl_args) $(ccl_verbose_arg) -o $@ $< 
0.trace: 0.out 
	strace ./$<



.DEFAULT_GOAL: main
.PHONY: clean main test 
clean:
	rm -f *i *.s *.ll 
	rm -f *.o *.a *.so *.out    
	rm -rf main maincpp test maincpptest
	clear