#pragma once
#include<Siv3D.hpp>
# include <HamFramework.hpp>
# include <cmath>
#include"../Flappy.hpp"

class ScreenShake : public IEffect
{
private:

	double m_maxOffset, m_lengthMillisec;

public:

	ScreenShake(double maxOffset, double lengthMillisec)
		: m_maxOffset(maxOffset)
		, m_lengthMillisec(lengthMillisec) {}

	bool update(double timeSec) override
	{
		const double timeMillisec = timeSec * 1000.0;

		const Vec2 offset = RandomVec2(Circle(m_maxOffset * Max(1.0 - timeMillisec / m_lengthMillisec, 0.0)));

		Graphics2D::SetTransform(Mat3x2::Translate(offset));

		return timeMillisec < m_lengthMillisec;
	}
};


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
	bool Death;
	Player(){
		body.setPos(60,80);
		body.setSize(40);
		Move = Vec2(0,0);
		Death = false;
	}
	virtual void update(){
		body.moveBy(Move);
		Move.moveBy(0,0.5);
		//Move.y = Min((int)Move.y,10);
		if (!IsDeath() && Input::MouseL.clicked){
			Move.set(Move.x, -10);
		}
	}
	virtual void draw() const {
		TextureAsset(L"Hakka1").rotate(HalfPi/20*Move.y).draw(body.x-55,body.y-40);
	}
	bool IsDeath(){
		return Death;
	}
	bool OnGround(){
		return body.y > 590;
	}
};

struct Game : MyApp::Scene{

	Player player;
	int Time;
	Array<Block> blocks;
	Effect effect;

	void init() override{
		player = Player();
		Time = 0;
	}

	void update() override{
		
		player.update();
		if (Time % 480 == 0) {
			float a = Random(300);
			blocks.push_back(Block(a, a + 200));
		}
		if (!player.IsDeath()) {
			Time += 4;
			for (int i = 0; i < blocks.size(); i++) {
				blocks[i].update();
			}
			for (int i = 0; i < blocks.size(); i++) {
				if (player.body.intersects(blocks[i].UpRect) || player.body.intersects(blocks[i].DownRect)) {
					player.Death = true;
					effect.add<ScreenShake>(16, 600);
				}
			}
		}

		if (Time % 30 == 0) m_data->score += 10;
		if (player.OnGround()) changeScene(L"Result");
	}

	void draw()const override{
		effect.update();
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