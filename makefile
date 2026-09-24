CC = gcc
CFLAGS = -Wall
TARGET = apc
SRCS = main.c addition.c subtraction.c multiplication.c dll_utils.c division.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)