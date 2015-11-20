CC = g++
CFLAGS = -O 
LDFLAGS = -mwindows
INCLUDES = 
LIBS =
DEBUG = 
TARGET = main
SRC=$(wildcard *.cpp) 
OBJS = $(SRC:.cpp=.o)
.SUFFIXES:	.cpp
# 生成規則 
all: $(TARGET)

debug: DEBUG=-g -DDEBUG

debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS) 
run:
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) .nfs* *~ *.core *.stackdump \#* core 

.cpp.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -c $< 
