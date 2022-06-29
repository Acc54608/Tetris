// A Tetris game built in C++
// GUI made using SFML - https://www.sfml-dev.org/index.php
// By Alex Casper

#include <cstdio>
#include <String>
#include <new>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <SFML\Graphics.hpp>

class Tetrimino {
	std::vector<sf::Vertex> shape;
	int rotation = 1;
	int type =  0;
	bool locked = false;
	sf::Vector2f origin = { 0.f, 0.f };
public:
	Tetrimino(int type) {
		switch (type) {
			// Grid is 0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300 or -120, -90, -70, -60, -30 0, 30, 60, 90, 120
			// 100, 130|132, 162|164, 194|196, 226|228, 258|260, 290|292, 322|324, 354|356, 386| 388, 418
		case 0:
			shape.push_back({ {196, 0.f}, sf::Color::Magenta });
			shape.push_back({ {226.f, 0.f}, sf::Color::Magenta });
			shape.push_back({ {226.f, 30.f}, sf::Color::Magenta });
			shape.push_back({ {196.f, 30.f}, sf::Color::Magenta });

			shape.push_back({ {228.f, 0.f}, sf::Color::Magenta });
			shape.push_back({ {258.f, 0.f}, sf::Color::Magenta });
			shape.push_back({ {258.f, 30.f }, sf::Color::Magenta });
			shape.push_back({ {228.f, 30.f}, sf::Color::Magenta });

			shape.push_back({ {228.f, 32.f}, sf::Color::Magenta });
			shape.push_back({ {258.f, 32.f}, sf::Color::Magenta });
			shape.push_back({ {258.f, 62.f}, sf::Color::Magenta });
			shape.push_back({ {228.f, 62.f}, sf::Color::Magenta });

			shape.push_back({ {260.f, 0.f}, sf::Color::Magenta });
			shape.push_back({ {290.f, 0.f}, sf::Color::Magenta });
			shape.push_back({ {290.f, 30.f}, sf::Color::Magenta });
			shape.push_back({ {260.f, 30.f}, sf::Color::Magenta });


			origin.x = 243.f; origin.y = 15;
			break;
		case 1:

			shape.push_back({ {196, 32.f}, sf::Color::Blue });
			shape.push_back({ {226.f, 32.f}, sf::Color::Blue });
			shape.push_back({ {226.f, 62.f}, sf::Color::Blue });
			shape.push_back({ {196.f, 62.f}, sf::Color::Blue });

			shape.push_back({ {196.f, 0.f}, sf::Color::Blue });
			shape.push_back({ {226.f, 0.f}, sf::Color::Blue });
			shape.push_back({ {226.f, 30.f}, sf::Color::Blue });
			shape.push_back({ {196.f, 30.f}, sf::Color::Blue });

			shape.push_back({ {228.f, 32.f}, sf::Color::Blue });
			shape.push_back({ {258.f, 32.f}, sf::Color::Blue });
			shape.push_back({ {258.f, 62.f}, sf::Color::Blue });
			shape.push_back({ {228.f, 62.f}, sf::Color::Blue });

			shape.push_back({ {260.f, 32.f}, sf::Color::Blue });
			shape.push_back({ {290.f, 32.f}, sf::Color::Blue });
			shape.push_back({ {290.f, 62.f}, sf::Color::Blue });
			shape.push_back({ {260.f, 62.f}, sf::Color::Blue });

			origin.x = 243.f; origin.y = 47;
			break;
		case 2:

			shape.push_back({ {260.f, 32.f}, sf::Color(255, 165, 0, 255)});
			shape.push_back({ {290.f, 32.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {290.f, 62.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {260.f, 62.f}, sf::Color(255, 165, 0, 255) });

			shape.push_back({ {260.f, 0.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {290.f, 0.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {290.f, 30.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {260.f, 30.f}, sf::Color(255, 165, 0, 255) });

			shape.push_back({ {228.f, 32.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {258.f, 32.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {258.f, 62.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {228.f, 62.f}, sf::Color(255, 165, 0, 255) });

			shape.push_back({ {196.f, 32.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {226.f, 32.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {226.f, 62.f}, sf::Color(255, 165, 0, 255) });
			shape.push_back({ {196.f, 62.f}, sf::Color(255, 165, 0, 255) });

			origin.x = 243.f; origin.y = 47; 

			break;
		case 3:

			shape.push_back({ {228.f, 0.f}, sf::Color::Yellow });
			shape.push_back({ {258.f, 0.f}, sf::Color::Yellow });
			shape.push_back({ {258.f, 30.f}, sf::Color::Yellow });
			shape.push_back({ {228.f, 30.f}, sf::Color::Yellow });

			shape.push_back({ {260.f, 0.f}, sf::Color::Yellow });
			shape.push_back({ {290.f, 0.f}, sf::Color::Yellow });
			shape.push_back({ {290.f, 30.f}, sf::Color::Yellow });
			shape.push_back({ {260.f, 30.f}, sf::Color::Yellow });

			shape.push_back({ {228.f, 32.f}, sf::Color::Yellow });
			shape.push_back({ {258.f, 32.f}, sf::Color::Yellow });
			shape.push_back({ {258.f, 62.f}, sf::Color::Yellow });
			shape.push_back({ {228.f, 62.f}, sf::Color::Yellow });

			shape.push_back({ {260.f, 32.f}, sf::Color::Yellow });
			shape.push_back({ {290.f, 32.f}, sf::Color::Yellow });
			shape.push_back({ {290.f, 62.f}, sf::Color::Yellow });
			shape.push_back({ {260.f, 62.f}, sf::Color::Yellow });

			origin.x = 259.f; origin.y = 31.f;

			break;
		case 4:

			shape.push_back({ {260.f, 0.f}, sf::Color::Green });
			shape.push_back({ {290.f, 0.f}, sf::Color::Green });
			shape.push_back({ {290.f, 30.f}, sf::Color::Green });
			shape.push_back({ {260.f, 30.f}, sf::Color::Green });

			shape.push_back({ {228.f, 0.f}, sf::Color::Green });
			shape.push_back({ {258.f, 0.f}, sf::Color::Green });
			shape.push_back({ {258.f, 30.f}, sf::Color::Green });
			shape.push_back({ {228.f, 30.f}, sf::Color::Green });

			shape.push_back({ {228.f, 32.f}, sf::Color::Green });
			shape.push_back({ {258.f, 32.f}, sf::Color::Green });
			shape.push_back({ {258.f, 62.f}, sf::Color::Green });
			shape.push_back({ {228.f, 62.f}, sf::Color::Green });

			shape.push_back({ {196.f, 32.f}, sf::Color::Green });
			shape.push_back({ {226.f, 32.f}, sf::Color::Green});
			shape.push_back({ {226.f, 62.f}, sf::Color::Green });
			shape.push_back({ {196.f, 62.f}, sf::Color::Green });

			origin.x = 243.f; origin.y = 47.f;

			break;
		case 5:

			shape.push_back({ {196.f, 0.f}, sf::Color::Red });
			shape.push_back({ {226.f, 0.f}, sf::Color::Red });
			shape.push_back({ {226.f, 30.f}, sf::Color::Red });
			shape.push_back({ {196.f, 30.f}, sf::Color::Red });

			shape.push_back({ {228.f, 0.f}, sf::Color::Red });
			shape.push_back({ {258.f, 0.f}, sf::Color::Red });
			shape.push_back({ {258.f, 30.f}, sf::Color::Red });
			shape.push_back({ {228.f, 30.f}, sf::Color::Red });

			shape.push_back({ {228.f, 32.f}, sf::Color::Red });
			shape.push_back({ {258.f, 32.f}, sf::Color::Red });
			shape.push_back({ {258.f, 62.f}, sf::Color::Red });
			shape.push_back({ {228.f, 62.f}, sf::Color::Red });

			shape.push_back({ {260.f, 32.f}, sf::Color::Red });
			shape.push_back({ {290.f, 32.f}, sf::Color::Red });
			shape.push_back({ {290.f, 62.f}, sf::Color::Red });
			shape.push_back({ {260.f, 62.f}, sf::Color::Red });

			origin.x = 243.f; origin.y = 47.f;

			break;
		case 6:
			shape.push_back({ {196.f, 0.f}, sf::Color(131, 238, 255, 255)});
			shape.push_back({ {226.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {226.f, 30.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {196.f, 30.f}, sf::Color(131, 238, 255, 255) });

			shape.push_back({ {228.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {258.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {258.f, 30.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {228.f, 30.f}, sf::Color(131, 238, 255, 255) });

			shape.push_back({ {260.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {290.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {290.f, 30.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {260.f, 30.f}, sf::Color(131, 238, 255, 255) });

			shape.push_back({ {292.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {322.f, 0.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {322.f, 30.f}, sf::Color(131, 238, 255, 255) });
			shape.push_back({ {292.f, 30.f}, sf::Color(131, 238, 255, 255) });

			origin.x = 259.f; origin.y = 31.f;

			break;
		}
		Tetrimino::type = type;
	}
	virtual ~Tetrimino();

	int checkMoveCollision(int direction, const std::vector<Tetrimino*>& gamePieces) {
		if (direction == 1) {
			for (size_t i = 0; i < shape.size(); i++) {
				if (shape[i].position.x + 30 > 418)
					return 1;
			}
			// See if any vertices of each tile of the current Tetrimino match any loaded Tetrimino's and if so how many with int matches
			int matches = 0;
			for (Tetrimino* tp : gamePieces) {
				if (tp != this) {
					auto compare = tp->getShape();
					
					for (size_t i = 1; i <= shape.size() / 4 ; i++) {
						for (size_t j = 1; j <= compare.size() / 4; j++) {
							matches = 0;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 2)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 2)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 2)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 2)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 3)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 3)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 3)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 3)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (matches >= 3)
								return 1;
						}
					}
				}
			}
			return 0;
		}
		else if (direction == -1) {
			for (size_t i = 0; i < shape.size(); i++) {
				if (shape[i].position.x - 30 < 100)
					return 1;
			}
			// See if any vertices of each tile of the current Tetrimino match any loaded Tetrimino's and if so how many with int matches
			int matches = 0;
			for (Tetrimino* tp : gamePieces) {
				if (tp != this) {
					auto compare = tp->getShape();
					
					for (size_t i = 1; i <= shape.size() / 4; i++) {
						for (size_t j = 1; j <= compare.size() / 4; j++) {
							matches = 0;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 2)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 2)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 2)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 2)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 3)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 3)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 3)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 3)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ -32.f, 0.f } == compare[(j * 4) - 4].position)
								matches++;
							if (matches >= 3)
								return 1;
						}
					}
				}
			}
			return 0;
		}
		else if (direction == 0) {
			for (size_t i = 0; i < shape.size(); i++) {
				if (shape[i].position.y + 30 > 642)
					return 1;
			}
			// See if any vertices of each tile of the current Tetrimino match any loaded Tetrimino's and if so how many with int matches
			int matches = 0;
			for (Tetrimino* tp : gamePieces) {
				if (tp != this) {
					auto compare = tp->getShape();
					//matches = 0;
					for (size_t i = 1; i <= shape.size() / 4; i++) {
						for (size_t j = 1; j <= compare.size() / 4; j++) {
							matches = 0;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 2)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 2)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 2)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 2)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 3)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 3)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 3)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 3)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 4].position)
								matches++;
							if (shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 1].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 2].position ||
								shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 3].position || shape[(i * 4 - 1)].position + sf::Vector2f{ 0.f, 32.f } == compare[(j * 4) - 4].position)
								matches++;
							if (matches >= 4)
								return 1;
						}
					}
				}
			}
		return 0;
		}
	}

	void rotate(int rotate, const std::vector<Tetrimino*>& gamePieces) {
		float xDisplace = 0;
		float yDisplace = 0;
		int test = 0;
		bool wallKick = true;
		// Assume block will not pass and is obstructed
		bool pieceKick = true;
		if (!locked) {
			std::vector<sf::Vertex> testCopy;
			sf::Vector2f testOrigin;
			while (test < 5) {
				wallKick = false;
				pieceKick = false;
				testCopy = shape;
				testOrigin = origin;
				if (rotate == -1) {
					// Tetris SRS kick offsets set the displacement values
					switch (test) {
					case 0:
						break;
					case 1:
						if (rotation - 1 == 1 || rotation - 1 == 0) {
							xDisplace = 32.f;
						}
						else if (rotation - 1 == 2 || rotation - 1 == 3) {
							xDisplace = -32.f;
						}
						break;
					case 2:
						if (rotation - 1 == 1) {
							xDisplace = 32.f;
							yDisplace = 32.f;
						}
						else if (rotation - 1 == 2) {
							xDisplace = -32.f;
							yDisplace = -32.f;
						}
						else if (rotation - 1 == 3) {
							xDisplace = -32.f;
							yDisplace = 32.f;
						}
						else if (rotation - 1 == 0) {
							xDisplace = 32.f;
							yDisplace = -32.f;
						}
						break;
					case 3:
						if (rotation - 1 == 1 || rotation - 1 == 3) {
							yDisplace = -64.f;
						}
						else if (rotation - 1 == 2 || rotation - 1 == 0) {
							yDisplace = 64.f;
						}
						break;
					case 4:
						if (rotation - 1 == 1) {
							xDisplace = 32.f;
							yDisplace = -64.f;
						}
						else if (rotation - 1 == 2) {
							xDisplace = -32.f;
							yDisplace = 64.f;
						}
						else if (rotation - 1 == 3) {
							xDisplace = -32.f;
							yDisplace = -64.f;
						}
						else if (rotation - 1 == 0) {
							xDisplace = 32.f;
							yDisplace = 64.f;
						}
						break;
					}
					
					// Rotate the shape
					for (size_t i = 0; i < testCopy.size(); i++) {
						testCopy[i].position = { ((testCopy[i].position.y - origin.y) + origin.x) + xDisplace, (((testCopy[i].position.x - origin.x) * -1) + origin.y) + yDisplace };
					}
					testOrigin.x += xDisplace;
					testOrigin.y += yDisplace;
					// Check the shape against wall, and others
					
					for (size_t i = 0; i < testCopy.size(); i++) {
						if (testCopy[i].position.x > 418 || testCopy[i].position.x < 100 || testCopy[i].position.y < 0 || testCopy[i].position.y > 642) {
							wallKick = true;
							break;
						}
					}
					
					if (wallKick == false) {
						int matches = 0;
						for (Tetrimino* tp : gamePieces) {
							if (pieceKick == true)
								break;
							if (tp != this) {
								auto compare = tp->getShape();
								
								for (size_t i = 1; i <= shape.size() / 4; i++) {
									if (pieceKick)
										break;
									for (size_t j = 1; j <= compare.size() / 4; j++) {
										matches = 0;
										if (testCopy[(i * 4) - 1].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 1].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 1].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 1].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 2].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 2].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 2].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 2].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 3].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 3].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 3].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 3].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 4].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 4].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 4].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 4].position == compare[(j * 4) - 4].position)
											matches++;
										if (matches >= 3) {
											pieceKick = true;
											break;
										}
									}
								}
							}
						}
					}
				}
				else if (rotate == 1) {
					switch (test) {
					case 0:
						break;
					case 1:
						if (rotation + 1 == 2 || rotation + 1 == 5)
							xDisplace = -32.f;
						else if (rotation + 1 == 3 || rotation + 1 == 4)
							xDisplace = 32.f;
						break;
					case 2:
						if (rotation + 1 == 2) {
							xDisplace = -32.f;
							yDisplace = -32.f;
						}
						else if (rotation + 1 == 3) {
							xDisplace = 32.f;
							yDisplace = 32.f;
						}
						else if (rotation + 1 == 4) {
							xDisplace = 32.f;
							yDisplace = -32.f;
						}
						else if (rotation + 1 == 5) {
							xDisplace = -32.f;
							yDisplace = 32.f;
						}
						break;
					case 3:
						if (rotation + 1 == 2 || rotation + 1 == 4)
							yDisplace = 64.f;
						else if (rotation + 1 == 3 || rotation + 1 == 5)
							yDisplace = -64.f;
						break;
					case 4:
						if (rotation + 1 == 2) {
							xDisplace = -32.f;
							yDisplace = 64.f;
						}
						else if (rotation + 1 == 3) {
							xDisplace = 32.f;
							yDisplace = -64.f;
						}
						else if (rotation + 1 == 4) {
							xDisplace = 32.f;
							yDisplace = 64.f;
						}
						else if (rotation + 1 == 5) {
							xDisplace = -32.f;
							yDisplace = -64.f;
						}
						break;
					}
					for (size_t i = 0; i < testCopy.size(); i++) {
						testCopy[i].position = { (((testCopy[i].position.y - origin.y) * -1) + origin.x) + xDisplace, ((testCopy[i].position.x - origin.x) + origin.y) + yDisplace };
					}
					testOrigin.x += xDisplace;
					testOrigin.y += yDisplace;
					// Check the shape against wall, and others
					wallKick = false;
					for (size_t i = 0; i < testCopy.size(); i++) {
						if (testCopy[i].position.x > 418 || testCopy[i].position.x < 100) {//|| testCopy[i].position.y < 0 || testCopy[i].position.y > 600) {
							wallKick = true;
							break;
						}
					}
					pieceKick = false;
					if (!wallKick) {
						int matches = 0;
						for (Tetrimino* tp : gamePieces) {
							if (pieceKick == true)
								break;
							if (tp != this) {
								auto compare = tp->getShape();
								
								for (size_t i = 1; i <= shape.size() / 4; i++) {
									if (pieceKick)
										break;
									for (size_t j = 1; j <= compare.size() / 4; j++) {
										matches = 0;
										if (testCopy[(i * 4) - 1].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 1].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 1].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 1].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 2].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 2].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 2].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 2].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 3].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 3].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 3].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 3].position == compare[(j * 4) - 4].position)
											matches++;
										if (testCopy[(i * 4) - 4].position == compare[(j * 4) - 1].position || testCopy[(i * 4) - 4].position == compare[(j * 4) - 2].position ||
											testCopy[(i * 4) - 4].position == compare[(j * 4) - 3].position || testCopy[(i * 4) - 4].position == compare[(j * 4) - 4].position)
											matches++;
										if (matches >= 3) {
											pieceKick = true;
											break;
										}
									}
								}
							}
						}
					}
				}
				// End of testing Here if a kick is still needed after all 5 cases (I.E. the piece will be obstructed no matter what) then the rotation doesn't happen)
				if (pieceKick == false && wallKick == false) {
					rotation += rotate;
					if (rotation == 5)
						rotation = 1;
					else if (rotation == 0)
						rotation = 4;
					shape = testCopy;
					origin = testOrigin;
					break;
				}
				test++;
			}

			
		}

	}

	void moveDown(float y, int clearRow = -1) {
		if (clearRow != -1) {
			for (size_t i = 0; i < shape.size(); i++) {
				if (shape[i].position.y < clearRow )
					shape[i].position.y += y;
			}
		}
		else if (clearRow == -1) {
			for (size_t i = 0; i < shape.size(); i++) {
				shape[i].position.y += y;
			}
			origin.y += y;
		}
	}

	void moveHorizontal(float x, int dir) {
		if (!locked) {
			for (size_t i = 0; i < shape.size(); i++) {
				shape[i].position.x += (x * dir);
			}
			origin.x += (x * dir);
		}
	}

	int findPoints(sf::Vector2f point, int prevGroup = -1) {
		for (size_t i = 0; i < shape.size(); i++) {
			
			if (shape[i].position == point) {
				if (i >= 0 && i <= 3 && prevGroup != 0)
					return 0;
				if (i >= 4 && i <= 7 && prevGroup != 1)
					return 1;
				if (i >= 8 && i <= 11 && prevGroup != 2)
					return 2;
				if (i >= 12 && i <= 15 && prevGroup != 3)
					return 3;
			}
		}
		return -1;
	}

	int deletePoints(int vGroup) {
		for (int i = 0; i < 4; i++) {
			shape.erase(shape.begin() + (vGroup * 4));
		}
		if (shape.empty() == true)
			return 1;
		return 0;
	}

	void lock(bool lock) {
		locked = lock;
	}

	auto getType() {
		return type;
	}

	auto getLowestYPoints() {
		std::vector<float> yPoints;
		float lowest = 0.f;
		for (int i = 0; i < 16; i++) {
			if (shape[i].position.y > lowest)
				lowest = shape[i].position.y;
		}
		yPoints.push_back(lowest);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 16; j++) {
				if (shape[j].position.y == yPoints[i] - 32) {
					yPoints.push_back(shape[j].position.y);
					break;
				}
				if (j == 15 && yPoints.size() == (i + 1))
					return yPoints;
			}
		}
		return yPoints;
	}

	int getSize() {
		return shape.size();
	}

	auto& getRotation() {
		return rotation;
	}

	std::vector<sf::Vertex>& getShape() {
		return shape;
	};


	// Function I made to get a string of every vertex in shape to see how the rotation affected them
	/*std::string getCoords() {
		std::string positions = "";
		for (int i = 0; i < shape.getVertexCount(); i++) {
			positions += std::to_string(shape[i].position.x) + " , " + std::to_string(shape[i].position.y) + "\n";
		}
		return positions;
	}*/
};

