CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I.

SRCS := main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := AMateria.hpp ICharacter.hpp Cure.hpp Ice.hpp Charcter.hpp
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