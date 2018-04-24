NAME = libft.a
HEADER = includes
SRCS_P = $(shell ls srcs/)
SRCS = $(addprefix srcs/, $(SRCS_P))

CFLAGS = -Wall -Werror -Wextra -ggdb
CC = gcc

OBJ = $(SRCS:.c=.o)
		CL=\x1b[35m
		GREEN=\033[1;32m
		RED=\033[1;31m
		CL2=\x1b[36m
		NC=\033[0m

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)[✓]$(NC)$(CL) Objects of $(NAME) compiled$(NC)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)[✓]$(NC)$(CL) library $(NAME) built$(NC)"

%.o: %.c
	@$(CC) -c $< -o $@ -I$(HEADER) $(CFLAGS)

clean:
	@rm -Rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned"

re: fclean all
