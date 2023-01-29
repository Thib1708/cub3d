# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 11:01:27 by tgiraudo          #+#    #+#              #
#    Updated: 2023/01/28 11:06:19 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS							  = $(shell uname -s)

ifeq ($(OS), Linux)
		PRINT = @echo -ne
endif
ifeq ($(OS), Darwin)
		PRINT = @printf
endif

# SOURCES
SRCS	=	libft/ft_strlen.c \
			libft/ft_isalpha.c \
			libft/ft_isalnum.c \
			libft/ft_isprint.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_bzero.c \
			libft/ft_memset.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strncmp.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_memchr.c \
			libft/ft_atoi.c \
			libft/ft_memcmp.c \
			libft/ft_strnstr.c \
			libft/ft_split.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstmap_bonus.c \
\
			get_next_line/get_next_line.c				\
			get_next_line/get_next_line_utils.c			\
			get_next_line/get_next_line_bonus.c			\
			get_next_line/get_next_line_utils_bonus.c	\
\
			printf/ft_printf_utils_2.c	\
			printf/ft_printf_utils.c	\
			printf/ft_printf.c

DIR_OBJS = .objs/
OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

# VARIABLES
NAME	= libft.a
CC			  = cc
CFLAGS  = -Wall -Wextra -Werror
RM			  = rm -rf
INCLUDES                = -I ${HEADERS_PATH}

HEADERS_PATH = headers/

HEADERS =       ${HEADERS_PATH}ft_printf.h \
                        ${HEADERS_PATH}get_next_line.h \
                        ${HEADERS_PATH}get_next_line_bonus.h \
                        ${HEADERS_PATH}libft.h

# COMPILATION
all :		   ${NAME}

${DIR_OBJS}%.o :  %.c   ${HEADERS} Makefile
								@mkdir -p $(shell dirname $@)
								@${PRINT} "${YELLOW}${SUPPR}Creating libft's objects : $@"
								@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}:		${OBJS}
						@${PRINT} "${GREEN}${SUPPR}Creating libft's objects : DONE\n"
						@${PRINT} "${YELLOW}Compiling libft... ${DEFAULT}"
						@ar rc ${NAME} ${OBJS}
						@${PRINT} "${GREEN}${SUPPR}Compiling libft : DONE ${DEFAULT}\n"

clean :
						@${RM} ${DIR_OBJS}

fclean :		clean
						@${RM} ${NAME} 

re :			fclean all

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
SUPPR = \r\033[2K
MAKEFLAGS += --no-print-directory

.PHONY : all re clean fclean