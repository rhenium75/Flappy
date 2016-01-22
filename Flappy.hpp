#pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>

struct GameData{
	int score;
	Image Result_Back;
};

using MyApp = SceneManager < String, GameData >;