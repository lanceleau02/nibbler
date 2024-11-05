/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:16 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 11:28:16 by laprieur         ###   ########.fr       */
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

	public:
		SDL();
		// SDL(const SDL& other);
		// SDL& operator=(const SDL& other);
		~SDL();
		
		void*	createWindow();
		int 	handleEvents(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void	createSquare(void* window);
		bool	isOpen(void* r);
		void	display(void* r);
};

#endif