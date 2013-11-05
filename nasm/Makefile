#  Makefile for nasm program
#
#
all:sample sumprog adddigits addition toupper

sample: io.o sample.o
	ld -s -o $@  $^
sumprog: io.o sumprog.o
	ld -s -o $@  $^
adddigits: io.o adddigits.o
	ld -s -o $@  $^
toupper: io.o toupper.o
	ld -s -o $@  $^
addition: io.o addition.o
	ld -s -o $@  $^

sample.o: sample.asm
	nasm -f elf $<
toupper.o: toupper.asm
	nasm -f elf $<
addition.o: addition.asm
	nasm -f elf $<
sumprog.o: sumprog.asm
	nasm -f elf  $<
adddigits.o: adddigits.asm
	nasm -f elf  $<
.PHONY: clean

clean:
	$(RM) sample.o  sumprog.o sample sumprog adddigits adddigits.o addition.o addition toupper toupper.o
