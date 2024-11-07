/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/07 15:43:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIBRARIES_HPP
#define ILIBRARIES_HPP

#include "nibbler.hpp"

class ILibraries {
	protected:
		int	_windowWidth;
		int	_windowHeight;

	public:
		virtual	~ILibraries() = default;
		
		virtual int		handleEvents(void* r = nullptr) = 0;
		virtual bool	isOpen(void* r = nullptr) = 0;
		virtual void    centerWindow(void* r = nullptr) = 0;
		virtual void	clearWindow(void* r = nullptr) = 0;
		virtual void	closeWindow(void* r = nullptr) = 0;
		virtual void	createSquare(int x, int y, int width, int height, const Colors& color, void* r = nullptr) = 0;
		virtual void	display(void* r = nullptr) = 0;
		virtual	void*	createWindow() = 0;
		
		void			setWindowWidth(int width) { _windowWidth = width; }
		void			setWindowHeight(int height) { _windowHeight = height; }
};

using createLibraryInstance_t = ILibraries* (*)();

#endif