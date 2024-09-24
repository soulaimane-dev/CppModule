CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = span
SRCF = main.cpp Span.cpp
RM = rm -f
OBJF = $(SRCF:.cpp=.o)
HEADERS = Span.hpp

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJF)
	$(CC) $(CPPFLAGS) $(OBJF) -o $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)
