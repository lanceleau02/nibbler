/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/30 11:58:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_HPP
#define SFML_HPP

#include "ILibraries.hpp"

class ILibraries;

class SFML : public ILibraries {
	private:
	
	public:
		SFML();
		// SFML(const SFML& other);
		// SFML& operator=(const SFML& other);
		~SFML();
		
		void	createWindow();
        // void    createSquare(sf::RenderWindow window);
};

#endif