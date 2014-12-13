/*! @file
 *
 * @date 27.01.2014
 * @author ttue
 *
 * @copyright GPL v3
 */

#include <iostream>
#include <limits>
#include <cstring>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "SDL.h"

#include "Game.h"

class SDLQuitEnv final : public testing::Environment
{
public:
	virtual ~SDLQuitEnv() noexcept = default;

	virtual void SetUp() override {}

	virtual void TearDown() override
	{
		SDL_Quit();
	}
};

bool willSDLTestsRun(int argc, char** argv)
{
	for (int i = 0; i != argc; ++i) {
		auto sdlInArg = strstr(argv[i], "-*SDL*") != nullptr;
		if (sdlInArg) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv)
{
	auto shouldQuitSdl = !willSDLTestsRun(argc, argv);
	testing::InitGoogleMock(&argc, argv);
	if (shouldQuitSdl) {
		std::cout << "should quit sql" << std::endl;
		testing::AddGlobalTestEnvironment(new SDLQuitEnv);
	}
	auto result = RUN_ALL_TESTS();
	std::cout << "Press enter to quit" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return result;
}
