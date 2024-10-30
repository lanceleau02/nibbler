/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:16 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 11:58:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

#include "ILibraries.hpp"
#include <iostream>

class ILibraries;

class SDL : public ILibraries {
	private:
	
	public:
		SDL();
		// SDL(const SDL& other);
		// SDL& operator=(const SDL& other);
		~SDL();
		
		void	createWindow();
		// void		createSquare(SDL_Renderer* renderer);
};

#endif