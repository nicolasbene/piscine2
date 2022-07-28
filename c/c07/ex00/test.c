#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int             main(void)
{
        char    *str;
        char    *allocated;

        str = "Hello World with malloc()";
        printf("original  : base  : $%s$ @ %p\n", str, str);
        allocated = strdup(str);
        printf("copied    : alloc : $%s$ @ %p\n", allocated, allocated);
        allocated = ft_strdup(str);
        printf("ft_copied : alloc : $%s$ @ %p\n", allocated, allocated);
}
