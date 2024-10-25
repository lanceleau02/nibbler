#include <string>

/* extern "C" char	*get_library_name() {
	return "I add 2 to ints";
} */

extern "C" int do_operation(int i) {
	return i + 2;
}