

OS							  = $(shell uname -s)

ifeq ($(OS), Linux)
		PRINT = @echo -ne
endif
ifeq ($(OS), Darwin)
		PRINT = @printf
endif

# SOURCES
LIST_SRCS	 = main.c												\
			ft_parsing.c

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))
SRCS  = ${addprefix ${DIR_SRC}, ${LIST_SRCS}}

# DIRECTORIES
DIR_OBJS = .objs/
DIR_INCLUDE = include/
DIR_SRC = srcs/

# LIB
LIBFT   = -L ./libft -lft 

# VARIABLES
NAME	= cub3d
CC			  = cc
CFLAGS  = -Wall -Wextra -Werror -g3 #TODO remove g3
RM			  = rm -rf
MAKEFLAGS += --no-print-directory

# COLORS
RED			 = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
DEFAULT = \033[0m
SUPPR   = \r\033[2K

# COMPILATION
all :		   ${NAME}

${DIR_OBJS}%.o: %.c	 ${DIR_INCLUDE}cub3d.h Makefile
						@mkdir -p $(shell dirname $@)
						@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
						@${CC} ${CFLAGS} -I ./libft/headers -I ${DIR_INCLUDE} -c $< -o $@ 

${NAME}:		ascii lib ${OBJS}
						@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
						@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
						@${CC} ${OBJS} -o ${NAME} ${LIBFT}
						@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

lib :
						@make -C ./libft

ascii :
						@${PRINT} "$$ASCII"

clean :		 ascii
						@${PRINT} "${RED}Deleting objects : DONE\n"
						@${RM} ${DIR_OBJS}

fclean :		clean 
						@${PRINT} "${RED}Cleaning libft : DONE\n"
						@${MAKE} fclean -C ./libft
						@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n\n"
						@${RM} ${NAME} 

re :			fclean all

define ASCII
${CYAN}
 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ 
██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ 
${DEFAULT}

endef
export ASCII

.PHONY : all re clean fclean lib ascii