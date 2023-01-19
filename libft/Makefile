NAME = libft.a

FT_PRINTF = ./ft_printf

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_reverse.c \

SOURCES_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \ 

SOURCES_PRINTF = ./ft_printf/ft_printf_c.c ./ft_printf/ft_printf_s.c ./ft_printf/ft_printf_p.c ./ft_printf/ft_printf_d.c ./ft_printf/ft_printf_i.c \
	./ft_printf/ft_printf_u.c ./ft_printf/ft_printf_x.c ./ft_printf/ft_printf_X.c ./ft_printf/ft_printf.c ./ft_printf/ft_strlen.c ./ft_printf/ft_putnbr_base.c \
	./ft_printf/ft_putnbr_base_p.c \

SOURCES_GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

SOURCES_GNL_BONUS = ./get_next_line_bonus/get_next_line_bonus.c ./get_next_line_bonus/get_next_line_utlis.c \

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

OBJECTS_PRINTF = $(SOURCES_PRINTF:.c=.o)

OBJECTS_GNL = $(SOURCES_GNL:.c=.o)

OBJECTS_GNL_BONUS = $(SOURCES_GNL_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

all: $(NAME)

clean: 
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f $(OBJECTS_PRINTF)
	rm -f $(OBJECTS_GNL)
	rm -f $(OBJECTS_GNL_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.a

re: fclean all

lst: $(OBJECTS_BONUS)
	ar -r $(NAME) $(OBJECTS_BONUS)

printf: $(OBJECTS_PRINTF)
	ar crs libftprintf.a $(OBJECTS_PRINTF)

gnl: $(OBJECTS_GNL)
	$(CC) $(CFLAGS) $(OBJECTS_GNL) -o gnl.exe

gnl_bonus: $(OBJECTS_GNL_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_GNL_BONUS) -o gnl_bonus.exe 

.PHONY: all clean fclean re printf gnl gnl_bonus