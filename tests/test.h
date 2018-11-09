#include <stdint.h>
#include <stddef.h>

#define TEST int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
#define ASSERT(__VA_ARGS__) if (!(__VA_ARGS__)) return 0;
#define CRASH_IF(__VA_ARGS__) if (__VA_ARGS__) __builtin_trap(); 
