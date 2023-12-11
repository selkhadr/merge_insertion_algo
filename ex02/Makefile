SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

EXECUTION = PmergeMe

<<<<<<< HEAD
CPPFLAGS =  -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g
=======
CPPFLAGS =  -g -Wall -Werror -Wextra -std=c++98 -fsanitize=address
>>>>>>> be9c63b72f4488ea384d17ba402a118785602b18

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