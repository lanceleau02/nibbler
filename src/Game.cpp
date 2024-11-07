/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/07 22:29:09 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.hpp"

Game::Game(int gameAreaWidth, int gameAreaHeight) : _gameAreaWidth(gameAreaWidth), _gameAreaHeight(gameAreaHeight) {
    for (int i = 0; i < gameAreaHeight; i++) {
        std::vector<int> row(gameAreaWidth, 0);
        _gameGrid.push_back(row);
    }

    _snake.push_back(std::make_pair(gameAreaWidth / 2, gameAreaHeight / 2));
    _snake.push_back(std::make_pair(gameAreaWidth / 2 - 1, gameAreaHeight / 2));
    _snake.push_back(std::make_pair(gameAreaWidth / 2 - 2, gameAreaHeight / 2));
    _snake.push_back(std::make_pair(gameAreaWidth / 2 - 3, gameAreaHeight / 2));
    
    _lastMove = std::chrono::steady_clock::now();
    
    _currentDirection = RIGHT;
    _currentLib = RAYLIB_LIB;
    
    openLibrary(&_handle, "raylib");
    createLibraryInstance_t createLibraryInstance = loadSymbol(_handle);
    
    if (createLibraryInstance) {
        _libraryInstance = createLibraryInstance();
        _libraryInstance->setWindowWidth(gameAreaWidth * SQUARE_SIZE);
        _libraryInstance->setWindowHeight(gameAreaHeight * SQUARE_SIZE);
        _renderer = _libraryInstance->createWindow();
    }
}

Game::~Game() {
    if (_libraryInstance) delete _libraryInstance;
    if (_handle) dlclose(_handle);
}

void Game::run() {
    while (true) {
        if (_libraryInstance) {
            
            //--- Handling events ---//
            int eventResult = _libraryInstance->handleEvents(_renderer);
    
            if (eventResult == CLOSE_WINDOW || eventResult == 'q') {
                std::cout << "Quitting..." << std::endl;
                break;
            } else if (_currentLib != RAYLIB_LIB && (eventResult == '1' || eventResult == ONE)) {
                _currentLib = RAYLIB_LIB;
                std::cout << "Switching to Raylib..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_SIZE, _gameAreaHeight * SQUARE_SIZE, _libraryInstance, _handle, _renderer, "raylib");
            } else if (_currentLib != SDL_LIB && (eventResult == '2' || eventResult == TWO)) {
                _currentLib = SDL_LIB;
                std::cout << "Switching to SDL..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_SIZE, _gameAreaHeight * SQUARE_SIZE, _libraryInstance, _handle, _renderer, "sdl2");
            } else if (_currentLib != SFML_LIB && (eventResult == '3' || eventResult == THREE)) {
                _currentLib = SFML_LIB;
                std::cout << "Switching to SFML..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_SIZE, _gameAreaHeight * SQUARE_SIZE, _libraryInstance, _handle, _renderer, "sfml");
            } else if (eventResult == UP && _currentDirection != DOWN) {
                _currentDirection = UP;
            } else if (eventResult == DOWN && _currentDirection != UP) {
                _currentDirection = DOWN;
            } else if (eventResult == LEFT && _currentDirection != RIGHT) {
                _currentDirection = LEFT;
            } else if (eventResult == RIGHT && _currentDirection != LEFT) {
                _currentDirection = RIGHT;
            }

            //---> Handling Snake Movement <---//
            auto currentTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsedTime = currentTime - _lastMove;
            
            if (elapsedTime.count() >= _moveInterval) {
                moveSnake();
                _lastMove = currentTime;
            }

            //---> Check if the player has won <---//
            size_t maxScore = _gameAreaWidth * _gameAreaHeight;
            if (_snake.size() == maxScore) {
                std::cout << "You won!" << std::endl;
                break;
            }

            //---> Update The position of the snake in the grid <---//
            for (int y = 0; y < _gameAreaHeight; y++) {
                for (int x = 0; x < _gameAreaWidth; x++) {
                        _gameGrid[y][x] = 0;
                }
            }

            _gameGrid[_food.second][_food.first] = 3;
            
            for (auto& snakePart : _snake) {
                _gameGrid[snakePart.second][snakePart.first] = 1;
            }
            _gameGrid[_snake.front().second][_snake.front().first] = 2;
            
            //---> Handling Display <---//
            drawGrid();
        }
    }
}

void Game::moveSnake() {
    //--- Move the snake ---//
    for (int i = _snake.size() - 1; i > 0; --i) {
        _snake[i] = _snake[i - 1];
    }
    
    //--- Change the direction of the snake ---//
    switch (_currentDirection) {
        case UP: _snake.front().second--; break;
        case DOWN: _snake.front().second++; break;
        case LEFT: _snake.front().first--; break;
        case RIGHT: _snake.front().first++; break;
    }

    //--- Check if the snake has eaten the food ---//
    if (_snake.front().first == _food.first && _snake.front().second == _food.second) {
        _snake.push_back(_snake.back());
        generateFood();
    }

    //--- Check if the snake has hit the wall---//
    if (_snake.front().first < 0 || _snake.front().first >= _gameAreaWidth ||
        _snake.front().second < 0 || _snake.front().second >= _gameAreaHeight) {
        std::cout << "Game Over!" << std::endl;
        exit(EXIT_SUCCESS);
    }

    //--- Check if the snake has hit itself ---//
    for (size_t i = 1; i < _snake.size(); i++) {
        if (_snake.front().first == _snake[i].first && _snake.front().second == _snake[i].second) {
            std::cout << "Game Over!" << std::endl;
            exit(EXIT_SUCCESS);
        }
    }
}

void Game::drawGrid() {
    if (!_libraryInstance->isOpen(_renderer))
        return;

    _libraryInstance->centerWindow(_renderer);
    _libraryInstance->clearWindow(_renderer);
    
    for (int y = 0; y < _gameAreaHeight; y++) {
        for (int x = 0; x < _gameAreaWidth; x++) {
            if (_gameGrid[y][x] == 0) {
                _libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, NIBBLER_GREEN, _renderer);
            } else if (_gameGrid[y][x] == 1) {
                _libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, NIBBLER_BLUE, _renderer);
            } else if (_gameGrid[y][x] == 2) {
                _libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, NIBBLER_RED, _renderer);
            } else if (_gameGrid[y][x] == 3) {
                _libraryInstance->createSquare(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, NIBBLER_ORANGE, _renderer);
            }
        }
    }
    
    _libraryInstance->display(_renderer);
}

#include <random>

void Game::generateFood() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> disX(0, _gameAreaWidth - 1);
    std::uniform_int_distribution<> disY(0, _gameAreaHeight - 1);

    int x, y;
    while (true) {
        x = disX(gen);
        y = disY(gen);

        if (_gameGrid[y][x] == 0) {
            _food.first = x;
            _food.second = y;
            break;
        }
    }
}
