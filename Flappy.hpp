#pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>

struct GameData{
	int score;
};
using MyApp = SceneManager < String, GameData >;