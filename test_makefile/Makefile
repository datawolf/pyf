# Makefile for to learn makefile
#
# @author: Wang Long (wanglong@l-cloud.org)
# @date: Wed Oct 30 16:25:31 CST 2013
#

string := bar.o foo.o bar.c 	 foo.c bar.s foo.s    foo.z  bar.z

sort:
	@echo $(sort sort $(string))

filter:
	@echo $(filter %.c %s, $(string))

filter-out:
	@echo $(filter-out %.c %s, $(string))

findstring:
	@echo $(findstring bar.i, $(string))

strip:
	@echo $(strip $(string))

patsubst:
	@echo $(patsubst %.c, %.i, $(string))

subst:
	@echo $(subst ee,EE,feet on the street)

word:
	@echo $(word 2, $(string))

wordlist:
	@echo $(wordlist 2, 4, $(string))

words:
	@echo $(words $(string))
firstword:
	@echo $(firstword $(string))
