CC = gcc
TESTFLAGS = -lcheck -g
CFLAGS = -Wall -Wextra -Werror -std=c11 -I /opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/lib -lcheck
TESTFLAGS2 = -lcheck -lm -lpthread -lrt -lsubunit -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: test

s21_matrix.a : func/*.c
	$(CC) $(CFLAGS) -g -std=c11 -c func/*.c
	ar rcs s21_matrix.a *.o
	rm -rf *.o

test: clean tests/test.c func/*.c
	$(CC) $(CFLAGS) tests/test.c func/*.c -o test $(TESTFLAGS)
	./test

gcov_report:
	$(CC) $(GCOVFLAGS) $(CFLAGS) tests/test.c func/*.c -o test $(TESTFLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno string_test.gcda string_test.gcno
	open report/index.html
rebuild: clean all

clean: 
	rm -rf *.o test *.a a.out *.gcno *.gcda test.dSYM *.info report
	clear

style_check:
	clang-format -style=Google -n *.c *.h *.c

style:
	clang-format -style=Google -i *.c *.h *.c

main:
	$(CC) $(CFLAGS) -c func/*.c
	$(CC) $(CFLAGS) main.c *.o -o main
	./main

val:
	cd ../materials/build
	
valback:
	cd ../../src