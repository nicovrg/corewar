# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 19:23:29 by nivergne          #+#    #+#              #
#    Updated: 2019/10/20 01:00:22 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM	= asm
VM	= corewar

include mk/include.mk
include mk/src.mk
include mk/obj.mk
include mk/colors.mk

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS += -MMD -MP
LIB = libft/libft.a
DEPS = $(subst .o,.d,$(OBJ))

all: $(ASM) $(VM)

$(ASM): $(OBJ_ASM) | makelib
	@echo "$(BOLD)$(CYAN)ASM		$(BLUE)$(patsubst obj/%, %, $(basename $@))	$(GREEN)[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ_ASM) -L libft -lft -o $(NAME)

$(VM): $(OBJ_VM) | makelib
	@echo "$(BOLD)$(CYAN)VM		$(BLUE)$(patsubst obj/%, %, $(basename $@))	$(GREEN)[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ_VM) -L libft -lft -o $(NAME)


makelib:
	@$(MAKE) -C libft

obj/%.o: src/%.c
	@mkdir -p obj
	@mkdir -p $(dir $@)
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PATH) -o $@ -c $<
	@printf "\33[2K"

include mk/bitcoin.mk
include mk/debug.mk
include mk/clean.mk

re: fclean all

.PHONY: all clean fclean re makelib g3 fsanitize bitcoin minotaure bitcoin_autore

-include $(DEPS)
