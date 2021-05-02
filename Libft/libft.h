/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:28:11 by ybouddou          #+#    #+#             */
/*   Updated: 2021/04/27 10:45:43 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlen(const char *s);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isexist(char *s, char c);
int					ft_atoi(const char *s);
void				*ft_memset(void *s, int c, size_t len);
void				ft_bzero(void *s, size_t len);
char				*ft_strdup(const char *s1);

typedef struct s_var
{
	int				i;
	char			*s;
	char			*token;
	char			pr;
	int				skip;
	int				words;
	char			**splt;
	char			dq;
	char			q;
	int				end;
}					t_var;

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				**ft_strsplit(char *s, char *c, int skip);
int					exist(t_var *var);
void				skipping(t_var *var);
char				*ft_itoa(int n);

#endif
