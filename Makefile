# Copyright (C) 2023-4 Ethan Uppal. All rights reserved.

SRCDIR		:= ./src
INCLUDEDIR	:= ./src

CC			:= $(shell which g++ || which clang)
CFLAGS		:= -std=c++17 -pedantic -Wall -Wextra -I $(INCLUDEDIR)
CDEBUG		:= -g
CRELEASE	:= -O2 -DRELEASE_BUILD
TARGET		:= sdlwrapper
REALTARGET	:= lib$(TARGET).a
INSTLIB		:= /usr/local/lib
INSTHEA		:= /usr/local/include/$(TARGET)

# CFLAGS 		+= $(CRELEASE)
CFLAGS 		+= $(CDEBUG)

# use SDL
CFLAGS		+= $(shell sdl2-config --cflags --libs)

SRC			:= $(shell find $(SRCDIR) -name "*.cpp" -type f -not -path "$(SRCDIR)/demo/*")
OBJ			:= $(SRC:.cpp=.o)
DEPS 		:= $(OBJS:.o=.d) 

# NOT MY CODE
# Customizes ar for macOS
ifeq ($(shell uname), Darwin)
AR 		:= /usr/bin/libtool
AR_OPT 	:= -static
else
AR 		:= ar
AR_OPT 	:= rcs $@ $^
endif

$(REALTARGET): $(OBJ)
	$(AR) $(AR_OPT) $^ -o $@


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

install: $(REALTARGET)
	mv $(REALTARGET) $(REALTARGET).bak
	make clean
	mv $(REALTARGET).bak $(REALTARGET)
	mkdir -p $(INSTLIB)
	mkdir -p $(INSTHEA)
	mv $(REALTARGET) $(INSTLIB)
	cp -a -r $(SRCDIR) $(INSTHEA)/
	mv $(INSTHEA)/$(SRCDIR)/* $(INSTHEA)/ 
	chmod +rw $(INSTHEA)/gui 
	chmod +rw $(INSTHEA)/gui/* 

uninstall:
	rm -r $(INSTLIB)/$(REALTARGET) \
		$(INSTHEA)

reinstall:
	make uninstall
	make install
