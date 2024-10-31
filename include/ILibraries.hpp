/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/10/31 15:33:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIBRARIES_HPP
#define ILIBRARIES_HPP

#include "nibbler.hpp"

class ILibraries {
	private:
		// void*	renderer;

	public:
		virtual	~ILibraries() = default;
		
		virtual	void*	createWindow() = 0;
		virtual void	clearWindow(void* r = nullptr) = 0;
		virtual void	createSquare(void* r = nullptr) = 0;
		virtual void	display(void* r = nullptr) = 0;
};

using createLibraryInstance_t = ILibraries* (*)();

#endif