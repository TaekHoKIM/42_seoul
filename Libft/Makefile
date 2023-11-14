NAME = libft.a
SOURCE_FILES =				./ft_atoi.c		\
							./ft_bzero.c		\
							./ft_calloc.c	\
							./ft_isalnum.c	\
							./ft_isalpha.c	\
							./ft_isascii.c	\
							./ft_isdigit.c	\
							./ft_isprint.c	\
							./ft_itoa.c		\
							./ft_memchr.c	\
							./ft_memcmp.c	\
							./ft_memcpy.c	\
							./ft_memmove.c	\
							./ft_memset.c	\
							./ft_putchar_fd.c\
							./ft_putendl_fd.c\
							./ft_putnbr_fd.c	\
							./ft_putstr_fd.c	\
							./ft_split.c		\
							./ft_strchr.c	\
							./ft_strdup.c	\
							./ft_striteri.c	\
							./ft_strjoin.c	\
							./ft_strlcat.c	\
							./ft_strlcpy.c	\
							./ft_strlen.c	\
							./ft_strmapi.c	\
							./ft_strncmp.c	\
							./ft_strnstr.c	\
							./ft_strrchr.c	\
							./ft_strtrim.c	\
							./ft_substr.c	\
							./ft_tolower.c	\
							./ft_toupper.c
OBJECT_FILES = ${SOURCE_FILES:.c=.o}
BONUS_FILES = 				./ft_lstnew.c		\
							./ft_lstadd_front.c	\
							./ft_lstsize.c		\
							./ft_lstlast.c		\
							./ft_lstadd_back.c	\
							./ft_lstdelone.c	\
							./ft_lstclear.c		\
							./ft_lstiter.c		\
							./ft_lstmap.c
BONUS_OBJECT_FILES = ${BONUS_FILES:.c=.o}
HEADER_FILES = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef FLAG
	OBJECT_FILES += ${BONUS_OBJECT_FILES}
endif

all : $(NAME)

$(NAME) : ${OBJECT_FILES}
	ar rsc $@ ${OBJECT_FILES}

%.o : %.c ${HEADER_FILES}
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	make all FLAG=1
	
clean :
	rm -f ${OBJECT_FILES} ${BONUS_OBJECT_FILES}

fclean :
	make clean
	rm -f ${NAME}

re : 
	make fclean
	make all

.PHONY : all clean fclean re
