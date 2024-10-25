#include <string>

/* extern "C" char	*get_library_name() {
	return "I add 1 to ints";
} */

extern "C" int do_operation(int i) {
	return i + 1;
}