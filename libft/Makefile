SRCS	=		atoi_limit.c\
				bool_strchr.c\
				change_char.c\
				format_check.c\
				free_char_p2p.c\
				ft_memccpy.c\
				ft_memset.c\
				ft_strncmp.c\
				ft_bzero.c\
				ft_memchr.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_isalnum.c\
				ft_memcmp.c\
				ft_strlcat.c\
		 		ft_isdigit.c\
				ft_memmove.c\
				ft_strlen.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_memcpy.c\
				ft_strlcpy.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_split.c\
				ft_lstnew.c\
				ft_lstdelone.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				ft_lstsize.c\
				ft_lstclear.c\
				ft_lstmap.c\
				ft_listiter.c\
				ft_strcmp.c\
				ft_pf_atoi.c\
				ft_strstr.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putchar.c\
				get_next_line.c\
		  		get_next_line_utils.c\
				is_tab_digit.c\
				count_lines.c\
				longest_line.c\
				str_isdigit.c\
				wrmalloc.c

BON_SRCS 	=	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c

OBJS		= 	$(SRCS:.c=.o)

BON_OBJS	= 	$(BON_SRCS:.c=.o)

NAME		= 	libft.a

HEADER_FILE	=	/libft.h

CC			= 	clang

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -g3

%.o: 			%.c $(HEADER_FILE)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BON_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(BON_OBJS) $(OBJS)
				ar rcs $(NAME) $(OBJS) $(BON_OBJS)

.PHONY:			all clean fclean re
