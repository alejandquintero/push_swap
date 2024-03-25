/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:37:25 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:20:56 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>
#include "../inc/libft.h"
#include <ctype.h>
#include <fcntl.h>

// char	ft_transform(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return ft_tolower(c);
// 	return ft_toupper(c);
// }

void	ft_replace(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = '4';
	else
		*c = '2';
}

// void	*content_m(void *c)
// {
// 	size_t	len;
// 	char	*s2;

// 	len = ft_strlen(c) + 4;
// 	s2 = malloc(len * sizeof(char));
// 	if (!s2)
// 		return (NULL);
// 	s2 = ft_memcpy(s2, (const void*)c, len);
// 	s2[len - 4] = ' ';
// 	s2[len - 3] = ':';
// 	s2[len - 2] = 'D';
// 	s2[len - 1] = '\0';
// 	return (s2);
// }

// void	free_content(void *c)
// {
// 	if (c != NULL)
// 		free(c);
// }

// void	change_content(void *c)
// {
// 	int	i;
// 	char *str;

// 	i = 0;
// 	str = (char *)c;
// 	write(1, "From write: ", 12);
// 	while (str[i] != '\0')
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

int	main(int argc, char* argv[])
{
	if (argc == 0)
		return (0);
	if (!argv[0])
		return (0);

// 	// char	dest[10] = "a";
// 	//char	src[] = "lorem ipsum dolor sit amet";
// 	//char str[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
//     //char    s1[] = "lorem ipsum dolor sit amet";
//     //char    s2[] = "dolor";
// 		char    *ptr1;
//     //char    *ptr2;

// printf("-- ft_bzero --\n");
// char    str[] = "Hello world";
// printf("before %s\n", str);
// ft_bzero(str, 12);
// printf("after %s\n", str);
// printf("-- ft_bzero --\n");

// printf("-- ft_isalnum --\n");
// char    str	 = 'd';
// printf("%d\n", ft_isalnum(str));
// printf("-- ft_isalnum --\n");

// printf("-- ft_isalpha --\n");
// int	num;
// num = 97;
// printf("ORIGINAL: %d\n", isalpha(num));
// printf("MIO: %d\n", ft_isalpha(num));
// printf("-- ft_isalpha --\n");

// printf("-- ft_isascii --\n");
// int	n;
// n = 58;
// printf("ORIG: %d\n", isascii(n));
// printf("MIO: %d\n", ft_isascii(n));
// printf("-- ft_isascii --\n");

// printf("-- ft_isdigit --\n");
// int	n;
// n = 49;
// printf("ORIG: %d\n", isdigit(n));
// printf("MIO: %d\n", ft_isdigit(n));
// printf("-- ft_isdigit --\n");

// printf("-- ft_isprint --\n");
// int	n;
// n = 126;
// printf("ORIG: %d\n", isprint(n));
// printf("MIO: %d\n", ft_isprint(n));
// printf("-- ft_isprint --\n");


// printf("-- ft_memcpy --\n");
// char	src[] = "Hello world!";
// char	dest[10] = "\0";
// printf("%s\n", dest);
// ft_memcpy(dest, src, 3);
// printf("%s\n", dest);
// printf("-- ft_memcpy --\n");

// printf("-- ft_memmove --\n");
// char	src[] = "hola";
// char	dst[5];
// printf("%s\n", dst);
// ft_memmove(dst, src, sizeof(src));
// printf("%s\n", dst);
// printf("-- ft_memmove --\n");

// printf("-- ft_memset --\n");
// char	b[] = "Hola";
// ft_memset(b, 65, 3);
// printf("%s", b);
// printf("-- ft_memset --\n");

// printf("-- ft_strlcpy --\n");
// char	dst[6]= "";
// char	src[]= "lorem ipsum";
// printf("%s\n", dst);
// printf("Return: %lu\n", ft_strlcpy(dst, src, 0));
// printf("-- ft_strlcpy --\n");

// printf("-- ft_strlen --\n");
// char	str[] = "8787";
// printf("ORIG: %lu\n", strlen(str));
// printf("MIO: %lu\n", ft_strlen(str));
// printf("-- ft_strlen --\n");

// printf("-- ft_strlcat --\n");
// char	dest[10] = "a";
// char	src[] = "lorem ipsum dolor sit amet";
// printf("dst before: %s\n", dest);
// printf("return value: %lu \n", ft_strlcat(dest, src, 10));
// printf("dst after: %s \n", dest);
// printf("-- ft_strlcat --\n");

// printf("-- ft_toupper --\n");
// printf("(a) -> %c | (z) -> %c | (&) -> %c \n", ft_toupper('a'), ft_toupper('z'), ft_toupper('&'));
// printf("-- ft_toupper --\n\n");

// printf("-- ft_tolower --\n");
// printf("(A) -> %c | (Z) -> %c | (&) -> %c \n", ft_tolower('A'), ft_tolower('Z'), ft_tolower('&'));
// printf("-- ft_tolower --\n\n");

// printf("-- ft_strchr --\n");
// //char str[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// char str[] = "there is so";

// printf("%s\n", ft_strchr(str, 'i'));
// printf("-- ft_strchr --\n\n");

// printf("-- ft_strrchr --\n");
// char str[] = "there tis so to";
// printf("%s\n", ft_strrchr(str, 't'));
// printf("-- ft_strrchr --\n\n");

// printf("-- ft_strncmp --\n");
// char    s1[] = "lorem ipsum dolor sit amet";
// char    s2[] = "dolor";
// printf("%d\n", ft_strncmp(s1, s2, 1));
// printf("-- ft_strncmp --\n\n");

// printf("-- ft_memchr --\n");
// char    str[] = "lorem ips";
// printf("mine: %s\n", ft_memchr(str, 'i', sizeof(str)));
// printf("orig: %s\n", memchr(str, 'i', sizeof(str)));
// printf("-- ft_memchr --\n\n");

// printf("-- ft_memcmp --\n");
// printf("mine: %d\n", ft_memcmp(argv[1], argv[2], 4));
// printf("ori: %d\n", memcmp(argv[1], argv[2], 4));
// printf("-- ft_memcmp --\n\n");

// printf("-- ft_strnstr --\n");
// char    s1[] = "lorem ipsum dolor sit amet";
// char    s2[] = "dolor";
// printf("mine: %s\n", ft_strnstr(s1, s2,20));
// printf("orig: %s\n", strnstr(s1, s2, 20));
// printf("-- ft_strnstr --\n\n");

// printf("-- ft_atoi --\n");
// printf("mine: %d\n", ft_atoi(argv[1]));
// printf("orig: %d\n", atoi(argv[1]));
// printf("-- ft_atoi --\n\n");

// printf("-- ft_calloc --\n");
// char    *ptr1;
// char    *ptr2;

// ptr1 = ft_calloc(5, sizeof(char));
// ptr2 = calloc(5, sizeof(char));
// printf("mine: %p\n", ptr1);
// printf("orig: %p\n", ptr2);
// free(ptr1);
// free(ptr2);
// printf("-- ft_calloc --\n\n");

// printf("-- ft_strdup --\n");
// char    *ptr1;
// char    *ptr2;

// ptr1 = ft_strdup(argv[1]);
// ptr2 = strdup(argv[1]);
// printf("mine: %p\n", ptr1);
// printf("orig: %p\n", ptr2);
// free(ptr1);
// free(ptr2);
// printf("-- ft_strdup --\n\n");

// printf("-- ft_substr --\n");
// char    *ptr1;

// ptr1 = ft_substr(argv[1], 5, 6);
// printf("res: %s\n", ptr1);
// free(ptr1);
// printf("-- ft_substr --\n\n");

// printf("-- ft_strtrim --\n");
// char    *ptr1;

// ptr1 = ft_strtrim(argv[1], argv[2]);
// printf("res: %s\n", ptr1);
// free(ptr1);
// printf("-- ft_strtrim --\n\n");

// printf("-- ft_split --\n\n");

// int		i;
// char	**ptr2;

// ptr2 = ft_split(argv[1], 'c');

// i = 0;
// printf("-- ft_split --\n");
// while (ptr2[i] != '\0')
// {
// 	printf("Res: %s\n", ptr2[i]);
// 	i++;
// }
// i = 0;
// while (ptr2[i] != '\0')
// {
// 	free(ptr2[i]);
// 	i++;
// }
// free(ptr2);
// printf("-- ft_split --\n\n");

// printf("-- ft_itoa --\n\n");
// int	number = -233232;
// char *ptr1;

// ptr1 = ft_itoa(number);
// printf("res: %s\n", ptr1);
// free(ptr1);
// printf("-- ft_itoa --\n");

// printf("-- ft_strmapi --\n");
// char	*ptr1;

// ptr1 = ft_strmapi("hello world!", ft_transform);
// printf("res: %s\n", ptr1);
// free(ptr1);
// printf("-- ft_strmapi --\n");

// printf("-- ft_striteri --\n");
// char	*ptr1;

// ptr1 = argv[1];
// printf("before: %s\n", ptr1);
// ft_striteri(ptr1, ft_replace);
// printf("after: %s\n", ptr1);
// printf("-- ft_striteri --\n");

	// printf("-- ft_putchar_fd --\n");
	// int	f;
	// int	i;
	
	// f = open("test.txt", O_WRONLY | O_APPEND);
	// if (!f)
	// 	return (1);
	// while (argv[1][i] != '\0')
	// {
	// 	ft_putchar_fd(argv[1][i], f);
	// 	i++;
	// }			
	// ft_putchar_fd('\n', 1);
	// close(f);
	// printf("-- ft_putchar_fd --\n");

	// printf("-- ft_putstr_fd --\n");
	// int	f;
	
	// f = open("test.txt", O_WRONLY | O_APPEND);
	// if (!f)
	// 	return (1);
	// ft_putstr_fd(argv[1], f);
	// ft_putstr_fd(argv[1], 1);
	// close(f);
	// printf("-- ft_putstr_fd --\n");

	// printf("-- ft_putendl_fd --\n");
	// int	f;
	
	// f = open("test.txt", O_WRONLY | O_APPEND);
	// if (!f)
	// 	return (1);
	// ft_putendl_fd(argv[1], f);
	// ft_putendl_fd(argv[1], 1);
	// close(f);
	// printf("-- ft_putendl_fd --\n");

	// printf("-- ft_putnbr_fd --\n");
	// int	f;
	// int	nbr = -2147483648;
	
	// f = open("test.txt", O_WRONLY | O_APPEND);
	// if (!f)
	// 	return (1);
	// ft_putnbr_fd(nbr, f);
	// ft_putnbr_fd(nbr, 1);
	// close(f);
	// printf("-- ft_putnbr_fd --\n");

	// printf("-- ft_lstnew --\n");
	// char	str[] = "This is a test";
	// t_list	*list;
	
	// list = ft_lstnew(str);
	// printf("content: %s\n", list->content);
	// printf("next: %p\n", list->next);
	// free(list);
	// printf("-- ft_lstnew --\n");

	// printf("-- ft_lsadd_front --\n");
	// t_list *current;
	// t_list *people =  malloc(sizeof(t_list));

	// people->content = "Node";
	// people->next = NULL;

	// t_list *new = malloc(sizeof(t_list));

	// new->content = "New node";
	// new->next = NULL;

	// current = people;
	// while (current != NULL)
	// {
	// 	printf("BEFORE %s\n", current->content);
	// 	current = current->next;
	// }

	// ft_lstadd_front(&people, new);

	// current = people;
	// while ( current != NULL)
	// {
	// 	printf("AFTER %s\n", current->content);
	// 	current = current->next;
	// }

	// free(new);
	// printf("-- ft_lsadd_front --\n");

	// printf("-- ft_lstsize --\n");
	// t_list *list1;
	// t_list *list2;

	// list1 = malloc(sizeof(t_list));
	
	// list1->content = "list 1";
	// list1->next = list2;

	// list2->content = "list 2";
	// list2->next = NULL;

	// printf("size: %d\n", ft_lstsize(list1));
	// free(list1);
	// printf("-- ft_lstsize --\n");

	// printf("-- ft_lstlast --\n");
	// t_list *list;
	// t_list *last;
	// t_list *aux;
	// char str[8] = "list ";
	// int		i;
	// i = 1;
	// aux = NULL;

	// while (i < 4)
	// {
	// 	aux = malloc(sizeof(t_list));
	// 	ft_strlcat(str, ft_itoa(i), 8);
	// 	aux->content = ft_strdup(str);
	// 	aux->next = NULL;
	// 	list = aux;
	// 	ft_strlcpy(str, "list ", 8);
	// 	i++;
	// }
	// last = ft_lstlast(list);
	// printf("content of last list: %s\n", last->content);

	// while (list != NULL)
	// {
	// 	aux = list;
	// 	list = list->next;
	// 	free(aux);
	// }
	// printf("-- ft_lstlast --\n");


	// printf("-- ft_lstadd_back --\n");
	// t_list *list1;
	// t_list *list2;
	// t_list *current;
	// t_list *new;


	// list1 = malloc(sizeof(t_list));
	// list1->content = "node";
	// list1->next = NULL;
	
	// list2 = malloc(sizeof(t_list));
	// list2->content = "other node";
	// list2->next = NULL;

	// list1->next = list2;
	
	// new = malloc(sizeof(t_list));
	// new->content = "new node";
	// new->next = NULL;
	
	// current = list1;
	// while (current != NULL)
	// {
	// 	printf("before: %s\n", current->content);
	// 	current = current->next;
	// }
	
	// ft_lstadd_back(&list1, new);

	// current = list1;
	// while (current != NULL)
	// {
	// 	printf("after: %s\n", current->content);
	// 	current = current->next;
	// }

	// free(list1);
	// free(list2);
	// printf("-- ft_lstadd_back --\n");

	// printf("-- ft_lstdelone --\n");
	// t_list	*lst1;
	// t_list	*lst2;
	// char	*str;

	// str = ft_strdup("Hello");

	// lst1 = malloc(sizeof(t_list));
	// lst1->content = str;
	// lst1->next = NULL;

	// lst2 = malloc(sizeof(t_list));
	// lst2->content = "Other content node";
	// lst2->next = NULL;

	// lst1->next = lst2;

	// printf("-- before lst1->content: %s --\n", lst1->content);
	// printf("-- before lst2->content: %s --\n", lst2->content);
	
	// ft_lstdelone(lst1, free_content);

	// printf("-- after lst1->content: %s --\n", lst1->content);
	// printf("-- after lst2->content: %s --\n", lst2->content);

	// free(lst2);
	
	// printf("-- ft_lstdelone --\n"); 

	// printf("-- ft_lstclear --\n");
	// t_list	*lst1;
	// t_list	*lst2;
	// char	*str1;
	// char	*str2;

	// str1 = ft_strdup("Hello 1");
	// str2 = ft_strdup("Hello 2");

	// lst1 = malloc(sizeof(t_list));
	// lst1->content = str1;
	// lst1->next = NULL;

	// lst2 = malloc(sizeof(t_list));
	// lst2->content = str2;
	// lst2->next = NULL;

	// lst1->next = lst2;

	// printf("-- before lst1: %s --\n", lst1->content);
	// printf("-- before lst2: %s --\n", lst2->content);
	
	// ft_lstclear(&lst1, free_content);

	// //  Segmentation fault porque no hay nada
	// printf("-- after lst1: %s --\n", lst1->content);
	// printf("-- after lst2: %s --\n", lst2->content);
	
	// printf("-- ft_lstclear --\n");

	// printf("-- ft_lstiter --\n");
	// t_list	*lst1;
	// t_list	*lst2;
	// char	*str1;
	// char	*str2;

	// str1 = ft_strdup("Hello 1");
	// str2 = ft_strdup("Hello 2");

	// lst1 = malloc(sizeof(t_list));
	// lst1->content = str1;
	// lst1->next = NULL;

	// lst2 = malloc(sizeof(t_list));
	// lst2->content = str2;
	// lst2->next = NULL;

	// lst1->next = lst2;

	// printf("-- before lst1: %s --\n", lst1->content);
	// printf("-- before lst2: %s --\n", lst2->content);
	
	// ft_lstiter(lst1, change_content);

	// printf("-- after lst1: %s --\n", lst1->content);
	// printf("-- after lst2: %s --\n", lst2->content);

	// ft_lstclear(&lst1, free_content);
	
	// printf("-- ft_lstiter --\n");

	// printf("-- ft_lstmap --\n");
	// t_list	*lst1;
	// t_list	*lst2;
	// t_list 	*lst_res;
	// char	str1[] = "Hello 1";
	// char	str2[] = "Hello 2";
	
	// lst1 = malloc(sizeof(t_list));
	// lst1->content = str1;
	// lst1->next = NULL;

	// lst2 = malloc(sizeof(t_list));
	// lst2->content = str2;
	// lst2->next = NULL;

	// lst1->next = lst2;

	// printf("-- before lst1: %s --\n", lst1->content);
	// printf("-- before lst2: %s --\n", lst1->next->content);
	
	// lst_res = ft_lstmap(lst1, content_m, free_content);

	// printf("-- res node 1:  %s --\n", lst_res->content);
	// printf("-- res node 2: %s --\n", lst_res->next->content);

	// ft_lstclear(&lst_res, free_content);
	
	// free(lst1);
	// free(lst2);
	
	// printf("-- ft_lstmap --\n");

	return (0);
}