/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:00:41 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/09 18:07:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILibraries.hpp"

class ILibraries;

class Game {
	private:
		int										_currentLib;
		int										_currentDirection;
		int										_windowWidth;
		int										_windowHeight;
		bool									_justMoved;
		void*									_renderer;
		void*									_handle;
		const int								_gameAreaWidth;
		const int								_gameAreaHeight;
		const double							_moveInterval;
		ILibraries*								_libraryInstance;
		std::pair<int, int>						_food;
		std::vector<std::vector<int>>			_gameGrid;
		std::deque<std::pair<int, int>>			_snake;
		std::chrono::steady_clock::time_point	_lastMove;

		Game();
		Game(const Game& other);
		Game& operator=(const Game& other);
        
	public:
		Game(int gameAreaWidth, int gameAreaHeight);
		~Game();

		void	drawGrid();
		void	generateFood();
		void	moveSnake();
		void	run();
};
