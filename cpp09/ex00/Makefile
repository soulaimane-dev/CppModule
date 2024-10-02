# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 12:07:42 by sbouabid          #+#    #+#              #
#    Updated: 2024/10/02 12:20:43 by sbouabid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
SRCF = main.cpp BitcoinExchange.cpp
RM = rm -f
OBJF = $(SRCF:.cpp=.o)
HEADERS = BitcoinExchange.hpp

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJF)
	$(CC) $(CPPFLAGS) $(OBJF) -o $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re : fclean all



# Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

