/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:09:38 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 13:17:24 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*set_list(const char *name)
{
	t_dir		*new;
	struct stat	sb;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	stat(name, &sb);
	new->name = ft_strdup(name);
	new->nlink = sb.st_nlink;
	new->uid = convert_un(sb.st_uid);
	new->gid = convert_gn(sb.st_gid);
	new->size = sb.st_size;
	new->next = NULL;
	return (new);
}

void	delete_list(t_dir **list)
{
	t_dir *current;
	t_dir *next;

	current = *list;
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

	(void)flags;

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

		// -l
		// printf("%hu\t%s\t%s\t%lld\t%s\n", ptr->nlink, ptr->uid, ptr->gid, ptr->size, ptr->name);
		// ptr = ptr->next;
	}
}
