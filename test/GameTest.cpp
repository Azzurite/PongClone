/*! @file
 *
 * @date 19.02.2014
 * @author Timo
 *
 * @copyright GPL v3
 */

#include "Game.h"

#include "SDL.h"
#include "SDL_ttf.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace pong {

class GameTest_UsesSDL : public ::testing::Test
{
public:
	GameTest_UsesSDL() {}

	virtual void SetUp() {}

	virtual ~GameTest_UsesSDL() {}

	virtual void TearDown() {}

};

TEST_F(GameTest_UsesSDL, Game_InitializesSDL)
{
	auto g = Game{};
	ASSERT_EQ(cUSED_SDL_SUBSYSTEMS, SDL_WasInit(cUSED_SDL_SUBSYSTEMS));
}

TEST_F(GameTest_UsesSDL, Game_InitializesTTF)
{
	auto g = Game{};
	ASSERT_EQ(1, TTF_WasInit());
}

TEST_F(GameTest_UsesSDL, Game_QuitsSDL)
{
	{
		auto g = Game{};
	} // when g is destroyed, SDL_Quit should be called
	ASSERT_EQ(0U, SDL_WasInit(0));
}

TEST_F(GameTest_UsesSDL, Game_QuitsTTF)
{
	{
		auto g = Game{};
	} // when g is destroyed, TTF_Quit should be called
	ASSERT_EQ(0, TTF_WasInit());
}

} // namespace pong
