# Makefile
hello32: hello32.o
	ld -o hello32 hello32.o
hello32.o: hello32.asm
	nasm -f elf64 -o hello32.o hello32.asm
# nasm -f elf -o hello32.o hello32.asm
hello64: hello64.o
	ld -o hello64 hello64.o
hello64.o: hello64.asm
	nasm -f elf64 -o hello64.o hello64.asm

clean:
	$(RM) *.o hello32 hello64
