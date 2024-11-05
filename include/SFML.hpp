/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFML.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 14:15:16 by laprieur         ###   ########.fr       */
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
        void    centerWindow(void* r);
		int 	handleEvents(void* r);
		void    clearWindow(void* r);
		void    closeWindow(void* r);
		void    createSquare(void* r);
		bool	isOpen(void* r);
		void	display(void* r);
};

#endif