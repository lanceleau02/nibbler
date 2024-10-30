/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 17:59:11 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ILibraries.hpp"

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

int main(int argc, char** argv) {
	try {
		if (argc != 3)
			throw UsageException("invalid number of arguments.", "./main.elf <width> <height>");
		parsing(argv[1], argv[2]);
	} catch (const UsageException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Usage: " << e.getUsageMessage() << std::endl;
        return EXIT_FAILURE;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	
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