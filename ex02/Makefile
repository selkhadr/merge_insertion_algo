SRCS = main.cpp PmergeVect.cpp  Vect_insertion.cpp Vect_merge.cpp 

OBJS = $(SRCS:.cpp=.o)

EXECUTION = PmergeMe

CPPFLAGS =  -fsanitize=address -g -Wall -Werror -Wextra -std=c++98

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