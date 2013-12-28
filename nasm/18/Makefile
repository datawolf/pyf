#  Makefile for nasm program
all: asciiadd bcdadd

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

asciiadd: io.o asciiadd.o
	ld $(LD_FLAGS) -o $@  $^

asciiadd.o: asciiadd.asm
	nasm  $(NASM_FLAGS) $<


bcdadd: io.o bcdadd.o
	ld $(LD_FLAGS) -o $@  $^

bcdadd.o: bcdadd.asm
	nasm  $(NASM_FLAGS) $<

.PHONY: clean

clean:
	$(RM) asciiadd.o asciiadd bcdadd bcdadd.o
