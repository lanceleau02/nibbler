/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/29 14:43:55 by laprieur         ###   ########.fr       */
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

createWindow_t loadSymbol(void* handle) {
	dlerror();
	std::cout << "Loading symbol createWindow..." << std::endl;
	createWindow_t createWindow = (createWindow_t) dlsym(handle, "createWindow");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		std::cerr << "Cannot load symbol 'createWindow': " << dlsym_error << std::endl;
		dlclose(handle);
		return NULL;
	}
	return createWindow;
}

int main() {
	Raylib	raylib;
	SDL		sdl;
	SFML	sfml;
	
	std::cout << "Press 'q' to quit.\n";

	while (true) {
		if (kbhit()) {
			char key = getchar();
			std::cout << "You pressed: " << key << '\n';

			void* handle = NULL;
			createWindow_t createWindow;
			if (key == '1') {
				// Raylib
				openLibrary(&handle, "Raylib");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling Raylib createWindow()..." << std::endl;
						raylib.createWindow();
					}
					std::cout << "Closing Raylib library..." << std::endl;
					dlclose(handle);
				}
			}
			else if (key == '2') {
				// SDL
				openLibrary(&handle, "SDL");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling SDL createWindow()..." << std::endl;
						sdl.createWindow();
					}
					std::cout << "Closing SDL library..." << std::endl;
					dlclose(handle);
				}
			}
			else if (key == '3') {
				// SFML
				openLibrary(&handle, "SFML");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling SFML createWindow()..." << std::endl;
						sfml.createWindow();
					}
					std::cout << "Closing SFML library..." << std::endl;
					dlclose(handle);
				}
			}
			else if (key == 'q') {
				std::cout << "Quitting...\n";
				break;
			}
		}
	}

	return 0;
}