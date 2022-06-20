TEST_PATH = gtest

CC = g++

INCDIRS 		:= include

SRCDIRS			:= src

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
CFILENDIR		:= $(notdir  $(CFILES))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.cpp=.o))

VPATH			:= $(SRCDIRS)

all : $(COBJS)
	@echo $(CFILES)
	@echo $(CFILENDIR)
	@echo $(COBJS)


test : $(COBJS)
	@cd $(TEST_PATH) && make

.PHONY: clean cleanall

$(COBJS) : obj/%.o : src/%.cpp
	@echo compiling $(notdir $<)
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDE) -c $< -o $@

clean:
	rm -rf obj

cleanall:
	rm -rf obj
	@cd $(TEST_PATH) && make clean
