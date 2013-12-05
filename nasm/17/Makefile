#  Makefile for nasm program
all: mem_copy str_test

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

mem_copy: io.o mem_copy.o
	ld $(LD_FLAGS) -o $@  $^

mem_copy.o: mem_copy.asm
	nasm  $(NASM_FLAGS) $<

str_test: str_test.o io.o string.o
	ld $(LD_FLAGS) -o $@  $^

string.o: string.asm
	nasm  $(NASM_FLAGS) $<

str_test.o: str_test.asm
	nasm  $(NASM_FLAGS) $<




.PHONY: clean

clean:
	$(RM)  mem_copy mem_copy.o str_test str_test.o string.o
