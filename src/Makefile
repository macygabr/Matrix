CC=gcc
WWW = -Wall -Wextra -Werror
CFLAGS= -c $(WWW) -std=c11  
FLAGS= -g $(WWW)
ADD_MATH_LIB = $(WWW) -lm

FILES = support/*.c operation/*.c
TEST_FLAGS=-lcheck --coverage
TEST_FUNC= tests/s21_test.c

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lsubunit -lm
	OPEN=echo 'report: s21_matrix/src/report/index.html'
else
	OPEN=open ./report/index.html
endif

all: clean s21_matrix.a

clean:
	rm -rf *.o *.a *.out  *.info */*.gcda */*.gcno *.gch *.dSYM */*.o tests/*.out greport report gcov tests/test tests/s21_test.c

s21_matrix.a:
	$(CC) $(CFLAGS) -c operation/sub_matrix.c -o operation/sub_matrix.o
	$(CC) $(CFLAGS) -c operation/remove_matrix.c -o operation/remove_matrix.o
	$(CC) $(CFLAGS) -c operation/sum_matrix.c -o operation/sum_matrix.o
	$(CC) $(CFLAGS) -c operation/sum_matrix.c -o operation/sum_matrix.o
	$(CC) $(CFLAGS) -c operation/calc_complements.c -o operation/calc_complements.o
	$(CC) $(CFLAGS) -c operation/create_matrix.c -o operation/create_matrix.o
	$(CC) $(CFLAGS) -c operation/determinant.c -o operation/determinant.o
	$(CC) $(CFLAGS) -c operation/eq_matrix.c -o operation/eq_matrix.o
	$(CC) $(CFLAGS) -c operation/mult_matrix.c -o operation/mult_matrix.o
	$(CC) $(CFLAGS) -c operation/inverse_matrix.c -o operation/inverse_matrix.o
	$(CC) $(CFLAGS) -c operation/mult_number.c -o operation/mult_number.o
	$(CC) $(CFLAGS) -c operation/transpose.c -o operation/transpose.o

	$(CC) $(CFLAGS) -c support/support_functions.c -o support/support_functions.o
	ar -rcs s21_matrix.a $(FILES:.c=.o)


gcov_report: clean check
	mkdir -p gcov
	gcc $(FILES) $(TEST_FUNC) -o gcov/greport $(TEST_FLAGS)
	./gcov/greport;
	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	genhtml -o ./report s21_matrix.info
	$(OPEN)


clang:
	clang-format -style="{BasedOnStyle: Google}" -n */*.c *.h

test: clean s21_matrix.a clang check 
	$(CC) $(WWW) -std=c11  tests/s21_test.c s21_matrix.a -o tests/test $(TEST_FLAGS) 
	./tests/test

valgrind: test
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes ./tests/test

check:
	checkmk clean_mode=1 tests/headers.check tests/*.check > tests/s21_test.c

my_test: clean s21_matrix.a
	$(CC)  tests/my_test.c s21_matrix.a $(ADD_MATH_LIB) -o tests/my_test
	echo
	./tests/my_test
