/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/06 09:48:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ILibraries.hpp"

void	openLibrary(void** handle, const std::string& library) {
	std::cout << "Opening the " << library << " library..." << std::endl;
	*handle = dlopen(("./lib" + library + ".so").c_str(), RTLD_LAZY);
	if (!*handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return ;
	}
}

createLibraryInstance_t	loadSymbol(void* handle) {
	dlerror();
	std::cout << "Loading symbol createLibraryInstance..." << std::endl;
	auto createLibraryInstance = (ILibraries* (*)()) dlsym(handle, "createLibraryInstance");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol 'createLibraryInstance': " << dlsym_error << std::endl;
		dlclose(handle);
		return NULL;
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
		throw UsageException("invalid area values.", "800 ≤ WIDTH ≤ 1920 || 600 ≤ HEIGHT ≤ 1080");
}

void	switchLibrary(ILibraries*& libraryInstance, void*& handle, void*& renderer, const std::string& libraryName) {
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
		renderer = libraryInstance->createWindow();
	}
}

void	game() {
	ILibraries*	libraryInstance = nullptr;
	void*		handle = nullptr;
	void*		renderer = nullptr;

	std::cout << "Press '1', '2', '3' to switch libraries or 'q' to quit." << std::endl;
	openLibrary(&handle, "raylib");
	createLibraryInstance_t createLibraryInstance = loadSymbol(handle);
	if (createLibraryInstance) {
		libraryInstance = createLibraryInstance();
		renderer = libraryInstance->createWindow();
	}
	while (true) {
		if (libraryInstance) {
			int eventResult = libraryInstance->handleEvents(renderer);
			if (eventResult == CLOSE_WINDOW || eventResult == 'q') {
				std::cout << "Quitting..." << std::endl;
				break;
			} else if (eventResult == '1' || eventResult == ONE) {
				std::cout << "Switching to Raylib..." << std::endl;
				switchLibrary(libraryInstance, handle, renderer, "raylib");
			} else if (eventResult == '2' || eventResult == TWO) {
				std::cout << "Switching to SDL..." << std::endl;
				switchLibrary(libraryInstance, handle, renderer, "sdl2");
			} else if (eventResult == '3' || eventResult == THREE) {
				std::cout << "Switching to SFML..." << std::endl;
				switchLibrary(libraryInstance, handle, renderer, "sfml");
			}
			if (libraryInstance->isOpen(renderer)) {
				libraryInstance->centerWindow(renderer);
				libraryInstance->clearWindow(renderer);
				libraryInstance->createSquare(renderer);
				libraryInstance->display(renderer);
			}
		}
	}
	if (libraryInstance) delete libraryInstance;
	if (handle) dlclose(handle);
}

int main(int argc, char** argv) {
	try {
		if (argc != 3)
			throw UsageException("invalid number of arguments.", "./nibbler <width> <height>");
		parsing(argv[1], argv[2]);
		game();
	} catch (const UsageException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Usage: " << e.getUsageMessage() << std::endl;
		return EXIT_FAILURE;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}