/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:45 by hsebille          #+#    #+#             */
/*   Updated: 2024/11/07 20:00:26 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.hpp"

Game::Game(int gameAreaWidth, int gameAreaHeight) : _gameAreaWidth(gameAreaWidth), _gameAreaHeight(gameAreaHeight) {
    openLibrary(&_handle, "raylib");
    createLibraryInstance_t createLibraryInstance = loadSymbol(_handle);
    
    if (createLibraryInstance) {
        _libraryInstance = createLibraryInstance();
        _libraryInstance->setWindowWidth(gameAreaWidth * SQUARE_WIDTH);
        _libraryInstance->setWindowHeight(gameAreaHeight * SQUARE_HEIGHT);
        _renderer = _libraryInstance->createWindow();
    }

}

Game::~Game() {
    if (_libraryInstance) delete _libraryInstance;
    if (_handle) dlclose(_handle);
}

void Game::run() {
    Colors green(0, 255, 0, 255);
    Colors red(255, 0, 0, 255);
    Colors black(0, 0, 0, 255);

    while (true) {
        if (_libraryInstance) {
            int eventResult = _libraryInstance->handleEvents(_renderer);
    
            if (eventResult == CLOSE_WINDOW || eventResult == 'q') {
                std::cout << "Quitting..." << std::endl;
                break;
            } else if (_currentLib != RAYLIB_LIB && (eventResult == '1' || eventResult == ONE)) {
                _currentLib = RAYLIB_LIB;
                std::cout << "Switching to Raylib..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_HEIGHT, _gameAreaHeight * SQUARE_WIDTH, _libraryInstance, _handle, _renderer, "raylib");
            } else if (_currentLib != SDL_LIB && (eventResult == '2' || eventResult == TWO)) {
                _currentLib = SDL_LIB;
                std::cout << "Switching to SDL..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_HEIGHT, _gameAreaHeight * SQUARE_WIDTH, _libraryInstance, _handle, _renderer, "sdl2");
            } else if (_currentLib != SFML_LIB && (eventResult == '3' || eventResult == THREE)) {
                _currentLib = SFML_LIB;
                std::cout << "Switching to SFML..." << std::endl;
                switchLibrary(_gameAreaHeight * SQUARE_HEIGHT, _gameAreaHeight * SQUARE_WIDTH, _libraryInstance, _handle, _renderer, "sfml");
            }
            
            if (_libraryInstance->isOpen(_renderer)) {
                _libraryInstance->centerWindow(_renderer);
                _libraryInstance->clearWindow(_renderer);
                _libraryInstance->createSquare(350, 250, 100, 100, green, _renderer);
                _libraryInstance->display(_renderer);
            }
        }
    }
}