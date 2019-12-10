# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 19:23:29 by nivergne          #+#    #+#              #
#    Updated: 2019/11/27 03:34:53 by nicolasv         ###   ########.fr        #
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

all: $(ASM) debug

# all: $(ASM) $(VM) 

$(ASM): $(OBJ_ASM) | makelib
	@echo "$(BOLD)$(GREEN)ASM			$(BLUE)compile$(GREEN)		[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ_ASM) -L libft -lft -o $(ASM)

$(VM): $(OBJ_VM) | makelib
	@echo "$(BOLD)$(GREEN)VM			$(BLUE)compile$(GREEN)		[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ_VM) -L libft -lft -o $(VM)
	
makelib:
	@$(MAKE) -C libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@mkdir -p $(dir $@)
	@echo "$(patsubst obj/%, %, $(basename $@))"	
	@echo "$(BOLD)$(CYAN)corewar		$(BLUE)$(patsubst obj/%, %, $(basename $@))	$(GREEN)[OK]$(END)"	
	@printf "$(UP_LINE)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PATH) -o $@ -c $<
	@printf "$(ERASE_LINE)"

include mk/bitcoin.mk
include mk/debug.mk
include mk/clean.mk

re: fclean all

.PHONY: all clean fclean re makelib g3 fsanitize bitcoin minotaure bitcoin_autore

-include $(DEPS)
