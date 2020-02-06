void	ft_putnbr(int nbr);
void	ft_putchar(char c);

void	ft_print_iarray(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		if (!(i % 10) && i)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
