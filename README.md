# corewar

==================== processeur 16bits ====================
	char				1
	int					2
==================== processeur 32bits ====================
	char				1
	short int			2
	long int			4
==================== processeur 64bits ====================
	char				1
	short int			2
	long int			4
	long long int		8


 ==================== steven tricks ====================
    c_line[0]->nb_line = index;
    (*(c_line)->nb_line = index;
    (*(c_line + 0))->nb_line = index;
    (*(*c_line)).nb_line = index;
    (**c_line).nb_line = index;
    c_line[0][0].nb_line = index
    memcpy(&b, &a, sizeof(int));
