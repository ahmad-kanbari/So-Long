# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 16:31:11 by akanbari          #+#    #+#              #
#    Updated: 2023/11/16 22:33:53 by akanbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror -I.
# -Wall (enable all compiler warnings), -Wextra (enable extra compiler warnings), -Werror (treat warnings as errors), and -I. (include the current directory).

SRCS_CHECKERS	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_is_prime.c ft_isblank.c ft_iscntrl.c ft_isgraph.c  \
					ft_isprint.c ft_isspace.c ft_find_next_prime.c ft_ishexdigit.c ft_ispunct.c ft_isspace.c ft_isstrnbr.c \
					ft_sqrt.c 
					
SRCS_GNL		= get_next_line_bonus.c get_next_line_utils_bonus.c \
					get_next_line.c get_next_line_utils.c

SRCS_LISTS		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
					ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
					ft_lstsize.c ft_lstadd_back_cmp.c ft_lstadd_front_cmp.c \
					ft_lstadd_pos.c ft_lstdelcont.c ft_lstdelelem.c ft_lstdelpos.c ft_lstget.c \
					ft_lstiter_param.c ft_lstprint.c ft_lstreverse.c ft_lstsort.c ft_lstswap_cont.c \
					ft_list_remove_if.c ft_strndup.c


SRCS_MEMORY		=   ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memmove.c ft_memset.c ft_print_bits.c ft_malloc.c \
					
SRCS_PRINT_FUNCS	= ft_putchar_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_putstr_fd.c \
					ft_putnbr_base_fd.c

SRCS_PRINTF =	ft_print_address.c ft_print_hex_big.c ft_print_hex_small.c \
				ft_printf.c ft_printnbr_base.c ft_putchar_fd.c ft_putnbr_fd.c \
				ft_putnbr_unsigned.c ft_putstr_fd.c ft_strlen.c

SRCS_ARRAY = ft_abs.c ft_arrfree.c ft_arrlen.c ft_sort_int_tab.c \
				ft_swap.c ft_abs.c ft_max.c


SRCS_STRING	= 		ft_atoi.c ft_itoa.c ft_split.c ft_split2.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_striteri.c \
					ft_strjoin.c ft_atoi_base.c ft_strlcat.c ft_strcapitalize.c ft_strcat.c \
					ft_strlcpy.c ft_strcmp_insensitive.c ft_strcmp.c ft_strcpy.c ft_strdup_n.c \
					ft_strlen.c ft_strjoin_delim.c ft_strnjoin.c ft_strreps.c \
					ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
					ft_substr.c ft_tolower.c ft_toupper.c first_word.c ft_swap.c ft_search_replace.c \
					ft_strcspn.c ft_strpbrk.c ft_strspn.c	ft_last_word.c ft_str_capitalizer.c \
					ft_strlen_c.c \

CC = cc
RM = rm -f
NAME = libft.a
AR =  ar rcs
# ranlib is a utility used to generate an index for a static library 
#(.a file) created with ar. The index, sometimes called the "table of contents," 
#makes it faster to look up and link against symbols in the library.
LIB = ranlib
SRCF = ./src/
SRCF_CHECK = $(SRCF)checkers/
SRCF_GNL   = $(SRCF)get_next_line/
SRCF_ARRAY = $(SRCF)array/
SRCF_LIST = $(SRCF)linked_lists/
SRCF_MEMORY = $(SRCF)memory/
SRCF_PRINT = $(SRCF)print_funcs/
SRCF_PRINTF = $(SRCF)printf/
SRCF_STR = $(SRCF)string/

SRC_CHECKERS = $(addprefix $(SRCF_CHECK), $(SRCS_CHECKERS))
SRC_GNL      = $(addprefix $(SRCF_GNL), $(SRCS_GNL))
SRC_LIST 	 = $(addprefix $(SRCF_LIST), $(SRCS_LISTS))
SRC_MEMORY 	 = $(addprefix $(SRCF_MEMORY), $(SRCS_MEMORY))
SRC_PRINT_FUNCS 	 = $(addprefix $(SRCF_PRINT), $(SRCS_PRINT_FUNCS))
SRC_STRING 	  		= $(addprefix $(SRCF_STR), $(SRCS_STRING))
SRC_PRINTF	  		= $(addprefix $(SRCF_PRINTF), $(SRCS_PRINTF))
SRC_ARRAY 	  		= $(addprefix $(SRCF_ARRAY), $(SRCS_ARRAY))

