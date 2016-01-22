
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Flappy.hpp"
# include "Scenes.h"


void Main(){
	
	Window::SetTitle(L"Flappy Hakka 1.0");
	Window::Resize({480,640});

	MyApp manager;// (SceneManagerOption::ShowSceneName);
	manager.setFadeColor(Palette::Black);
	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");
	manager.init(L"Title");

	TextureAsset::Register(L"Title", L"Images/Title.png");
	TextureAsset::Register(L"Button", L"Images/Button.png");
	TextureAsset::Register(L"Window", L"Images/Window.png");
	TextureAsset::Register(L"Ground", L"Images/Ground.png");
	TextureAsset::Register(L"Cloud", L"Images/cloud.png");
	TextureAsset::Register(L"Sky", L"Images/Sky.png");
	TextureAsset::Register(L"Dokan", L"Images/Dokan.png");
	TextureAsset::Register(L"Hakka1", L"Images/Hakka1.png");
	TextureAsset::Register(L"Dokan", L"Images/Dokan.png");

	FontAsset::Register(L"Font",30);

	while (System::Update()){
		if (!manager.updateAndDraw()) break;
	}
}
