
SRCS = main.cpp PmergeVect.cpp Vect_insertion.cpp Vect_merge.cpp 

HEADER = PmergeVect.hpp

OBJS = $(SRCS:.cpp=.o)

EXECUTION = PmergeMe

CPPFLAGS =   -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g

CC = c++

all:$(EXECUTION)

%.o:	%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXECUTION):	$(OBJS) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(EXECUTION)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(EXECUTION)

re:	fclean all