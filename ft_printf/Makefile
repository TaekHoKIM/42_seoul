NAME = libftprintf.a
SOURCE_FILES =			./ft_printf.c						\
						./ft_printf_utils1.c				\
						./ft_printf_utils2.c				
OBJECT_FILES = ${SOURCE_FILES:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJECT_FILES}
	ar rsc $@ ${OBJECT_FILES}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJECT_FILES}

fclean :
	make clean
	rm -rf ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re