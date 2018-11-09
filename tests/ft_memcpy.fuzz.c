#include "test.h"

#include <string.h>
#include "libft.h"

TEST {
	char buff[size];
	char buff2[size];
	CRASH_IF(memcpy(buff, data, size) - (void *)buff != ft_memcpy(buff2, data, size) - (void *)buff2);
	CRASH_IF(memcmp(buff, buff2, size) != 0);
	return 0;
}
