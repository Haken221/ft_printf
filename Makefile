# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 11:46:04 by dduchang          #+#    #+#              #
#    Updated: 2022/07/10 15:20:08 by dduchang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

# output (EXEC)
NAME	= libftprintf.a

# sources
INC			=	-I includes/
SRC_DIR 	=	srcs/
OBJ_DIR 	=	obj/

SRC_FILES	=	ft_printf \
				ft_printf_utils \
				main \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	.cache_exists

# compilation
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# extra
AR	= ar rcs
RM	= rm -rf

# colors
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
RED			= \033[0;31m
END_COLOR	= \033[0;39m

# **************************************************************************** #
# RULES

all:		$(NAME)

$(NAME): 	$(OBJ)
ifdef LIB
			@$(MAKE) -C $(LIB)
			@cp $(LIB)*.a $(NAME)
endif
			@$(AR) $@ $(OBJ)
			@echo "$(GREEN)$@ compiled 🥳$(END_COLOR)"
			@$(CC) $(CFLAGS) $@ -o test.out						#SUPPRIMER AVANT PUSH#
			@echo "$(GREEN)test.out compiled 🥳$(END_COLOR)"	#SUPPRIMER AVANT PUSH#


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(END_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

# cleaning
clean:
	@$(RM) test.out												#SUPPRIMER AVANT PUSH#
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)$(OBJ_DIR) successfully removed!$(END_COLOR)"
ifdef LIB
	@$(MAKE) clean -C $(LIB)
endif

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)$(NAME) successfully removed!$(END_COLOR)"
ifdef LIB
	@$(MAKE) fclean -C $(LIB)
endif
	@echo "$(GREEN)All clean. 🧹$(END_COLOR)"

re:		fclean all
	@echo "$(BLUE)Cleaned and rebuilt. 💪$(END_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re
