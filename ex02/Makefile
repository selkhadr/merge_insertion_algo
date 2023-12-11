SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

EXECUTION = PmergeMe

CPPFLAGS =  -g -Wall -Werror -Wextra -std=c++98 -fsanitize=address

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