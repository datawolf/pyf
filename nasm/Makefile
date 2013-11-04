#  Makefile for nasm program
#
#
all:sample sumprog

sample: io.o sample.o
	ld -s -o $@  $^
sumprog: io.o sumprog.o
	ld -s -o $@  $^

sample.o: sample.asm
	nasm -f elf $<
sumprog.o: sumprog.asm
	nasm -f elf  $<

.PHONY: clean

clean:
	$(RM) sample.o  sumprog.o sample sumprog
