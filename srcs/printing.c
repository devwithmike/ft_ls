/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 14:56:35 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_list(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			printf("%hu\t%s\t%s\t%lld\t%s\n", ptr->nlink, ptr->uid, ptr->gid,
					ptr->size, ptr->name);
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				printf("%hu\t%s\t%s\t%lld\t%s\n", ptr->nlink, ptr->uid,
						ptr->gid, ptr->size, ptr->name);
			}
			ptr = ptr->next;
		}
	}
}

void	print_normal(t_dir *list, unsigned char flags)
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

void	print_output(t_dir *list, unsigned char flags)
{
	if (flags & 1)
		print_list(list, flags);
	else
		print_normal(list, flags);
}