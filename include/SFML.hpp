/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 18:08:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ILibraries.hpp"

class ILibraries;

class SFML : public ILibraries {
	private:
		sf::RenderWindow*   _window;
		sf::Event			_event;
	
		SFML(const SFML& other);
		SFML& operator=(const SFML& other);

	public:
		SFML();
		~SFML();
		
		int 	handleEvents(void* r);
		bool	isOpen(void* r);
		void    centerWindow(int width, int height, void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void    createSquare(int x, int y, int size, const Colors& color, void* r);
		void	display(void* r);
		void*	createWindow(int width, int height);
};
