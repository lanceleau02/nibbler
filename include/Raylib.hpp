/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raylib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:49 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 13:04:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYLIB_HPP
#define RAYLIB_HPP

#include "ILibraries.hpp"

class ILibraries;

class Raylib : public ILibraries {
	private:
	
	public:
		Raylib();
		// Raylib(const Raylib& other);
		// Raylib& operator=(const Raylib& other);
		~Raylib();
		
		void	createWindow();
        void    createSquare(void* window);
};

#endif