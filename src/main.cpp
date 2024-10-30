/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 12:00:31 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ILibraries.hpp"
#include "../include/Raylib.hpp"
#include "../include/SDL.hpp"
#include "../include/SFML.hpp"
#include <iostream>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <termios.h>

int kbhit() {
	termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

void	openLibrary(void** handle, const std::string& library) {
	std::cout << "Opening the " << library << " library..." << std::endl;
	*handle = dlopen(("./src/" + library + ".so").c_str(), RTLD_LAZY);
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

int main() {
	std::cout << "Press 'q' to quit.\n";

	while (true) {
		if (kbhit()) {
			char key = getchar();
			std::cout << "You pressed: " << key << '\n';

			void* handle = NULL;
			ILibraries* libraryInstance = NULL;
			if (key == '1')
				openLibrary(&handle, "Raylib");
			else if (key == '2')
				openLibrary(&handle, "SDL");
			else if (key == '3')
				openLibrary(&handle, "SFML");
			if (handle) {
				createLibraryInstance_t createLibraryInstance = loadSymbol(handle);
				if (createLibraryInstance)
					libraryInstance = createLibraryInstance();
			}
			if (key == 'q') {
				std::cout << "Quitting...\n";
				break;
			}
			if (libraryInstance) {
				std::cout << "Calling createWindow() for the selected library...\n";
				libraryInstance->createWindow();
				delete libraryInstance;
				dlclose(handle);
			} else if (handle) {
				dlclose(handle);
			}
		}
	}

	return 0;
}