#  Makefile for nasm program
all: sar_divide shl_mlt shl_mlt2

ARCH=$(shell uname -m)

ifeq ($(ARCH),x86_64)
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386
else
NASM_FLAGS=-f elf
LD_FLAGS=
endif

sar_divide: io.o sar_divide.o
	ld $(LD_FLAGS) -o $@  $^

sar_divide.o: sar_divide.asm
	nasm  $(NASM_FLAGS) $<

shl_mlt: io.o shl_mlt.o
	ld $(LD_FLAGS) -o $@  $^

shl_mlt.o: shl_mlt.asm
	nasm  $(NASM_FLAGS) $<

shl_mlt2: io.o shl_mlt2.o
	ld $(LD_FLAGS) -o $@  $^

shl_mlt2.o: shl_mlt2.asm
	nasm  $(NASM_FLAGS) $<



.PHONY: clean

clean:
	$(RM) sar_divide sar_divide.o  shl_mlt2 shl_mlt2.o  shl_mlt.o shl_mlt
