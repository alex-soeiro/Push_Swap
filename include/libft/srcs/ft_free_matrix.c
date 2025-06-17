#include "../include/libft.h"

void	ft_free_matrix(char **matrix)
{
	char	**matrix_ptr;

	matrix_ptr = matrix;
	while (*matrix)
		free(*(matrix++));
	free(matrix_ptr);
}
