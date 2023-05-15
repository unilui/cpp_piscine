SRCS 		=	main.cpp Contact.cpp PhoneBook.cpp
OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
NAME		=	phone
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

clean:
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
