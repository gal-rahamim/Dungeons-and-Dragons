# this is my target
TARGET = main

# All .c files in this directory are my sources
SOURCES = main.cpp $(SRC_DIR)passage.cpp $(SRC_DIR)room.cpp $(SRC_DIR)i_object.cpp $(SRC_DIR)sword.cpp
SOURCES += $(SRC_DIR)player.cpp $(SRC_DIR)shield.cpp $(SRC_DIR)i_fightable.cpp $(SRC_DIR)dragon.cpp $(SRC_DIR)key.cpp
SOURCES += $(SRC_DIR)i_shield.cpp $(SRC_DIR)i_sword.cpp $(SRC_DIR)map_loader.cpp $(SRC_DIR)passage_loader.cpp
SOURCES += $(SRC_DIR)passage_parser.cpp $(SRC_DIR)room_loader.cpp $(SRC_DIR)room_parser.cpp
SOURCES += $(SRC_DIR)dragon_parser.cpp $(SRC_DIR)dragon_loader.cpp $(SRC_DIR)object_parser.cpp $(SRC_DIR)object_loader.cpp

# Include directory
INC_DIR = ../../include/
SRC_DIR = ../../src/

# General compilation flags

# The compiler will be gcc("CC" is MAKE variable)
CC = g++
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Werror -Wall -g3
CFLAGS += -g
CXXFLAGS = $(CFLAGS) -std=c++17
LDFLAGS = -g -pthread
CPPFLAGS = -I$(INC_DIR)


#  my objects are the .o of my sources
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY:all
all: $(TARGET)

# The default command, compile all the sources
#$(CC) $(LDFLAGS) $(^) -o $(@)

main: LDLIBS += -ldl

$(TARGET): $(OBJECTS)

#built-in c compiler rule is $(CC) $(CFLAGS) $(CPPFLAGS) -c  -o $(@) $(<)

#spacial targets
.PHONY:clean
clean:
	rm -f $(TARGET) *.o *.out *.txt
	rm -f $(SRC_DIR)*.o

.PHONY:run
run: $(TARGET)
	./$(TARGET) -v

.PHONY:valgrind
valgrind:	$(TARGET)
	valgrind --leak-check=full ./$(TARGET)

.PHONY:drd
drd:  $(TARGET)
	valgrind --tool=drd --log-file=drd.log ./$(TARGET)

.PHONY:helgrind
helgrind:  $(TARGET)
	valgrind --tool=helgrind --log-file=helgrind.log ./$(TARGET)
