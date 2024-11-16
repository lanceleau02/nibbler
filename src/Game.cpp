/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/16 16:02:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.hpp"

Game::Game(int gameAreaWidth, int gameAreaHeight) :	_currentLib(RAYLIB_LIB),
													_currentDirection(RIGHT),
													_windowWidth(gameAreaWidth * SQUARE_SIZE),
													_windowHeight(gameAreaHeight * SQUARE_SIZE),
													_justMoved(false),
													_gameAreaWidth(gameAreaWidth), 
													_gameAreaHeight(gameAreaHeight),
													_moveInterval(0.5),
													_food({0, 0}),
													_lastMove(std::chrono::steady_clock::now()) {
	openLibrary(&_handle, "raylib");
	createLibraryInstance_t createLibraryInstance = loadSymbol(_handle);
	if (createLibraryInstance) {
		_libraryInstance = createLibraryInstance();
		_renderer = _libraryInstance->createWindow(_windowWidth, _windowHeight);
	}
	for (int i = 0; i < gameAreaHeight; i++) {
		std::vector<int> row(gameAreaWidth, 0);
		_gameGrid.push_back(row);
	}
	_snake.push_back(std::make_pair(gameAreaWidth / 2, gameAreaHeight / 2));
	_snake.push_back(std::make_pair(gameAreaWidth / 2 - 1, gameAreaHeight / 2));
	_snake.push_back(std::make_pair(gameAreaWidth / 2 - 2, gameAreaHeight / 2));
	_snake.push_back(std::make_pair(gameAreaWidth / 2 - 3, gameAreaHeight / 2));
	generateFood();
}

Game::~Game() {
	if (_libraryInstance) delete _libraryInstance;
	if (_handle) dlclose(_handle);
}

void	Game::drawGrid() {
	if (!_libraryInstance->isOpen(_renderer))
		return;

	_libraryInstance->centerWindow(_windowWidth, _windowHeight, _renderer);
	_libraryInstance->clearWindow(_renderer);
	for (int y = 0; y < _gameAreaHeight; y++) {
		for (int x = 0; x < _gameAreaWidth; x++) {
			if (_gameGrid[y][x] == 0)
				_libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, NIBBLER_GREEN, _renderer);
			else if (_gameGrid[y][x] == 1)
				_libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, NIBBLER_BLUE, _renderer);
			else if (_gameGrid[y][x] == 2)
				_libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, NIBBLER_RED, _renderer);
			else if (_gameGrid[y][x] == 3)
				_libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, NIBBLER_ORANGE, _renderer);
		}
	}
	_libraryInstance->display(_renderer);
}

void	Game::generateFood() {
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	disX(0, _gameAreaWidth - 1);
	std::uniform_int_distribution<>	disY(0, _gameAreaHeight - 1);

	while (true) {
		int x = disX(gen);
		int y = disY(gen);

		if (_gameGrid[y][x] == 0) {
			_food.first = x;
			_food.second = y;
			break;
		}
	}
}

void	Game::moveSnake() {
	for (int i = _snake.size() - 1; i > 0; --i)
		_snake[i] = _snake[i - 1];
	
	switch (_currentDirection) {
		case UP: _snake.front().second--; break;
		case DOWN: _snake.front().second++; break;
		case LEFT: _snake.front().first--; break;
		case RIGHT: _snake.front().first++; break;
	}

	if (_snake.front().first == _food.first && _snake.front().second == _food.second) {
		_snake.push_back(_snake.back());
		generateFood();
	}

	if (_snake.front().first < 0 || _snake.front().first >= _gameAreaWidth ||
		_snake.front().second < 0 || _snake.front().second >= _gameAreaHeight) {
		std::cout << "Game Over!" << std::endl;
		exit(EXIT_SUCCESS);
	}

	for (size_t i = 1; i < _snake.size(); i++) {
		if (_snake.front().first == _snake[i].first && _snake.front().second == _snake[i].second) {
			std::cout << "Game Over!" << std::endl;
			exit(EXIT_SUCCESS);
		}
	}

	_justMoved = false;
}

void	Game::run() {
	while (true) {
		if (_libraryInstance) {
			int eventResult = _libraryInstance->handleEvents(_renderer);
			switch (eventResult) {
				case CLOSE_WINDOW:
					std::cout << "Quitting..." << std::endl;
					return;
				case ONE:
					if (_currentLib != RAYLIB_LIB) {
						_currentLib = RAYLIB_LIB;
						std::cout << "Switching to Raylib..." << std::endl;
						switchLibrary(_windowWidth, _windowHeight, _libraryInstance, _handle, _renderer, "raylib");
					}
					break;
				case TWO:
					if (_currentLib != SDL_LIB) {
						_currentLib = SDL_LIB;
						std::cout << "Switching to SDL..." << std::endl;
						switchLibrary(_windowWidth, _windowHeight, _libraryInstance, _handle, _renderer, "sdl2");
					}
					break;
				case THREE:
					if (_currentLib != SFML_LIB) {
						_currentLib = SFML_LIB;
						std::cout << "Switching to SFML..." << std::endl;
						switchLibrary(_windowWidth, _windowHeight, _libraryInstance, _handle, _renderer, "sfml");
					}
					break;
				case UP:
					if (_currentDirection != DOWN && !_justMoved) {
						_currentDirection = UP;
						_justMoved = true;
					}
					break;
				case DOWN:
					if (_currentDirection != UP && !_justMoved) {
						_currentDirection = DOWN;
						_justMoved = true;
					}
					break;
				case LEFT:
					if (_currentDirection != RIGHT && !_justMoved) {
						_currentDirection = LEFT;
						_justMoved = true;
					}
					break;
				case RIGHT:
					if (_currentDirection != LEFT && !_justMoved) {
						_currentDirection = RIGHT;
						_justMoved = true;
					}
					break;
				default:
					break;
			}

			auto currentTime = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsedTime = currentTime - _lastMove;
			
			if (elapsedTime.count() >= _moveInterval) {
				moveSnake();
				_lastMove = currentTime;
			}

			size_t maxScore = _gameAreaWidth * _gameAreaHeight;
			if (_snake.size() == maxScore) {
				std::cout << "You won!" << std::endl;
				break;
			}

			for (int y = 0; y < _gameAreaHeight; y++)
				for (int x = 0; x < _gameAreaWidth; x++)
						_gameGrid[y][x] = 0;

			_gameGrid[_food.second][_food.first] = 3;
			
			for (auto& snakePart : _snake)
				_gameGrid[snakePart.second][snakePart.first] = 1;
			_gameGrid[_snake.front().second][_snake.front().first] = 2;

			drawGrid();
		}
	}
}
