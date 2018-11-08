#include <stdint.h>
#include <stddef.h>
#include <string.h>

extern "C" {
	#include "libft.h"

	int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
		if (size >= 1 && data[size - 1] == 0) {
			char c = (char)data[0];
			char *str = (char *)data + 1;
			if (strchr(str, c) != ft_strchr(str, c))
			__builtin_trap();
		}
		return 0;
	}
}