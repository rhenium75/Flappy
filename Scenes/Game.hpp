#pragma once
#include<Siv3D.hpp>
# include <HamFramework.hpp>
# include <cmath>
#include"../Flappy.hpp"

class Block{
	public:
	Rect UpRect, DownRect;
	Block(double UpY,double DownY){
		UpRect = Rect(480,-640+UpY,80,640);
		DownRect = Rect(480,DownY,80,640);
	}
	void update(){
		UpRect.moveBy(-3,0);
		DownRect.moveBy(-3 ,0);

	}
	void draw(){
		UpRect.draw(Palette::Green);
		DownRect.draw(Palette::Green);
	}
};

class Player{
public:
	Circle body;
	Vec2 Move;
	Player(){
		body.setPos(30,560);
		body.setSize(100);
		Move = Vec2(0,0);
	}
	virtual void update(){
		body.moveBy(Move);
		Move.moveBy(0,-0.5);
		if (Input::MouseL.clicked){
			Move.set(Move.x, 10);
		}
	}
	virtual void draw() const {
		TextureAsset(L"Hakka1").draw(body.x, 640 - body.y);
	}
	bool IsDeath(){
		return body.y < 50;
	}
};

struct Game : MyApp::Scene{

	Player player;
	int Time;
	Array<Block> blocks;

	void init() override{
		player = Player();
		Time = 0;
	}

	void update() override{
		Time += 4;
		float a = Random(300);
		if (Time % 480 == 0) blocks.push_back(Block(a, a+100));
		player.update();
		if (Time % 30 == 0) m_data->score += 10;
		if (player.IsDeath()) changeScene(L"Result");
		for (int i = 0; i < blocks.size();i++){
			blocks[i].update();
		}
	}

	void draw()const override{
		TextureAsset(L"Sky").draw();
		TextureAsset(L"Cloud").draw(480 - fmod(Time/4., 1928), 0);
		TextureAsset(L"Cloud").draw(480 - fmod(Time/4.+964, 1928), 0);
		player.draw();
		for (auto block : blocks) block.draw();
		TextureAsset(L"Ground").draw(480 - fmod(Time, 1928), 0);
		TextureAsset(L"Ground").draw(480 - fmod(Time+964, 1928), 0);
		(FontAsset(L"Font"))(L"SCORE:" + Format(m_data->score)).draw(100, 30);
	}

};