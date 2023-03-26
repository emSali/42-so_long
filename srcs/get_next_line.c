/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2023/03/26 17:00:46 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
//while loop into extra function
char	*get_next_line(int fd)
{
	static char	save_file[1];
	char		*ret;

	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ret = gnl(ret, save_file, fd);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*gnl(char *ret, char *save_file, int fd)
{
	char	*tmp;
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, save_file, 1);
		save_file[i] = '\0';
		if (i == -1) //error
			return (NULL);
		if (i == 0) //end of file
			break ;
		tmp = ret;
		ret = concat(ret, save_file); // adds save file to ret
		free(tmp);
	}
	return (ret);
}

//concatinates 2 strings until \n
char	*concat(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = cpy_ret(ret, s1);
	j = 0;
	while (s2[j] != 0)
	{
		ret[i] = s2[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

//ONly used for concatinating string! copies s1 into ret and returns amout of characters copied
int	cpy_ret(char *ret, char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	return (i);
}
