# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 08:38:25 by sbouabid          #+#    #+#              #
#    Updated: 2024/07/24 09:29:23 by sbouabid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Animal
SRCF = main.cpp Animal.cpp Cat.cpp Dog.cpp
RM = rm -f
OBJF = $(SRCF:.cpp=.o)
HEADERS = Animal.hpp Dog.hpp Cat.hpp

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJF)
	$(CC) $(CPPFLAGS) $(OBJF) -o $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)
