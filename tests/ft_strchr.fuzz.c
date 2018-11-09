#include "test.h"

#include <string.h>
#include "libft.h"

TEST {
	ASSERT(size >= 1 && data[size - 1] == 0);
	char c = (char)data[0];
	char *str = (char *)data + 1;
	CRASH_IF(strchr(str, c) != ft_strchr(str, c));
	return 0;
}
