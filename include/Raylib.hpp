/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:49 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/31 15:36:13 by laprieur         ###   ########.fr       */
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
		void    clearWindow(void* r);
		void    createSquare(void* window);
		void	display(void* r);
};

#endif