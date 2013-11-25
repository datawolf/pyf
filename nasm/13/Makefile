#  Makefile for nasm program
all: array_sum ins_sort test_sum

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

array_sum: io.o array_sum.o
	ld $(LD_FLAGS) -o $@  $^

array_sum.o: array_sum.asm
	nasm  $(NASM_FLAGS) $<


ins_sort: io.o ins_sort.o
	ld $(LD_FLAGS) -o $@  $^

ins_sort.o: ins_sort.asm
	nasm  $(NASM_FLAGS) $<

test_sum: io.o test_sum.o
	ld $(LD_FLAGS) -o $@  $^

test_sum.o: test_sum.asm
	nasm  $(NASM_FLAGS) $<

.PHONY: clean

clean:
	$(RM) array_sum.o array_sum ins_sort.o ins_sort test_sum test_sum.o
