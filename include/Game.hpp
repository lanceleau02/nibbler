/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:00:41 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/08 10:56:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILibraries.hpp"

class ILibraries;

class Game {
	private:
		int										_currentLib;
		int										_currentDirection;
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

	public:
		Game();
		Game(int gameAreaWidth, int gameAreaHeight);
		Game(const Game& other);
		Game& operator=(const Game& other);
		~Game();

		void	drawGrid();
		void	generateFood();
		void	moveSnake();
		void	run();
};
