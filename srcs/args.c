/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:00:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/19 10:31:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sort_args(char **args)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((args[i] != NULL) && (args[i + 1] != NULL))
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

int		add_args(char **args, int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if ((av[i][0] == '-') && (ft_strlen(av[i]) > 1) && (av[i][1] != '-'))
			i++;
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
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
	return(j);
}

int		execute_args(char **args, unsigned char flags, int ac)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (args[i] != NULL)
	{
		if (ac > 2)
		{
			ft_putstr(args[i]);
			ft_putstr(":\n");
		}
		ft_ls(args[i], flags);
		i++;
		if (i + 1 < ac)
			ft_putchar('\n');
		check = 1;
	}
	return (check);
}
