/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:49:16 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 14:40:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
#define SDL_HPP

#include "ILibraries.hpp"

class ILibraries;

class SDL : public ILibraries {
	private:
	
	public:
		SDL();
		// SDL(const SDL& other);
		// SDL& operator=(const SDL& other);
		~SDL();
		
		void	createWindow();
		void	createSquare(void* window);
};

#endif