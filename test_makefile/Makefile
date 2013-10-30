# Makefile for to learn makefile
#
# @author: Wang Long (wanglong@l-cloud.org)
# @date: Wed Oct 30 16:25:31 CST 2013
#

string := bar.o foo.o bar.c 	 foo.c bar.s foo.s    foo.z  bar.z
VPATH := src:../includes
override CFLAGS += $(patsubst %, -l%, $(subst :, , $(VPATH)))

# text process functions

cflags:
	@echo $(CFLAGS)

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

# file process functions
dir:
	@echo $(dir src/foo.c bar.c src/include/foo.h)

notdir:
	@echo $(notdir src/foo.c bar.c src/include/foo.h)

suffix:
	@echo $(suffix src/foo.c bar.ss src/include/foo.h foo bar.i)

basename:
	@echo $(basename src/foo.c bar.ss src/include/foo.h foo bar.i)

addsuffix:
	@echo $(addsuffix .c, foo bar test)

addprefix:
	@echo $(addprefix src/, foo.c bar.c test.h)

join:
	@echo $(join a b c, .d .e .f)

wildcard:
	@echo $(wildcard *.c)

# foreach function
foreach:
	@echo $(foreach file, $(wildcard *.c), $(addprefix src/, $(file)))

ADDPREFIX = $(addprefix src/, $(file))  # Notice =  is not :=
foreach2:
	@echo $(foreach file, $(wildcard *.c), $(ADDPREFIX))

# if function
SRC_DIR := /home/wanglong/src
if:
	@echo $(if $(SRC_DIR), $(SRC_DIR), /home/src/)

# call function

# firset example
reverse = $(2) $(1)
call:
	@echo $(call reverse, long,  wang)

# second example
pathsearch = $(firstword $(wildcard $(addsuffix /$(1), $(subst :, ,$(PATH)))))
call2:
	@echo  $(wildcard $(addsuffix /ldd, $(subst :, ,$(PATH))))
	@echo $(call pathsearch,ls)

# value function
FOO = $PATH
value:
	@echo	$(FOO)
	@echo	$(value FOO)


# origin function
# origin return : 
# 		undefined, default, environment, 
# 		environment override, file, 
# 		command line, override, automatic
ifneq "$(findstring environment,$(origin bletch))" ""
bletch = enviroment.
endif

ifneq "$(findstring undefined,$(origin bletch))" ""
bletch = undefined bletch
endif

origin:
	@echo $(bletch)

# shell function
shell:
	@echo $(shell echo *.c)


# error function
error:
	@echo $(error found a error)

# warning function
warning:
	@echo $(warning found a warning)
