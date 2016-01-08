
# include <Siv3D.hpp>

struct GameObject{
	double x;
	double y;
	GameObject(double _x,double _y){
		x = _x;
		y = _y;
	}
};

void Main(){
	const Font font(30);
	
	struct GameObject Player(100,100);

	while (System::Update()){
		Player.x = Mouse::Pos().x;
		Player.y = Mouse::Pos().y;
		Circle(Player.x,Player.y, 50).draw({ 255, 0, 0, 127 });
	}
}
