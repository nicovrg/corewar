# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:51:03 by nivergne          #+#    #+#              #
#    Updated: 2020/02/11 01:11:03 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean:
	@make -C libft clean
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYAN)$(BOLD)COREWAR			$(BLUE)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(ASM) $(VM)