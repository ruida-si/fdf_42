/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <ruida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:29 by ruida-si          #+#    #+#             */
/*   Updated: 2024/12/27 15:19:23 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd, char **backup);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		count_wd(char *line);

#endif
