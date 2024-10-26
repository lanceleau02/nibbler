/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/26 20:21:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIBRARIES_HPP
#define ILIBRARIES_HPP

#include <raylib.h>
#include <SDL.h>
#include <SFML/Graphics.hpp>

typedef void (*createWindow_t)();

class ILibraries {
	public:
		virtual	~ILibraries() {}
		
		virtual	void	createWindow() = 0;
};

#endif