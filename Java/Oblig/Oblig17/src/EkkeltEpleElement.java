import java.awt.Color;
import java.util.Random;

public class EkkeltEpleElement extends GrafikkElement{

	public EkkeltEpleElement()
	{
		Random rg = new Random();
		this.setX(100);
		this.setY(-100);
		this.setBredde(20);
		this.setHoyde(20);
		this.setFarge(Color.GREEN);
	}
}
