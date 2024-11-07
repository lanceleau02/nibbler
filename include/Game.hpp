/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:00:41 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/07 20:55:52 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "nibbler.hpp"
#include "ILibraries.hpp"

#define SQUARE_SIZE 50

#define NIBBLER_GREEN	Colors(0, 255, 0, 255)
#define NIBBLER_RED		Colors(255, 0, 0, 255)
#define NIBBLER_BLUE	Colors(0, 0, 255, 255)
#define NIBBLER_ORANGE	Colors(255, 165, 0, 255)

class Game {
	private:
		std::vector<std::vector<int>>		_gameGrid;
		std::deque<std::pair<int, int>>		_snake;
	
		const int	_gameAreaWidth;
		const int	_gameAreaHeight;

		ILibraries*	_libraryInstance;
		void*		_handle;
		void*		_renderer;
		int			_currentLib;
		int			_currentDirection;

	public:
		Game();
		Game(int _gameAreaWidth, int gameAreaHeight);
		~Game();

		void	handleEvents(ILibraries& libraryInstance, void* handle, void* renderer, int currentLib);
		void	drawGrid();
		void	run();
};

createLibraryInstance_t	loadSymbol(void* handle);
void	                openLibrary(void** handle, const std::string& library);
void	                switchLibrary(int windowWidth, int windowHeight, ILibraries*& libraryInstance, void*& handle, void*& renderer, const std::string& libraryName);
void	                parsing(Nibbler& nibbler, char* w, char* h);
