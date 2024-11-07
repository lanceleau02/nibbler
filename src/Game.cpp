/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/07 20:59:14 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.hpp"

Game::Game(int gameAreaWidth, int gameAreaHeight) : _gameAreaWidth(gameAreaWidth), _gameAreaHeight(gameAreaHeight) {
    for (int i = 0; i < gameAreaHeight; i++) {
        std::vector<int> row(gameAreaWidth, 0);
        _gameGrid.push_back(row);
    }
    
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
            }

            
            
            //--- Handling Display ---//
            drawGrid();
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