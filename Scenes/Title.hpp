#pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "../Flappy.hpp"

struct Title : MyApp::Scene{
	void init() override{}
	void update() override{
		if (Input::MouseL.clicked){
			changeScene(L"Game");
		}
	}
	void draw()const override{

	}
};