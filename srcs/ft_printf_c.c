/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:49 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 16:39:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_c_conditionning(t_value_printf *value_printf, int l, \
	char c)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup("");
	post_value = ft_strdup("");
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	ft_putstr(pre_value);
	ft_putchar(c);
	ft_putstr(post_value);
	free(pre_value);
	free(post_value);
	return (l);
}

static int	ft_printf_c_l(t_value_printf *value_printf, wint_t c)
{
	(void)value_printf;
	ft_putwchar(c);
	return (0);
}

int	ft_printf_c(t_value_printf *value_printf, va_list *arg)
{
	char	c;

	if (ft_strcmp(value_printf->length, "l") == 0)
	{
		if (arg == NULL)
			return (ft_printf_c_l(value_printf, (wint_t) '%'));
		else
			return (ft_printf_c_l(value_printf, va_arg(*arg, wint_t)));
	}
	if (arg == NULL)
		c = '%';
	else
		c = (char)va_arg(*arg, int);
	return (ft_printf_c_conditionning(value_printf, 1, c));
}