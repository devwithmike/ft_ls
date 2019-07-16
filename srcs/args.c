/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:00:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/16 10:53:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sort_args(char **args)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((args[i] != NULL) &&  (args[i + 1] != NULL))
	{
		if (ft_strcmp(args[i], args[i + 1]) < 0 || 
			ft_strcmp(args[i], args[i + 1]) == 0)
			i++;
		else
		{
			tmp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = tmp;
		}
		
	}
}

void	add_args(char **args, int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			i++;
		else
			break ;
	}
	while (i < ac)
	{
		args[j] = av[i];
		i++;
		j++;
	}
	args[j] = NULL;
	sort_args(args);
}

int		execute_args(char **args, unsigned char flags)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (args[i] != NULL)
	{
		ft_ls(args[i], flags);
		check = 1;
		i++;
	}
	return (check);
}
