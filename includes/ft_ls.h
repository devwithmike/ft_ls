/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/05 09:03:19 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "../libft/libft.h"
# include <dirent.h>

typedef struct	s_dir
{
	char *name;
	struct s_dir *next;
}				t_dir;

int				check_flags(char *str);
int				check_errors(char *path);
void	basic_print(struct dirent *de, unsigned char flags, DIR *dr);
void	recursive_print(struct dirent *de, unsigned char flags, char *path);
unsigned char	get_flags(int ac, char **av);
void			ft_ls(char *path, unsigned char flags);

#endif
