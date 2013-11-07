#  Makefile for nasm program
all:binchar

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif


binchar: io.o binchar.o
	ld $(LD_FLAGS) -o $@  $^

binchar.o: binchar.asm
	nasm  $(NASM_FLAGS) $<


.PHONY: clean

clean:
	$(RM) binchar binchar.o 
