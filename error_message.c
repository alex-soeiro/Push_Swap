
#include "include/push_swap.h"
#include "include/libft/include/libft.h"

int	error_message(int error_code)
{
	if (error_code == 1)
	{
		ft_printf("error_code 1");
		return (1);
	}
	if (error_code == 2)
	{
		ft_printf("error_code 2");
		return (2);
	}
	if (error_code == 3)
	{
		ft_printf("error_code 3");
		return (3);
	}
	return (0);
}
