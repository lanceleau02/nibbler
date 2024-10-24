#include "polygon.hpp"
#include <iostream>
#include <dlfcn.h>

int main() {
	// Load the triangle library
	void* triangle = dlopen("./triangle.so", RTLD_LAZY);
	if (!triangle) {
		std::cerr << "Cannot load library: " << dlerror() << std::endl;
		return 1;
	}

	// Reset errors
	dlerror();

	// Define the create() function type
	typedef polygon* create_t();
	
	// Get the address of the create() function
	std::cout << "Loading symbol create..." << std::endl;
	create_t* create_triangle = (create_t*) dlsym(triangle, "create");
	const char* dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol create: " << dlsym_error << std::endl;
		return 1;
	}

	// Define the destroy() function type
	typedef void destroy_t(polygon*);
	
	// Get the address of the destroy() function
	std::cout << "Loading symbol destroy..." << std::endl;
	destroy_t* destroy_triangle = (destroy_t*) dlsym(triangle, "destroy");
	dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol destroy: " << dlsym_error << std::endl;
		return 1;
	}

	// Create an instance of the class
	polygon* poly = create_triangle();

	// Use the class
	poly->set_side_length(7);
	std::cout << "The area is: " << poly->area() << std::endl;

	// Destroy the class
	destroy_triangle(poly);

	// Unload the triangle library
	dlclose(triangle);
	return 0;
}