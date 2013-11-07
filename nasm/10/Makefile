#  Makefile for nasm program
all:binchar hex1char hex2char

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

hex1char: io.o hex1char.o
	ld $(LD_FLAGS) -o $@  $^

hex1char.o: hex1char.asm
	nasm  $(NASM_FLAGS) $<

hex2char: io.o hex2char.o
	ld $(LD_FLAGS) -o $@  $^

hex2char.o: hex2char.asm
	nasm  $(NASM_FLAGS) $<

.PHONY: clean

clean:
	$(RM) binchar binchar.o  hex1char hex1char.o hex2char hex2char.o
