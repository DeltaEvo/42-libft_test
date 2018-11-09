#include "test.h"

#include <string.h>
#include "libft.h"
#include <stdio.h>

TEST {
	ASSERT(size >= 1);
	char buff[size - 1];
	char buff2[size - 1];
	void *ret = memccpy(buff, data + 1, data[0], sizeof(buff));
	void *ret2 = ft_memccpy(buff2, data + 1, data[0], sizeof(buff2));
	size_t s = ret ? ret - (void *)buff : 0;
	size_t s2 = ret2 ? ret2 - (void *)buff2 : 0;
	CRASH_IF(s != s2)
	CRASH_IF(memcmp(buff, buff2, s) != 0);
	return 0;
}
