#include "test.h"

#include <string.h>
#include "libft.h"

TEST {
	ASSERT(size >= 1);
	char buff[size - 1];
	char buff2[size - 1];
	CRASH_IF(memccpy(buff, data + 1, data[0], size) - (void *)buff != ft_memccpy(buff2, data + 1, data[0], size) - (void *)buff2);
	CRASH_IF(memcmp(buff, buff2, size - 1) != 0);
	return 0;
}
