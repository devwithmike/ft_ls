/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:00:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 15:55:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sort_args(char **args, int ac)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < ac)
	{
		j = i;
		while (++j < ac)
			if (ft_strcmp(args[i], args[j]) != 0)
			{
				tmp = args[i];
				args[i] = args[j];
				args[j] = tmp;
			}
		i++;
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
		args[j++] = av[i++];
	args[j] = NULL;
	sort_args(args, j);
	return (j);
}

void	files_args(char **args, int flags, int ac)
{
	int i;

	i = -1;
	while (args[++i] != NULL)
		if (!(isdir(args[i])))
		{
			ft_ls(args[i], flags, ac);
			ft_putchar('\n');
		}
}

int		execute_args(char **args, int flags, int ac)
{
	int i;
	int check;

	check = 0;
	files_args(args, flags, ac);
	i = -1;
	while (args[++i] != NULL)
	{
		if (isdir(args[i]))
		{
			if (ac > 1 && !(flags & 4))
			{
				if ((args[i - 1] != NULL) && (i > 0))
					ft_putchar('\n');
				ft_putstr(args[i]);
				ft_putstr(":\n");
			}
			ft_ls(args[i], flags, ac);
		}
		check = 1;
	}
	return (check);
}
