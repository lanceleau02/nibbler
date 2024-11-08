/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/08 10:56:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILibraries.hpp"

class ILibraries;

class SFML : public ILibraries {
	private:
		sf::RenderWindow*   _window;
		sf::Event			_event;
	
	public:
		SFML();
		SFML(const SFML& other);
		SFML& operator=(const SFML& other);
		~SFML();
		
		int 	handleEvents(void* r);
		bool	isOpen(void* r);
		void    centerWindow(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void    createSquare(int x, int y, int width, int height, const Colors& color, void* r);
		void	display(void* r);
		void*	createWindow();
};
