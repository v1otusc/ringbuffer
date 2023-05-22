CC = g++
CFLAGS = -std=c++11 -Wall

TARGET = test

SRCS = test.cpp

INCLUDES = -I.

DEPS = Nocopyable.hpp RingBuffer.hpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
