TARGET			:= sbar
MODE			:= 
SUFFIX			:= c

# compilation
#
COMPILER		:= clang++
COMPILER_FLAGS	:= -fdiagnostics-color=always -mavx2 -mavx -std=c++20 -O3 -Wall -Wextra -pedantic

ifeq '$(MODE)' 'debug'
	COMPILER_FLAGS += -g
endif

# paths
#
SOURCE_PATH		:= source
OBJECT_PATH		:= object
BINARY_PATH		:= binary

# files
#
SOURCES	:= $(wildcard $(SOURCE_PATH)/*.$(SUFFIX))
OBJECTS	:= $(addprefix $(OBJECT_PATH)/, $(addsuffix .o, $(notdir $(basename $(SOURCES)))))
BINARY	:= $(BINARY_PATH)/$(TARGET)

#ifeq '$(BUILD_MODE)' 'debug'
#	BINARY := $(BINARY)-debug
#endif

CLEAN := $(OBJECTS) \
		 $(BINARY)

default: paths all

$(BINARY): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $@ $(COMPILER_FLAGS)

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.$(SUFFIX)
	sccache $(COMPILER) $< $(COMPILER_FLAGS) -c -o $@

.PHONY: paths
paths:
	mkdir -p $(OBJECT_PATH) $(BINARY_PATH)

.PHONY: all
all: $(BINARY)

.PHONY: clean
clean:
	rm -f $(CLEAN)
