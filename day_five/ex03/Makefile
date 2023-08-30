SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS		= ${SRCS:%.cpp=$(OBJS_DIR)%.o}
OBJS_DIR	= objects/
NAME		= bureaucrat_plus
CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
RM			= rm -rf

$(OBJS_DIR)%.o:	%.cpp
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -g -c $< -o $@ -I includes

all:		$(NAME)

$(NAME):	$(OBJS)
			@${CC} $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean:
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
