#
#
#
all:sample sumprog

sample.o: sample.asm
	nasm -f elf $<
io.o: io.mac
	nasm -f elf $<
sumprog.o: sumprog.asm
	nasm -f elf  $<

.PHONY: clean

clean:
	$(RM) *.o sample sumprog
