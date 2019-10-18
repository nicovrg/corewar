# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    debug.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:50:50 by nivergne          #+#    #+#              #
#    Updated: 2019/09/22 23:50:50 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

g3: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)debug$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) -g3 $(OBJ) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)fsanitize$(GRN)	[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) -g3 -fsanitize=address $(OBJ) $(MLX) -L libft -lft -o $(NAME)_fsanitize