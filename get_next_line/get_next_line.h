/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:46:38 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/24 19:56:40 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_node
{
	int				fd;
	char			*content;
	ssize_t			len;
	ssize_t			idx;
	struct s_node	*next;
}	t_temp;

char	*get_next_line(int fd);
t_temp	*new_node(int fd);
int		content_change(t_temp *node);
void	*remove_target(t_temp **start, t_temp *target, char *restr);
t_temp	*current_temp(t_temp *start, int fd);
char	*substr(char *s, ssize_t start, ssize_t len);
size_t	check_next(char *s, ssize_t idx, ssize_t len);
char	*ft_strcat(char *s1, char *s2);
int		check(t_temp **start, t_temp *c_node, char *restr);
char	*result(t_temp *c_node, t_temp **start, char *restr);

#endif