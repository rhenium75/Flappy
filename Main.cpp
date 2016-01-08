
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Flappy.hpp"
# include "Scenes.h"


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
