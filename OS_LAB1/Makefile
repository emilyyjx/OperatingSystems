# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>

# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g

# Define the source files and object files
SRCS = main.c list.c
OBJS = $(SRCS:.c=.o)

# Define the target executable
TARGET = list

# Default target
all: $(TARGET)

# Linking the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compiling the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -std=c99

# Clean up the object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

