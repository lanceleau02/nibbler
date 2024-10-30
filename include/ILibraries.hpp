/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 11:59:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIBRARIES_HPP
#define ILIBRARIES_HPP

#include <raylib.h>
#include <SDL2/SDL.h>
#include <SFML/Graphics.hpp>

class ILibraries {
	public:
		virtual	~ILibraries() = default;
		
		virtual	void	createWindow() = 0;
        // virtual void    createSquare() = 0;
};

using createLibraryInstance_t = ILibraries* (*)();

#endif