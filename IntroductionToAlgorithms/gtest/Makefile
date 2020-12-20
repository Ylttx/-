HOME_PATH = ..
TEST_PATH = .

TARGET = run_test
PROGRAM = run_src

CPP 			:= g++
LDFLAGS         := -lgtest -lpthread

INCDIRS 		:= $(HOME_PATH)/include

SRCDIRS			:= $(TEST_PATH) \
				   src

COBJECTS        := sort.o

CCFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cc))

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

CCFILENDIR		:= $(notdir  $(CCFILES))
COBJS			:= $(patsubst %, $(HOME_PATH)/obj/%, $(COBJECTS))
CCOBJS			:= $(patsubst %, obj/%, $(CCFILENDIR:.cc=.o))
OBJS            := $(COBJS) $(CCOBJS)

VPATH			:= $(SRCDIRS)

all : $(PROGRAM) $(TARGET)

$(PROGRAM) :
	@cd $(HOME_PATH) && make

$(TARGET) : $(OBJS)
	@echo compiling $(notdir $<)
	@$(CPP) $^ -o $@ $(LDFLAGS)

$(CCOBJS) : obj/%.o : %.cc
	@echo compiling $(notdir $<)
	@mkdir -p $(dir $@)
	@$(CPP) -o $@ -c $< $(INCLUDE) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf obj $(TARGET)
