#include <unistd.h>

void	ft_putstr(char const *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/*
**	int	main(void)
**	{
**		ft_putstr("Hello World !\n");
**		return (0);
**	}
*/
