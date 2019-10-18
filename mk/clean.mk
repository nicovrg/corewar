# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:51:03 by nivergne          #+#    #+#              #
#    Updated: 2019/10/18 19:24:13 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean:
	@make -C libft clean
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYA)$(BOL)LEMIN			$(BLU)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)