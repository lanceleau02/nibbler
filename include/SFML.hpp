/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 11:28:13 by laprieur         ###   ########.fr       */
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
		
		void*	createWindow();
		int 	handleEvents(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void    createSquare(void* r);
		bool	isOpen(void* r);
		void	display(void* r);
};

#endif