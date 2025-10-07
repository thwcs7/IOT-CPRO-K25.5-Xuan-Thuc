CC := gcc
CFLAGS := -O0 -g -std=c11 -Wall -Wextra
TARGET := memory_lab
SRC := memory_lab.c

.PHONY: all stack_overflow memory_leak valgrind clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

stack_overflow: $(TARGET)
	./$(TARGET) stack_overflow

memory_leak: $(TARGET)
	./$(TARGET) memory_leak

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrinf-out.txt ./$(TARGET) memory_leak

clean:
	-rm -f $(TARGET) valgrinf-out.txt
