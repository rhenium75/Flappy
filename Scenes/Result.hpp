#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../Flappy.hpp"

struct Result : MyApp::Scene{
	
	void init()override{
	}

	void update()override{
		if (Input::MouseL.clicked) changeScene(L"Title");
	}

	void draw()const override{
		FontAsset(L"Font").draw(Format(m_data->score));
	}

};
