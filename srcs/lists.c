/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:09:38 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/05 12:36:48 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*set_list(const char *name)
{
	t_dir *new;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = (char *)malloc(ft_strlen(name))))
	{
		free(new);
		return (NULL);
	}
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	delete_list(t_dir **list)
{
	t_dir *current = *list;
	t_dir *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

void	list_add(t_dir **alst, const char *name)
{
	t_dir *new;

	new = set_list(name);
	new->next = *alst;
	*alst = new;
}

void	print_list(t_dir *list, unsigned char flags)
{
	t_dir *ptr;
	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(ptr->name);
			ft_putchar('\t');
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putstr(ptr->name);
				ft_putchar('\t');
			}
			ptr = ptr->next;
		}
	}
}