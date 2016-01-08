#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../Flappy.hpp"

struct Result : MyApp::Scene{
	Font font;
	void init()override{ font = Font(10); }
	void update()override{
		if (Input::MouseL.clicked) changeScene(L"Title");
	}
	void draw()const override{
		font(Format(m_data->score)).draw();
	}
};
