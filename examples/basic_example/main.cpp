/* If you get this error: 

Cannot open library: libplus1.so: cannot open shared object file: No such file or directory

Run this command: export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. */

#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

int	main(int argc, char **argv) {
	// Usage message
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <library> <number>" << std::endl;
		return 1;
	}

	// Open the library
	std::cout << "Opening " << argv[1] << "..." << std::endl;
	void* handle = dlopen(argv[1], RTLD_LAZY);
	if (!handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return 1;
	}
    
	// Define the do_operation() function type
	typedef int (*do_operation_t)(int);

	// Reset errors
	dlerror();

	// Get the address of the do_operation() function
	std::cout << "Loading symbol do_operation..." << std::endl;
	do_operation_t do_operation = (do_operation_t) dlsym(handle, "do_operation");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol 'do_operation': " << dlsym_error << std::endl;
		dlclose(handle);
		return 1;
	}
	
	// Use it to do the calculation
	std::cout << "Calling do_operation..." << std::endl;
	std::cout << atoi(argv[2]) << " --> " << do_operation(atoi(argv[2])) << std::endl;
	
	// Close the library
	std::cout << "Closing library..." << std::endl;
	dlclose(handle);
	return 0;
}