int checkRowComplete(int& obj, std::vector<Tetrimino*>& pieces) {
	 auto y = pieces[obj]->getLowestYPoints();
	 int clearedLines = 0;

	 for (size_t possibleLines = 0; possibleLines < y.size(); possibleLines++) {
		if (y[possibleLines] == 30) {
			auto test = pieces[obj]->getShape();
			for (sf::Vertex v : test) {
				v.position.y -= 30.f;
			}
			if (pieces[obj]->checkMoveCollision(0, pieces) != 0) 
				return -1;
		}
		std::vector<sf::Vector2f> completeLine = { {100, y[possibleLines]}, {132, y[possibleLines]}, {164, y[possibleLines]}, {196, y[possibleLines]}, {228, y[possibleLines]},  
												 {260, y[possibleLines]}, {292, y[possibleLines]}, {324, y[possibleLines]}, {356, y[possibleLines]}, {388, y[possibleLines]} }; //{400, 600} };
		std::vector<int> elementm;
		std::vector<int> vGroup;
		if (pieces.size() > 2) {
			for (size_t i = 0; completeLine.size() >= 0 && i < pieces.size(); i++) {
				int previousGroup = -1;
				for (size_t j = 0; j < completeLine.size();) {
					int result = pieces[i]->findPoints(completeLine[j], previousGroup);
					if (result != -1) {
						elementm.push_back(i);
						vGroup.push_back(result);
						completeLine.erase(completeLine.begin() + j);
						previousGroup = result;
					}
					else
						j++;
				}
			}
			if (completeLine.empty() == true) {
				for (size_t i = 0; i < vGroup.size(); i++) {
					if (pieces[elementm[i]]->deletePoints(vGroup[i]) == 1) {
						delete pieces[elementm[i]];
						pieces.erase(pieces.begin() + elementm[i]);
						obj--;
						for (size_t j = 0; j < elementm.size(); j++) {
							if (elementm[j] > elementm[i])
								elementm[j]--;
						}
					}
					else {
						for (size_t j = i + 1; j < vGroup.size(); j++) {
							if (elementm[j] == elementm[i] && vGroup[j] > vGroup[i])
								vGroup[j]--;
						}
					}
					//bruh
				}
				clearedLines++;
				elementm.clear();
				for (Tetrimino* piece : pieces) {
					piece->moveDown(32, y[possibleLines]);
				}
				for (size_t i = 0; i < y.size(); i++) {
					y[i] += 32;
				}

			}
		}
	 }
	 return clearedLines;
}

