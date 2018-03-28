test: test.c
	gcc -O0 -mno-optimize-swaps -g  test.c  -o test
	gcc -moptimize-swaps -O2 -mcpu=power8 test.c  -o test1

clean:
	rm test1 test
