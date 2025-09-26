# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Explicitly list source files
SRCS := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
# HEADERS := Zombie.h
DEPS := $(SRCS:.cpp=.d)
# Replace .cpp with .o for objects
OBJS := $(SRCS:.cpp=.o)

# Target binary
TARGET := program

# Default rule
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile each .cpp into .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

# Clean up build artifacts
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re