#include <dlfcn.h>
#include <iostream>

int main() {
    // Open the library
	std::cout << "Opening the wrapper..." << std::endl;
	void* handle = dlopen("./wrapper.so", RTLD_LAZY);
	if (!handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return 1;
	}
	
	// Define the createWindow() function type
	typedef void (*createWindow_t)();

	// Reset errors
	dlerror();

	// Get the address of the createWindow() function
	std::cout << "Loading symbol createWindow..." << std::endl;
	createWindow_t createWindow = (createWindow_t) dlsym(handle, "createWindow");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol 'createWindow': " << dlsym_error << std::endl;
		dlclose(handle);
		return 1;
	}
	
	// Use it to create the window
	std::cout << "Calling createWindow..." << std::endl;
	createWindow();

	// Close the library
	std::cout << "Closing library..." << std::endl;
	dlclose(handle);
	return 0;
}