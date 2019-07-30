/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:33:41 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/30 10:23:25 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*sorted_merge(t_dir *a, t_dir *b, int flags)
{
	t_dir	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = sorted_merge(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = sorted_merge(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, flags);
	}
	return (result);
}

t_dir	*sorted_merge_t(t_dir *a, t_dir *b, int flags)
{
	t_dir	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && (a->time > b->time))
	{
		result = a;
		result->next = sorted_merge_t(a->next, b, flags);
	}
	else if ((flags & 8) && (a->time < b->time))
	{
		result = a;
		result->next = sorted_merge_t(a->next, b, flags);
	}
	else if (a->time == b->time)
		check_nano(flags, a, b, &result);
	else
	{
		result = b;
		result->next = sorted_merge_t(a, b->next, flags);
	}
	return (result);
}

void	merge_sort(t_dir **head_ref, int flags)
{
	t_dir	*head;
	t_dir	*a;
	t_dir	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	if (flags & 128)
	{
		rev_lst(head_ref);
		return ;
	}
	front_back_sort(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	if (flags & 16)
		*head_ref = sorted_merge_t(a, b, flags);
	else
		*head_ref = sorted_merge(a, b, flags);
}

void	front_back_sort(t_dir *source, t_dir **front_ref, t_dir **back_ref)
{
	t_dir	*fast;
	t_dir	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	check_nano(int flags, t_dir *a, t_dir *b, t_dir **result)
{
	if (!(flags & 8) && (a->nano > b->nano))
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else if ((flags & 8) && (a->nano < b->nano))
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else if (a->nano == b->nano)
		sort_nano_ascii(flags, a, b, result);
	else
	{
		*result = b;
		(*result)->next = sorted_merge_t(a, b->next, flags);
	}
}
