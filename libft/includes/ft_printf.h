/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:26:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/07 23:10:54 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MASK "cspdiuxX%"

// Includes
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);

// ft_strutils
int	ft_printchar(void *cptr, int fd);
int	ft_printstr(void *strptr, int fd);
int	ft_printpointer(void *ptr, int fd);
int	ft_printlowhex(void *lowptr, int fd);
int	ft_printupphex(void *upptr, int fd);

// ft_nbrutils
int	ft_printdecimal(void *dcmptr, int fd);
int	ft_printint(void *intptr, int fd);
int	ft_printuint(void *uintptr, int fd);
int	ft_printpercent(void *prcnt, int fd);

#endif