OBJS_CHECK		= $(SRC_CHECKERS:.c=.o)
OBJS_GNL		= $(SRC_GNL:.c=.o)
OBJS_LIST		= $(SRC_LISTS:.c=.o)
OBJS_MEMORY		= $(SRC_MEMORY:.c=.o)
OBJS_PRINT		= $(SRC_PRINT_FUNCS:.c=.o)
OBJS_PRINTF		= $(SRC_PRINTF:.c=.o)
OBJS_STRING		= $(SRC_STRING:.c=.o)
OBJS_ARRAY		= $(SRC_ARRAY:.c=.o)

INCLUDES			= ./includes/

all: $(NAME)
	
$(NAME): $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING) $(OBJS_PRINTF) $(OBJS_ARRAY)
	@echo "Creating the FULL Libft"
	$(AR) $(NAME) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING) $(OBJS_PRINTF) $(OBJS_ARRAY)
	@$(LIB) $(NAME)
	@echo "FULL LIBFT is Ready"

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

norm : ${SRCS_CHECKERS} ${SRCS_GNL} ${SRCS_LISTS} ${SRCS_MEMORY} ${SRCS_PRINT_FUNCS} ${SRCS_PRINTF} $(SRCS_ARRAY) $(SRCS_STRING)
	norminette -R CheckForbiddenSourceHeader ${SRCS_CHECKERS} ${SRCS_GNL} ${SRCS_LISTS} ${SRCS_MEMORY} ${SRCS_PRINT_FUNCS} ${SRCS_PRINTF} $(SRCS_ARRAY) $(SRCS_STRING)
	norminette -R CheckDefine *.h

check: $(OBJS_CHECK)
	@echo "Creating the Libft with checker functions"
	$(AR) $(NAME) $(OBJS_CHECK)
	$(LIB) $(NAME)
	@echo "LIBFT with Checkers Function is Ready"


gnl: $(OBJS_GNL) 
	@echo "Creating the Libft with Get NEXT LINE "
	$(AR) $(NAME) $(OBJS_GNL)
	$(LIB) $(NAME)
	@echo "LIBFT with get_next_line Function is Ready"


list: $(OBJS_LIST) $(OBJS_PRINTF)
	@echo "Creating the Libft with Linked Lists functions"
	$(AR) $(NAME) $(OBJS_LIST) $(OBJS_PRINTF)
	$(LIB) $(NAME)
	@echo "LIBFT with linked lists Functions is Ready"


memory: $(OBJS_MEMORY)
	@echo "Creating the Libft with Memory Functions"
	$(AR) $(NAME) $(OBJS_MEMORY)
	$(LIB) $(NAME)
	@echo "LIBFT with Memory Functions is Ready"


print: $(OBJS_PRINT) $(OBJS_STRING)
	@echo "Creating the Libft with print Functions"
	@$(AR) $(NAME) $(OBJS_PRINT) $(OBJS_STRING)
	@$(LIB) $(NAME)
	@echo "LIBFT with print Functions is Ready"


printf: $(OBJS_PRINTF)
	@echo "Creating the Libft with Printf"
	$(AR) $(NAME) $(OBJS_PRINTF)
	$(LIB) $(NAME)
	@echo "LIBFT with Printf Function is Ready"

string: $(OBJS_STRING)
	@echo "Creating the Libft with strings manipulation functions"
	$(AR) $(NAME) $(OBJS_STRING)
	$(LIB) $(NAME)
	@echo "LIBFT with strings manipulation Functions is Ready"

array : $(OBJS_ARRAY)
	@echo "Creating the Libft with array manipulation and math functions"
	$(AR) $(NAME) $(OBJS_ARRAY)
	$(LIB) $(NAME)
	@echo "LIBFT with array manipulation and math Functions is Ready"
	
clean:
	@echo "Deleting All the object files"
	@$(RM) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEMORY) $(OBJS_PRINT) $(OBJS_STRING) $(OBJS_PRINTF) $(OBJS_ARRAY)
	@echo "All files Deleted Successfully"

fclean: clean
	@echo "Deleting the library"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re check gnl list memory print string printf array
