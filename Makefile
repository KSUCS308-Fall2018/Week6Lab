CC = gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)

test: CFLAGS = -DTEST 
test: clean $(obj)
	$(CC) -o test $(obj) 

main: clean $(obj)
	$(CC) -o main $(obj) 

.PHONY: clean
clean:
	rm -f $(obj) main test 
