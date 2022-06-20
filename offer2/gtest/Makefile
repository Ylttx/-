HOME_PATH = ..
TEST_PATH = .

TARGET = run_test
PROGRAM = run_src

CPP 			:= g++
CPPFLAGS      	:= -std=c++11
LDFLAGS         := -lgtest -pthread

INCDIRS 		:= $(HOME_PATH)/include

SRCDIRS			:= $(TEST_PATH) \
				   src

COBJECTS        := problem_set.o

CCFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

CCFILENDIR		:= $(notdir  $(CCFILES))
COBJS			:= $(patsubst %, $(HOME_PATH)/obj/%, $(COBJECTS))
CCOBJS			:= $(patsubst %, obj/%, $(CCFILENDIR:.cpp=.o))
OBJS            := $(COBJS) $(CCOBJS)

VPATH			:= $(SRCDIRS)

all : $(PROGRAM) $(TARGET)

$(PROGRAM) :
	@cd $(HOME_PATH) && make

$(TARGET) : $(OBJS)
	@echo compiling $(notdir $<)
	@$(CPP) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)

$(CCOBJS) : obj/%.o : %.cpp
	@echo compiling $(notdir $<)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -o $@ -c $< $(INCLUDE)

.PHONY: clean

clean:
	rm -rf obj $(TARGET)
