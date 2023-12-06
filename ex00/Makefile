SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

EXECUTION = btc

CPPFLAGS =-Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

CC = c++

all:$(EXECUTION)

%.o:	%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXECUTION):	$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(EXECUTION)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(EXECUTION)

re:	fclean all