/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:16:52 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/09 17:59:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nibbler.hpp"

void	openLibrary(void** handle, const std::string& library) {
	std::cout << "Opening the " << library << " library..." << std::endl;
	*handle = dlopen(("./lib" + library + ".so").c_str(), RTLD_LAZY);
	if (!*handle)
		throw std::runtime_error(std::string("cannot open ") + dlerror());
}

createLibraryInstance_t	loadSymbol(void* handle) {
	dlerror();
	std::cout << "Loading symbol createLibraryInstance..." << std::endl;
	auto createLibraryInstance = (ILibraries* (*)()) dlsym(handle, "createLibraryInstance");
	if (dlerror()) {
		dlclose(handle);
		throw std::runtime_error(std::string("cannot load symbol 'createLibraryInstance': ") + dlerror());
	}
	return createLibraryInstance;
}

void	parsing(char* w, char* h) {
	std::istringstream	width(w);
	std::istringstream	height(h);
	int					widthValue;
	int					heightValue;
	
	if (!(width >> widthValue) || !(width.eof()) || 
		!(height >> heightValue) || !(height.eof()) ||
		widthValue < 0 || widthValue < MIN_WIDTH || widthValue > MAX_WIDTH ||
		heightValue < 0 || heightValue < MIN_HEIGHT || heightValue > MAX_HEIGHT)
		throw UsageException("invalid area values.", "6 ≤ WIDTH ≤ 20 | 6 ≤ HEIGHT ≤ 20");
    gGameAreaWidth = widthValue;
    gGameAreaHeight = heightValue;
}

void	switchLibrary(int windowWidth, int windowHeight, ILibraries*& libraryInstance, void*& handle, void*& renderer, const std::string& libraryName) {
	if (libraryInstance) {
		libraryInstance->closeWindow(renderer);
		delete libraryInstance;
		libraryInstance = nullptr;
	}
	if (handle) {
		dlclose(handle);
		handle = nullptr;
	}
	openLibrary(&handle, libraryName);
	createLibraryInstance_t createLibraryInstance = loadSymbol(handle);
	if (createLibraryInstance) {
		libraryInstance = createLibraryInstance();
		renderer = libraryInstance->createWindow(windowWidth, windowHeight);
	}
}