/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/09 17:47:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nibbler.hpp"

int	gGameAreaWidth = 0;
int	gGameAreaHeight = 0;
/* int	gWindowWidth = 0;
int	gWindowHeight = 0; */

int main(int argc, char** argv) {
	try {
		if (argc != 3)
			throw UsageException("invalid number of arguments.", "./nibbler <width> <height>");
		// Nibbler nibbler;
		parsing(/* nibbler,  */argv[1], argv[2]);
		Game game(/* nibbler.windowWidth, nibbler.windowHeight */gGameAreaWidth, gGameAreaHeight);
		game.run();
	} catch (const UsageException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Usage: " << e.getUsageMessage() << std::endl;
		return EXIT_FAILURE;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}