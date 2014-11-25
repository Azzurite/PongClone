/** @file
 *
 * \date 27.01.2014
 * \author ttue
 *
 * \copyright GPL v3
 */

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "SDL.h"

#include "Game.h"

class SDLQuitEnv : public testing::Environment
{
public:
	virtual ~SDLQuitEnv() noexcept = default;

	virtual void SetUp() override {}

	virtual void TearDown() override
	{
		SDL_Quit();
	}
};

int main(int argc, char** argv) {
	testing::InitGoogleMock(&argc, argv);
	auto sdlQuit = SDLQuitEnv{};
	testing::AddGlobalTestEnvironment(&sdlQuit);
	return RUN_ALL_TESTS();
}
