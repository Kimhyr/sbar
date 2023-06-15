# compiler cache support
#
TARGET	:= sbar
SUFFIX	:= cxx

# compilation command
#
BUILD_MODE		:= release
COMPILER_CACHE	:= sccache
COMPILER		:= $(COMPILER_CACHE) clang++
COMPILER_FLAGS	:= -Isource -fdiagnostics-color=always -std=c++20 -O3 -Wall -Wextra -pedantic

ifeq '$(BUILD_MODE)' 'debug'
	COMPILER_FLAGS += -D_DEBUG -g
endif

# paths
#
SOURCE_PATH	:= source
OBJECT_PATH	:= object
BINARY_PATH	:= binary

# files
#
SOURCES	:= $(wildcard $(SOURCE_PATH)/*.$(SUFFIX))
OBJECTS	:= $(addprefix $(OBJECT_PATH)/, $(addsuffix .o, $(notdir $(basename $(SOURCES)))))
BINARY	:= $(BINARY_PATH)/$(TARGET)

CLEAN := $(OBJECTS) \
		 $(BINARY)

default: paths all

$(BINARY): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $@ $(COMPILER_FLAGS)

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.$(SUFFIX)
	$(COMPILER) $< $(COMPILER_FLAGS) -c -o $@

.PHONY: paths
paths:
	mkdir -p $(OBJECT_PATH) $(BINARY_PATH)

.PHONY: all
all: $(BINARY)

.PHONY: clean
clean:
	rm -f $(CLEAN)
