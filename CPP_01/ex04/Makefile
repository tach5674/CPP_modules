CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.

SRCS := main.cpp replace_in_file.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := replace_in_file.hpp
TARGET := program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re