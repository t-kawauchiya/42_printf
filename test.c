/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:01:46 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/12/16 23:46:51 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./libft/libft.h"
// #include "./libftprintf.h"
#include <stdio.h>

int	main(void)
{
	// positive test
	printf("abc\n");
	printf("%c:abc\n", 'x');
	printf("%s:abc\n", "123");
	printf("%p:abc\n", "123");
	printf("%d:abc\n", -123);
	printf("%i:abc\n", 123);
	printf("%u:abc\n", 123);
	printf("%x:abc\n", 123);
	printf("%X:abc\n", 123);
	printf("%%:abc\n");
	// negative test
	//   arg number error
	printf("abc\n", '0');
	printf("abc:%c\n");
	printf("abc:%s\n", "123", "456");
	printf("abc:%p,%d\n", "123", 456, 789);
	//   arg kind mismatch error
	printf("abc:%s\n", "123", "456", "789");
	//   conversion error
	printf("abc\n");
	printf("%c:abc\n", 'x');
}
