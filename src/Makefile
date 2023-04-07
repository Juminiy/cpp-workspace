compile_gcc= gcc 
compile_gxx= g++
compile_clang= clang
compile_clangxx= clang++

c_args= -std=gnu99 -Wall -O2 
cxx_args= -std=c++11 -Wall -O2 

compile_test_args= -DCOMPILE_TEST
run_test_args= -DRUN_TEST
run_debug_args= -DRUNTIME_DEBUG

ccl= $(compile_clang)
ccl_args= $(c_args)
ccl_debug= -g
llvm_ir= -emit-llvm 
llvm_cl= -ccc-print-phases

main: main.o lib0.a 
	$(ccl) $(ccl_args) -o $@ $^
0.s: 0.c 0.h 
	$(ccl) $(ccl_args) -S $<
0.ll: 0.c 0.h
	$(ccl) $(llvm_ir) -S -o $@ $<
0.procedure: 0.c 0.h
	$(ccl) $(llvm_cl) $< 
0.o: 0.c 0.h
	$(ccl) -c $(ccl_args) -o $@ $< 
1.o: 1.c 1.h
	$(ccl) -c $(ccl_args) -o $@ $<
2.o: 2.c 2.h
	$(ccl) -c $(ccl_args) $(compile_test_args) -o $@ $<
main.o: main.c 0.h 1.h 2.h
	$(ccl) -c $(ccl_args) $(compile_test_args) $(run_test_args) -o $@ $< 

lib0.a: 0.o 1.o 2.o 
	ar cr $@ $^     


maincpp: maincpp.o lib0hpp.so 
	$(compile_clangxx) $(cxx_args) -L./ -o $@ $< -l0hpp
lib0hpp.so: 0.hpp
	$(compile_clangxx) -shared -fpic -x c++ $(cxx_args) -o $@ $<
maincpp.o: main.cpp 
	$(compile_clangxx) -c $(cxx_args) -o $@ $<  

test: main.o 
	$(ccl) $(compile_test_args) -c $(ccl_args) -o $@ $<

.DEFAULT_GOAL: main
.PHONY: clean main test 
clean:
	rm -f *.s *.o *.a *.so *.out  
	rm -rf ../lib main maincpp  
	clear