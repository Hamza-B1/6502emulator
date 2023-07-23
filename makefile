CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRCDIR = src
TESTDIR = test
INCDIR = include
BUILDDIR = bin
DEBUGDIR = debug

TARGET = $(BUILDDIR)/6502emulator
TEST_TARGET = $(BUILDDIR)/test6502emulator

.PHONY: all debug test clean

all: $(TARGET)

debug: CFLAGS += -g 
debug: $(DEBUGDIR)/6502emulator

test: CFLAGS += -g
test: $(TEST_TARGET)
	$(TEST_TARGET)


$(TARGET): $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
	$(CC) $^ -o $@

$(DEBUGDIR)/6502emulator: $(patsubst $(SRCDIR)/%.c, $(DEBUGDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DEBUGDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -g -c $< -o $@

$(TEST_TARGET): $(filter-out $(BUILDDIR)/main.o, $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))) $(patsubst $(TESTDIR)/%.c, $(DEBUGDIR)/%.o, $(wildcard $(TESTDIR)/*.c))
	$(CC) $^ -o $@

$(DEBUGDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET) $(DEBUGDIR)/*.o $(DEBUGDIR)/6502emulator $(TEST_TARGET)