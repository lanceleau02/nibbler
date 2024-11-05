/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:49 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 14:15:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYLIB_HPP
#define RAYLIB_HPP

#include "ILibraries.hpp"

class ILibraries;

class Raylib : public ILibraries {
	public:
		Raylib();
		// Raylib(const Raylib& other);
		// Raylib& operator=(const Raylib& other);
		~Raylib();
		
		void*	createWindow();
        void    centerWindow(void* r);
		int 	handleEvents(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void    createSquare(void* window);
		bool	isOpen(void* r);
		void	display(void* r);
};

#endif