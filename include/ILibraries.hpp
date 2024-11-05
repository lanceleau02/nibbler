/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/05 11:28:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIBRARIES_HPP
#define ILIBRARIES_HPP

#include "nibbler.hpp"

class ILibraries {
	public:
		virtual	~ILibraries() = default;
		
		virtual	void*	createWindow() = 0;
		virtual int		handleEvents(void* r = nullptr) = 0;
		virtual void	closeWindow(void* r = nullptr) = 0;
		virtual void	clearWindow(void* r = nullptr) = 0;
		virtual void	createSquare(void* r = nullptr) = 0;
		virtual bool	isOpen(void* r = nullptr) = 0;
		virtual void	display(void* r = nullptr) = 0;
};

using createLibraryInstance_t = ILibraries* (*)();

#endif