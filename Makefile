NAME = libft.a
HEADER = includes
SRCS_P = ft_atoi.c \
		 ft_isprint.c \
		 ft_lstmap.c \
		 ft_memdel.c \
		 ft_putnbr.c \
		 ft_putwstr.c \
		 ft_strdel.c \
		 ft_strlen.c \
		 ft_strnew.c \
		 ft_strtrim.c \
		 ft_bzero.c \
		 ft_itoa.c \
		 ft_lstnew.c \
		 ft_memmove.c \
		 ft_putnbr_fd.c \
		 ft_strcat.c \
		 ft_strdup.c \
		 ft_strmap.c \
		 ft_strnstr.c \
		 ft_tolower.c \
		 ft_exit.c \
		 ft_itoa_base.c \
		 ft_memalloc.c \
		 ft_memset.c \
		 ft_strccpy.c \
		 ft_strequ.c \
		 ft_strmapi.c \
		 ft_strrchr.c \
		 ft_toupper.c \
		 ft_isalnum.c \
		 ft_lstadd.c \
		 ft_memccpy.c \
		 ft_putchar.c \
		 ft_putnstr.c \
		 ft_strchr.c \
		 ft_striter.c \
		 ft_strncat.c \
		 ft_strsplit.c \
		 rostring.c \
		 ft_isalpha.c \
		 ft_lstdel.c \
		 ft_memchr.c \
		 ft_putchar_fd.c \
		 ft_putstr.c \
		 ft_strclr.c \
		 ft_striteri.c \
		 ft_strncmp.c \
		 ft_strstr.c \
		 ft_isascii.c \
		 ft_lstdelone.c \
		 ft_memcmp.c \
		 ft_putendl.c \
		 ft_putstr_fd.c \
		 ft_strcmp.c \
		 ft_strjoin.c \
		 ft_strncpy.c \
		 ft_strsub.c \
		 ft_isdigit.c \
		 ft_lstiter.c \
		 ft_memcpy.c \
		 ft_putendl_fd.c \
		 ft_putwchar.c \
		 ft_strcpy.c \
		 ft_strlcat.c \
		 ft_strnequ.c \
		 ft_strtolower.c \
		 ft_putnchar.c \
		 ft_wstrlen.c \
		 ft_wcharlen.c \
		 get_next_line.c \
		 ft_cconv.c \
		 ft_diconv.c \
		 ft_hexaconv.c \
		 ft_print_options.c \
		 ft_sconv.c \
		 ft_check_flags.c \
		 ft_ouconv.c \
		 ft_printf.c \
		 ft_tools.c \
		 ft_width_prec_decimal.c \
		 ft_wp_ws.c \
		 ft_doubletabfree.c \
		 ft_check_leaks.c \

SRCS = $(addprefix srcs/, $(SRCS_P))

CFLAGS = -Wall -Werror -Wextra
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
	@echo "$(GREEN)✓$(NC)$(CL) Objects of $(NAME) compiled$(NC)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)✓$(NC)$(CL) library $(NAME) built$(NC)"

%.o: %.c
	@$(CC) -c $< -o $@ -I$(HEADER) $(CFLAGS)

clean:
	@rm -Rf $(OBJ)
	@echo "$(RED)x$(NC)$(CL2) Objects of $(NAME) cleaned"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(RED)x$(NC)$(CL2) Library $(NAME) cleaned"

re: fclean all
