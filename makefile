CC = g++
CFLAGS = -O 
LDFLAGS = -mwindows
INCLUDES = 
LIBS =
TARGET = main
SRC=$(wildcard *.cpp) 
OBJS = $(SRC:.cpp=.o)
# 生成規則 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS) 
run:
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) .nfs* *~ *.core *.stackdump \#* core 
