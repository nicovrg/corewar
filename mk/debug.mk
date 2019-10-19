# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    debug.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:50:50 by nivergne          #+#    #+#              #
#    Updated: 2019/10/20 00:42:21 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

g3: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)COREWAR			$(BLU)debug$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) -g3 $(OBJ) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)COREWAR			$(BLU)fsanitize$(GRN)	[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) -g3 -fsanitize=address $(OBJ) $(MLX) -L libft -lft -o $(NAME)_fsanitize