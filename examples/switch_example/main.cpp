#include <iostream>
#include <string>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <termios.h>

// Function to check if a key has been pressed
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
	*handle = dlopen(("./" + library + "_wrapper.so").c_str(), RTLD_LAZY);
	if (!*handle) {
		std::cerr << "Cannot open library: " << dlerror() << std::endl;
		return ;
	}
}

typedef void (*createWindow_t)();

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
	std::cout << "Press 'q' to quit.\n";

	while (true) {
		if (kbhit()) {
			char key = getchar();
			std::cout << "You pressed: " << key << '\n';

			void* handle = NULL;
			createWindow_t createWindow;
			if (key == '1') {
				// Raylib
				openLibrary(&handle, "raylib");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling Raylib createWindow()..." << std::endl;
						createWindow();
					}
					std::cout << "Closing Raylib library..." << std::endl;
					dlclose(handle);
				}
			}
			else if (key == '2') {
				// SDL
				openLibrary(&handle, "sdl");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling SDL createWindow()..." << std::endl;
						createWindow();
					}
					std::cout << "Closing SDL library..." << std::endl;
					dlclose(handle);
				}
			}
			else if (key == '3') {
				// SFML
				openLibrary(&handle, "sfml");
				if (handle) {
					createWindow = loadSymbol(handle);
					if (createWindow) {
						std::cout << "Calling SFML createWindow()..." << std::endl;
						createWindow();
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