int sevenBag(std::vector<int>& bag, int lastPiece) {
	while (true) {
		int index;
		if (bag.size() > 1) 
			index = rand() % (bag.size() - 1);
		else if (bag.size() <= 1)
			index = 0;
		std::shuffle(bag.begin(), bag.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
		if (bag[index] != lastPiece) {
			int piece = bag[index];
			bag.erase(bag.begin() + index);
			return piece;
		}
	}
}

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(550, 675), "Tetris", sf::Style::Close);
	sf::Window window;
	gameWindow.setFramerateLimit(60);
	bool gameStop = 0;
	sf::Vertex leftBound[] = {
		sf::Vertex(sf::Vector2f(100.f, 0.f)),
		sf::Vertex(sf::Vector2f(100.f, 638.f))
	};
	sf::Vertex rightBound[] = {
		sf::Vertex(sf::Vector2f(418.f, 0.f)),
		sf::Vertex(sf::Vector2f(418.f, 638.f))
	};
	sf::Vertex bottom[] = {
		sf::Vertex(sf::Vector2f(100.f, 638.f)),
		sf::Vertex(sf::Vector2f(418.f, 638.f))
	};
	int frame = 0;
	int obj = 0;
	int lines = 0;
	int score = 0;
	int rotateClockNotPressed = 0;
	int rotateCounterNotPressed = 0;
	std::string horizontalPressed = "none";
	int count = 0;
	int last;
	sf::Clock clock;
	sf::Text scoreText;
	sf::Font font;
	std::vector<int> bag = { 0, 1, 2, 3, 4, 5, 6 };
	font.loadFromFile("comic.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(25);
	scoreText.setPosition(250.f, 640.f);
	scoreText.setString('0');

	//std::ofstream ofile("vertices.txt");
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	rand();

	std::vector<Tetrimino*> pieces;
	pieces.push_back(new Tetrimino(sevenBag(bag, -1)));
	last = pieces[obj]->getType();
	//pieces[obj]->moveDown();

	// Set up game loop and exit condition
	while (gameWindow.isOpen()) {
		lines = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) == true && frame % 5 == 0) {
			for (size_t i = 0; i < pieces.size();) {
				delete pieces[i];
				pieces.erase(pieces.begin(), pieces.begin() + 1);
			}
			obj = 0;
			pieces.push_back(new Tetrimino(rand() % 7));
		}
		if ((frame % 40 == 0 && gameStop == false) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && frame % 5 == 0 && gameStop == false)) {
			//ofile << piece->getCoords();
			if (pieces[obj]->checkMoveCollision(0, pieces) == 0)
				pieces[obj]->moveDown(32);
			else {
				pieces[obj]->lock(true);
				lines = checkRowComplete(obj, pieces);
				if (lines == -1) {
					gameStop = true;

				}
				else {
					switch (lines) {
					case 1:
						score += 40;
						break;
					case 2:
						score += 100;
						break;
					case 3:
						score += 300;
						break;
					case 4:
						score += 1200;
						break;
					default:
						break;
					}
					scoreText.setString(std::to_string(score));
					if (bag.empty())
						bag = { 0, 1, 2, 3, 4, 5, 6 };
					pieces.push_back(new Tetrimino(sevenBag(bag, last)));
					obj++;
					last = pieces[obj]->getType();
				}
			}
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			rotateClockNotPressed = 0;
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			rotateCounterNotPressed = 0;

		sf::Event event;
		while (gameWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				//ofile.close();
				for (size_t i = 0; i < pieces.size();) {
					delete pieces[i];
					pieces.erase(pieces.begin(), pieces.begin() + 1);
				}
				gameWindow.close();
				return 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && horizontalPressed == "none") {
			horizontalPressed = "left";
			if (pieces[obj]->checkMoveCollision(-1, pieces) == 0)
				pieces[obj]->moveHorizontal(32, -1);
		} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && horizontalPressed == "none") {
			horizontalPressed = "right";
			if (pieces[obj]->checkMoveCollision(1, pieces) == 0)
				pieces[obj]->moveHorizontal(32, 1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && rotateClockNotPressed == 0 && gameStop == false) {
			rotateClockNotPressed = -1;
			pieces[obj]->rotate(-1, pieces);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && rotateCounterNotPressed <= 0 && gameStop == false) {
			rotateCounterNotPressed = 1;
			pieces[obj]->rotate(1, pieces);
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && horizontalPressed == "right") {
			if (count == 10)
				pieces[obj]->moveAll(-1);
			count++;
		}*/

		if (horizontalPressed == "right" && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			horizontalPressed = "none";
			count = 0;
		}
		else if (horizontalPressed == "left" && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			horizontalPressed = "none";
			count = 0;
		}
		if (frame == 60) {
			frame = 0;
		}
		// Do stuff here
		gameWindow.clear();
		gameWindow.draw(scoreText);
		for (size_t i = 0; i < pieces.size(); i++) {
			gameWindow.draw(&pieces[i]->getShape()[0], pieces[i]->getSize() , sf::Quads);
		}
		gameWindow.draw(leftBound, 2, sf::Lines);
		gameWindow.draw(rightBound, 2, sf::Lines);
		gameWindow.draw(bottom, 2, sf::Lines);
		gameWindow.display();
		frame++;
	}

	return 0;
}

Tetrimino::~Tetrimino()
{
}