/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILibraries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:32:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 18:00:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "nibbler.hpp"

class ILibraries {
	public:
		virtual	~ILibraries() = default;

		virtual int		handleEvents(void* r = nullptr) = 0;
		virtual bool	isOpen(void* r = nullptr) = 0;
		virtual void    centerWindow(int width, int height, void* r = nullptr) = 0;
		virtual void	clearWindow(void* r = nullptr) = 0;
		virtual void	closeWindow(void* r = nullptr) = 0;
		virtual void	createSquare(int x, int y, int size, const Colors& color, void* r = nullptr) = 0;
		virtual void	display(void* r = nullptr) = 0;
		virtual	void*	createWindow(int width, int height) = 0;
};
