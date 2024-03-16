# Copyright (C) 2023-4 Ethan Uppal. All rights reserved.

SRCDIR		:= ./src
INCLUDEDIR	:= ./src

CC			:= $(shell which g++ || which clang)
CFLAGS		:= -std=c++17 -pedantic -Wall -Wextra -I $(INCLUDEDIR)
CDEBUG		:= -g
CRELEASE	:= -O2 -DRELEASE_BUILD
TARGET		:= sdlwrapper
REALTARGET	:= lib$(TARGET).so

# CFLAGS 		+= $(CRELEASE)
CFLAGS 		+= $(CDEBUG)

# use SDL
CFLAGS		+= $(shell sdl2-config --cflags --libs)

SRC			:= $(shell find $(SRCDIR) -name "*.cpp" -type f -not -path "$(SRCDIR)/demo/*")
OBJ			:= $(SRC:.cpp=.o)
DEPS 		:= $(OBJS:.o=.d) 

$(REALTARGET): $(OBJ)
	$(CC) -shared $(CFLAGS) $^ -o $@

%.o: %.cpp
	@echo 'Compiling $@'
	$(CC) $(CFLAGS) -MMD -MP $< -c -o $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -rf demo $(OBJ) $(REALTARGET) $(DEPS) $(shell find . -name "*.dSYM") $(shell find . -name "*.d")

.PHONY: demo
demo: $(REALTARGET)
	$(CC) $(CFLAGS) $(SRCDIR)/demo/demo_view.cpp $(SRCDIR)/demo/main.cpp -L. -l$(TARGET) -o demo

