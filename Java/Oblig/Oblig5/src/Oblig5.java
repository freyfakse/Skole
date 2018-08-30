
public class Oblig5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Game spill = new Game();
		
		Character bg = new Character();
		bg.setImage("http://188.138.32.138/dat101/filer/background.jpg");
		spill.addCharacter(bg,"background");
		
		Character hero = new Character();
		hero.setImage("http://188.138.32.138/dat101/filer/mario.png");
		spill.addCharacter(hero,"hero");
		
		hero.x = 50;
		hero.y = 400;
		hero.resize(2);
		
		
		Character princess = new Character();
		princess.setImage("http://188.138.32.138/dat101/filer/princess.jpg");
		spill.addCharacter(princess, "princess");
		
		princess.x = 1300;
		princess.y = 200;
		princess.resize(0.5);
		
	}

}
