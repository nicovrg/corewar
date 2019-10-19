# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:51:03 by nivergne          #+#    #+#              #
#    Updated: 2019/10/20 00:42:26 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean:
	@make -C libft clean
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYA)$(BOL)COREWAR			$(BLU)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)