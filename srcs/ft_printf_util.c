/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:34:50 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/14 13:22:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_init_value_lst(t_value_printf *value_printf)
{
	value_printf->flags = ft_strdup("");
	if (!value_printf->flags)
		return (-1);
	value_printf->width = 0;
	value_printf->precision = 0;
	value_printf->length = NULL;
	value_printf->specifier = '\0';
	return (0);
}

char	*ft_straddcharendstr(const char *s, char const c)
{
	char			*res;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (0);
	len = ft_strlen(s) + 2;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	i = -1;
	while (s[++i] != '\0')
		res[i] = s[i];
	res[i++] = c;
	res[i] = '\0';
	return (res);
}
