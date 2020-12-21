TEST_PATH = gtest

CC = gcc

INCDIRS 		:= include

SRCDIRS			:= src

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
CFILENDIR		:= $(notdir  $(CFILES))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))

VPATH			:= $(SRCDIRS)

all : $(COBJS)

test : $(COBJS)
	@cd $(TEST_PATH) && make

.PHONY: clean cleanall

$(COBJS) : obj/%.o : %.c
	@echo compiling $(notdir $<)
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf obj

cleanall:
	@rm -rf obj
	@cd $(TEST_PATH) && make clean
