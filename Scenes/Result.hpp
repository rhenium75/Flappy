#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../Flappy.hpp"

struct Result : MyApp::Scene{
	DynamicTexture texture;
	int frameCount;
	Rect TweetButton;

	void init()override{
		texture.fill(m_data->Result_Back);
		TweetButton = Rect(140,295,200,50);
	}

	void update()override{
		frameCount++;
		if (frameCount > 10 && Input::MouseL.clicked) {
			if (TweetButton.mouseOver) {
				Twitter::OpenTweetWindow(L"TestScore:"+Format(m_data->score));
			}
			//changeScene(L"Title");
		}
	}

	void draw()const override{
		texture.draw();
		TextureAsset(L"Window").scale(Min(frameCount,10)/10.,Min(frameCount,10)/10.).drawAt(240, 320);
		(TweetButton.scaled(Min(frameCount, 10) / 10., Min(frameCount, 10) / 10.))(TextureAsset(L"Button")).draw();
		if (frameCount > 10) {
			(FontAsset(L"Font"))(L"Score"+Format(m_data->score)).draw(100,100);
		}
	}

};
