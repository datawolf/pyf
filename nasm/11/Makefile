#  Makefile for nasm program
all:procex1 procex2 procex3 procswap

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

procex1: io.o procex1.o
	ld $(LD_FLAGS) -o $@  $^

procex1.o: procex1.asm
	nasm  $(NASM_FLAGS) $<

procex2: io.o procex2.o
	ld $(LD_FLAGS) -o $@  $^

procex2.o: procex2.asm
	nasm  $(NASM_FLAGS) $<

procex3: io.o procex3.o
	ld $(LD_FLAGS) -o $@  $^

procex3.o: procex3.asm
	nasm  $(NASM_FLAGS) $<

procswap: io.o procswap.o
	ld $(LD_FLAGS) -o $@  $^

procswap.o: procswap.asm
	nasm  $(NASM_FLAGS) $<

.PHONY: clean

clean:
	$(RM) procex1 procex1.o procex2 procex2.o procex3 procex3.o procswap.o procswap
