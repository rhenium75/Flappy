
# include <Siv3D.hpp>
# include <HamFramework.hpp>
#include <algorithm>

struct GameData{
	int score;
};

using MyApp = SceneManager < String, GameData > ;

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
		y = std::max(0,std::min((int)(y-v),1000));
		v -= 0.5;
		if (Input::MouseL.clicked) v = 10;
		if (frameCount % 30 == 0) m_data->score+=10;
		if (y > 500) changeScene(L"Result");
	}
	void draw()const override{
		Circle(100, y, 30).draw();
		font(L"SCORE:"+Format(m_data->score)).draw(100,30);
	}
};

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

void Main(){

	MyApp manager(SceneManagerOption::ShowSceneName);

	manager.setFadeColor(Palette::Black);

	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");
	manager.init(L"Title");

	while (System::Update()){
		if (!manager.updateAndDraw()) break;
	}
}
