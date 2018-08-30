import java.awt.Color;
import java.util.Random;

public class blinkeKryssordFelt extends kryssordFelt {

	
	
	@Override
	public void start() {
		// TODO Auto-generated method stub
		Random rg = new Random();
		
		if(this.isEditable())
		this.setBackground(new Color(
									rg.nextInt(255),
									rg.nextInt(255),
									rg.nextInt(255)));
	}

}
