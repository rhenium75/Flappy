#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../Flappy.hpp"

struct Result : MyApp::Scene{
	DynamicTexture texture;
	int frameCount;
	Rect TweetButton;
	Rect TitleButton;
	Rect RetryButton;

	void init()override{
		texture.fill(m_data->Result_Back);
		RetryButton = Rect(140, 200, 200, 50);
		TweetButton = Rect(140,295,200,50);
		TitleButton = Rect(140,400,200,50);
	}

	void update()override{
		frameCount++;
		if (frameCount > 10) {
			if (RetryButton.leftClicked)
				changeScene(L"Game");
			if (TweetButton.leftClicked)
				Twitter::OpenTweetWindow(L"TestScore:"+Format(m_data->score));
			if (TitleButton.leftClicked)
				changeScene(L"Title");
		}
	}

	void draw()const override{
		texture.draw();
		TextureAsset(L"Window").scale(Min(frameCount,10)/10.,Min(frameCount,10)/10.).drawAt(240, 320);
		
		double Zoom = -2.5 * Max(0., 10. - frameCount);
		(RetryButton.stretched(Zoom))(TextureAsset(L"Button")).draw();
		(TweetButton.stretched(Zoom))(TextureAsset(L"Button")).draw();
		(TitleButton.stretched(Zoom))(TextureAsset(L"Button")).draw();
		
		if (frameCount > 10) {
			(FontAsset(L"Font"))(L"Score"+Format(m_data->score)).draw(100,100);
		}
	}

};
