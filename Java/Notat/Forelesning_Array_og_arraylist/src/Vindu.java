import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;

import javax.swing.JFrame;

public class Vindu extends JFrame{

	ArrayList<Point> punkter = new ArrayList<Point>();
	
	public Vindu()
	{
		this.setVisible(true);
		Point p1 = new Point();
		p1.x = 60;
		p1.y = 60;
		this.punkter.add(p1);
		
		Point p2 = new Point();
		p2.x = 100;
		p2.y = 100;
		this.punkter.add(p2);
	}
	@Override
	public void paint(Graphics g){
	super.paint(g);
	Point etpunkt = punkter.get(0);
	g.fillRect(etpunkt.x, etpunkt.y, 10, 10);
	
	Point etpunkt1 = punkter.get(1);
	g.fillRect(etpunkt1.x, etpunkt1.y, 10, 10);
	}
}
