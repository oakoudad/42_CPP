#include <iostream>

int	main(int ac, char **av)
{
	int			i;
	int			j;
	std::string s;

	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	i = 1;
	while (i < ac)
	{
		s = av[i];
		j = 0;
		while (s[j])
			std::cout << (char)std::toupper(s[j++]);
		i++;
	}
	std::cout << "\n";
}