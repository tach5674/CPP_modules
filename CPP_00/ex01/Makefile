CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.

SRCS := main.cpp PhoneBook.cpp Contact.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := PhoneBook.hpp Contact.hpp
TARGET := PhoneBook

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