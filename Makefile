NAME        = hw

SRCS        = $(wildcard *.cpp)
OBJS        = $(SRCS:.cpp=.o)
CC          = c++ 
FLAGS		= -Wall -Werror -Wextra
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC)  $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:            fclean all

.PHONY:        all clean fclean re