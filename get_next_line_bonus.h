/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdazero <abdazero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:49:39 by abdazero          #+#    #+#             */
/*   Updated: 2025/12/04 22:02:48 by abdazero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *str, int c);
char	*ft_gnl_strdup(const char *src);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(const char *str, unsigned int start, size_t len);

#endif