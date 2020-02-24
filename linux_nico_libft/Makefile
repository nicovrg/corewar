# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 12:42:57 by nivergne          #+#    #+#              #
#    Updated: 2019/10/09 07:39:23 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

include mk/src.mk
include mk/colors.mk

PATH_INC := include
PATH_LIB := src
PATH_OBJ := obj

SRC_DIR_LIBFT := $(shell (find $(PATH_LIB) -maxdepth 1 -type d))
OBJ_DIR_LIBFT := $(subst $(PATH_LIB),$(PATH_OBJ),$(SRC_DIR_LIBFT))

SRC_LIBFT := $(addprefix $(PATH_LIB)/, $(SRC_LIBFT))
OBJ_LIBFT := $(addprefix $(PATH_OBJ)/, $(OBJ_LIBFT))

CC =						gcc
CFLAGS =					-Wall -Wextra -Werror
CPPFLAGS =					-MMD -MP -I $(PATH_INC)
DEPS =						$(subst .o,.d,$(OBJ))

all: $(NAME)

$(NAME): $(OBJ_LIBFT)
	@ar rcs $(NAME) $(OBJ_LIBFT)
	@echo "$(BOLD)$(CYAN)$(BOLD)LIBFT			$(BLUE)$(BOLD)compile		$(GREEN)[OK]$(END)"

$(PATH_OBJ)/%.o: $(PATH_LIB)/%.c | create_directories
	@echo "$(BOLD)$(CYAN)libft		$(BLUE)$(patsubst obj/%, %, $(basename $@))	$(GREEN)[OK]$(END)"
	@printf "$(UP_LINE)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE_LINE)"

create_directories:
	mkdir -p $(OBJ_DIR_LIBFT)

clean:
	@rm -rf $(OBJ_LIBFT) $(OBJ_PRINTF)
	@echo "$(BOLD)$(CYAN)LIBFT$(BLUE)			obj		$(END)$(RED)[delete]$(END)"
	@echo "$(BOLD)$(CYAN)PRINTF$(BLUE)			obj		$(END)$(RED)[delete]$(END)"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "$(BOLD)$(CYAN)LIBFT$(BLUE)			lib		$(END)$(RED)[delete]$(END)"
	
re: fclean all

.PHONY: all clean fclean re norme

include mk/bitcoin.mk
include mk/debug.mk

-include $(DEPS)
