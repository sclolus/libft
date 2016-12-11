/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:04:34 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/11 18:04:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fd_data
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	*current;
}				t_fd_data;

t_list			*ft_goto_fd_lst(int fd, t_list *lst);
int				get_next_line(const int fd, char **line);
int				ft_get_buf(int fd, t_fd_data *content);
int				ft_join_line(char **line, t_fd_data *current_buf);
int				ft_get_line(const int fd, char **line, t_fd_data *content);
#endif
