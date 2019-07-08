##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my project lemin
##

ROOT			=	.

MAIN 			= 	main

NAME			=	mysh

INCLUDE			= 	include

CC				= 	gcc

RM 				= 	rm

TYPE 			=	.c

SRC_DIR			=	$(addprefix $(ROOT)/, src)

BUILD			=	$(ROOT)/obj

SRC_PREFIX 		= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC				= 	$(addsuffix $(TYPE), $(SRC_PREFIX))

OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))

SRC_FILES		=	my_calloc			\
					env					\
					error				\
					my_exit				\
					my_get_nbr			\
					my_strlen_str		\
					error_env			\
					my_getenv			\
					my_cd				\
					my_path				\
					my_prompt			\
					my_setenv			\
					my_shell			\
					my_strcalloc		\
					my_unsetenv 		\
					treat_command 		\
					treat_command_next	\
					my_macro			\
					read_files			\
					$(MAIN)

WARN			=	-W -Wall $(WERROR)

WERROR			= 	-Werror

CFLAGS			=	-I $(ROOT)/$(INCLUDE) $(WARN) -g3

DEBUG 			= 	@


#COLORS

GREEN 			=	\e[1;32m
WHITE			=	\e[0m
ORANGE			=	\e[1;33m
RED				=	\e[1;31m
BLUE			=	\e[1;34m
YELLOW			=	\e[1;93m


all:				$(NAME)

$(NAME):			echo_start $(BUILD)/$(NAME)
					$(DEBUG)cp $(BUILD)/$(NAME) $(ROOT)
					$(DEBUG)printf "$(ORANGE)Successful to copy binary into root directory.\n$(WHITE)"

$(BUILD)/$(NAME):	$(OBJS)
					$(DEBUG)printf "$(ORANGE)Compile sources.$(WHITE)\n"
					$(DEBUG)$(CC) -o $(BUILD)/$(NAME) $(OBJS)
					$(DEBUG)printf "$(ORANGE)Start link obj and libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.c
					$(DEBUG)printf "$(ORANGE)Compiling$(WHITE)[$(YELLOW)$(notdir $<)$(WHITE)]$(RED)->$(WHITE)[$(YELLOW)$(notdir $@)$(WHITE)]\n"
					$(DEBUG)$(CC) -o $@ -c $< $(CFLAGS)

echo_start:	
					$(DEBUG)mkdir -p obj
					$(DEBUG)printf "$(RED)Start the compilation:\n$(WHITE)"

clean:	
					$(DEBUG)$(RM) -rf $(OBJS)
					$(DEBUG)$(RM) -rf $(BUILD)
					$(DEBUG)printf "$(ORANGE)Delete object files.$(WHITE)\n"

fclean:	clean
					$(DEBUG)$(RM) -f $(BUILD)/$(NAME)
					$(DEBUG)$(RM) -f $(ROOT)/$(NAME)
					$(DEBUG)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:					fclean
					$(DEBUG)make --no-print-directory all

.PHONY: clean fclean all re echo_start
