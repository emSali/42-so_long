#include "solong.h"

void print_map(char **map)
{
	int i = 0;

	while (map[i] != NULL) {
		ft_printf("\n%i: %s", i, map[i]);
		i++;
	}


}
