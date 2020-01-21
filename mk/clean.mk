# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:51:03 by nivergne          #+#    #+#              #
#    Updated: 2020/01/22 00:50:16 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean:
	@make -C libft clean
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYAN)$(BOLD)COREWAR			$(BLUE)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(ASM) $(VM)