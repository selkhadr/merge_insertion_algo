<<<<<<< HEAD
SRCS = main.cpp PmergeVect.cpp Vect_insertion.cpp Vect_merge.cpp 
=======
SRCS = main.cpp PmergeVect.cpp  Vect_insertion.cpp Vect_merge.cpp 
>>>>>>> 6f7006556eecf8ffddb064a0ee1559c365e3b4b2

OBJS = $(SRCS:.cpp=.o)

EXECUTION = PmergeMe

<<<<<<< HEAD
CPPFLAGS =   -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g
=======
CPPFLAGS =  -fsanitize=address -g -Wall -Werror -Wextra -std=c++98
>>>>>>> 6f7006556eecf8ffddb064a0ee1559c365e3b4b2

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