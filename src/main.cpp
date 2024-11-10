/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:23:56 by laprieur          #+#    #+#             */
/*   Updated: 2024/11/10 17:30:36 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nibbler.hpp"

int	gGameAreaWidth = 0;
int	gGameAreaHeight = 0;

int main(int argc, char** argv) {
	try {
		if (argc != 3)
			throw UsageException("invalid number of arguments.", "./nibbler <width> <height>");
		parsing(argv[1], argv[2]);
		Game game(gGameAreaWidth, gGameAreaHeight);
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