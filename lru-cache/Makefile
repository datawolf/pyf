# Make file for lru-cache
# Author: Wang Long (wanglong@cse.buaa.edu.cn)
# Date:  2013-10-22


flag=-g

lru-cache: lru.o test.o
	gcc -o lru-cache  $(flag) lru.o test.o
lru.o: lru.h lru.c
	gcc -c  $(flag) lru.c
test.o: test.c lru.h
	gcc -c  $(flag) test.c
clean:
	rm *.o lru-cache
