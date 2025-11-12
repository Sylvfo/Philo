NAME = philo

CC = cc

FLAGS = -g  -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = ./sources

SRCS = 	${shell find ${SRC_DIR} -type f -name '*.c'}\

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

RM = rm -f

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		${CC} ${FLAGS} -I. -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
			rm -rf $(OBJ_DIR)
			${RM} ${OBJ}

fclean:		clean
			${RM} -r ${NAME}

re: fclean all

.PHONY:		all re clean fclean
