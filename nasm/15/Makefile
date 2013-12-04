#  Makefile for nasm program
all: read_array 

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

read_array: read_array.o io.o
	ld $(LD_FLAGS) -o $@  $^

read_array.o: read_array.asm
	nasm  $(NASM_FLAGS) $<


.PHONY: clean

clean:
	$(RM) read_array read_array.o 
