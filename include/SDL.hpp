/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:16 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 15:43:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

#include "ILibraries.hpp"

class ILibraries;

class SDL : public ILibraries {
	private:
		SDL_Window*		_window;
		SDL_Renderer*	_renderer;
		SDL_Event		_event;
		SDL_DisplayMode	_displayMode;

	public:
		SDL();
		SDL(const SDL& other);
		SDL& operator=(const SDL& other);
		~SDL();
		
		int 	handleEvents(void* r);
		bool	isOpen(void* r);
		void    centerWindow(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void	createSquare(int x, int y, int width, int height, const Colors& color, void* r);
		void	display(void* r);
		void*	createWindow();
};

#endif