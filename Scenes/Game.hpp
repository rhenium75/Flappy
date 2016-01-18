#pragma once
#include<Siv3D.hpp>
# include <HamFramework.hpp>
# include <cmath>
#include"../Flappy.hpp"

class Block{
	public:
	Rect UpRect, DownRect;
	Block(double UpY,double DownY){
		UpRect = Rect(400,-UpY,80,640);
		DownRect = Rect(400,DownY,80,640);
	}
	void update(){

	}
	void draw(){
		UpRect.draw();
		DownRect.draw();
	}
};

struct Game : MyApp::Scene{

	Vec2 PlayerPos;
	Vec2 PlayerMove;
	int Time;
	Array<Block> blocks;

	void init() override{
		PlayerPos = Vec2(30,560);
		PlayerMove = Vec2(0,0);
		Time = 0;
		blocks.push_back(Block(100, 200));
	}

	void update() override{
		Time += 4;
		//y = Clamp((int)(y-v),0,640);
		PlayerPos += PlayerMove;
		PlayerMove.moveBy(0,-0.5);
		if (Input::MouseL.clicked){
			PlayerMove.set(PlayerMove.x,10);
		}
		if (Time % 30 == 0) m_data->score += 10;
		if (PlayerPos.y < 50) changeScene(L"Result");
		for (auto block : blocks){
			block.update();
			
		}
	}

	void draw()const override{
		TextureAsset(L"Sky").draw();
		TextureAsset(L"Cloud").draw(480 - fmod(Time/4., 1928), 0);
		TextureAsset(L"Cloud").draw(480 - fmod(Time/4.+964, 1928), 0);
		TextureAsset(L"Hakka1").draw(PlayerPos.x,640-PlayerPos.y);
		TextureAsset(L"Ground").draw(480 - fmod(Time, 1928), 0);
		TextureAsset(L"Ground").draw(480 - fmod(Time+964, 1928), 0);
		(FontAsset(L"Font"))(L"SCORE:" + Format(m_data->score)).draw(100, 30);
		for (auto block : blocks){
			block.draw();
		}
	}

};