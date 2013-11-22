#  Makefile for nasm program
all:procfib module bblmain varpara

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

procfib: io.o procfib.o
	ld $(LD_FLAGS) -o $@  $^

procfib.o: procfib.asm
	nasm  $(NASM_FLAGS) $<

module: io.o module1.o module2.o
	ld $(LD_FLAGS) -o $@  $^

module1.o: module1.asm
	nasm  $(NASM_FLAGS) $<

module2.o: module2.asm
	nasm  $(NASM_FLAGS) $<

bblmain: bblmain.o bblread.o bbloutput.o bblsort.o io.o
	ld $(LD_FLAGS) -o $@  $^

bblmain.o: bblmain.asm
	nasm  $(NASM_FLAGS) $<

bbloutput.o: bbloutput.asm
	nasm  $(NASM_FLAGS) $<

bblread.o: bblread.asm
	nasm  $(NASM_FLAGS) $<

bblsort.o: bblsort.asm
	nasm  $(NASM_FLAGS) $<

varpara: io.o varpara.o
	ld $(LD_FLAGS) -o $@  $^

varpara.o: varpara.asm
	nasm  $(NASM_FLAGS) $<

.PHONY: clean

clean:
	$(RM) procfib procfib.o module module1.o module2.o bblmain bblmain.o \
		bbloutput.o bblsort.o bblread.o varpara.o varpara
