TEST_PATH = gtest

CC = g++ -std=c++11

INCDIRS 		:= include

SRCDIRS			:= src

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
CFILENDIR		:= $(notdir  $(CFILES))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.cpp=.o))

VPATH			:= $(SRCDIRS)

all : $(COBJS)

test : $(COBJS)
	@cd $(TEST_PATH) && make

run_test:
	@./gtest/run_test

.PHONY: clean

$(COBJS) : obj/%.o : src/%.cpp
	@echo compiling $(notdir $<)
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDE) -c $< -o $@

clean:
	rm -rf obj
	@cd $(TEST_PATH) && make clean
