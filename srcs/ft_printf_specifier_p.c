/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:16:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:06 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_p_conditionning_2(t_value_printf *value_printf, \
	unsigned long long p, char ***value)
{
	int	l;

	l = ft_getlen_ull(p, 16) + 2;
	if (p == 0 && value_printf->precision == 0 && \
		value_printf->is_precision == 1)
		l--;
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l >= 0)
	{
		ft_putstr((*value)[0]);
		if (p != 0 || value_printf->precision != 0 || \
			value_printf->is_precision != 1)
			ft_putnbr_hex(p, 0);
		ft_putstr((*value)[1]);
	}
	return (l);
}

static int	ft_printf_p_conditionning_1(t_value_printf *value_printf, \
	unsigned long long p)
{
	char	*tmp;
	char	**value;
	int		l;

	tmp = ft_strdup("0x");
	if (!tmp)
		return (-1);
	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	free(value[0]);
	value[0] = tmp;
	l = ft_printf_p_conditionning_2(value_printf, p, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_p(t_value_printf *value_printf, va_list *arg)
{
	return (ft_printf_p_conditionning_1(value_printf, \
		va_arg(*arg, unsigned long long)));
}
