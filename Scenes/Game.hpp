#pragma once
#include<Siv3D.hpp>
# include <HamFramework.hpp>
#include"../Flappy.hpp"

struct Game : MyApp::Scene{
	double y, v;
	int frameCount;
	Font font;
	void init() override{
		y = 100;
		v = 0;
		frameCount = 0;
		font = Font(10);
	}
	void update() override{
		frameCount++;
		y = Clamp((int)(y-v),0,600);
		v -= 0.5;
		if (Input::MouseL.clicked) v = 10;
		if (frameCount % 30 == 0) m_data->score += 10;
		if (y > 500) changeScene(L"Result");
	}
	void draw()const override{
		Circle(100, y, 30).draw();
		font(L"SCORE:" + Format(m_data->score)).draw(100, 30);
	}
};
