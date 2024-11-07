# Distribution
FROM	ubuntu:22.04

# Update and upgrade
RUN		apt update && apt upgrade -y

# Install dependencies
RUN		apt install -y	sudo				\
						build-essential		\
						pkg-config			\
						git					\
						cmake				\
						meson				\
						libasound2-dev		\
						libx11-dev			\
						libxrandr-dev		\
						libxi-dev			\
						libgl1-mesa-dev 	\
						libglu1-mesa-dev	\
						libxcursor-dev		\
						libxinerama-dev		\
						libwayland-dev		\
						libxkbcommon-dev

# Install Raylib
RUN		git clone https://github.com/raysan5/raylib.git raylib	\
		&& cd raylib											\
		&& mkdir build											\
		&& cd build												\
		&& cmake -DBUILD_SHARED_LIBS=ON ..						\
		&& make													\
		&& sudo make install

# Install SDL
RUN		git clone https://github.com/libsdl-org/SDL.git -b SDL2	\
		&& cd SDL												\
		&& mkdir build											\
		&& cd build												\
		&& ../configure											\
		&& make													\
		&& sudo make install

#Install SFML
RUN		sudo apt install -y libsfml-dev

# Create a nibbler directory
RUN		mkdir nibbler

# Copy the content of the directory into the Docker
COPY	. /nibbler

# Define the nibbler directory as workdir
WORKDIR	/nibbler

