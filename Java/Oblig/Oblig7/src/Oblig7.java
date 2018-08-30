import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.JFrame;

public class Oblig7 extends JFrame{
	
	public ArrayList<Point> punkter = new ArrayList<Point>();
	
	Random rg = new Random();
	
	
	public Oblig7()
	{
		this.setVisible(true);
		/*
		Point p0 = new Point();
		p0.x = 100;
		p0.y = 100;
		this.punkter.add(p0);
		
		Point p1 = new Point();
		p1.x = 200;
		p1.y = 200;
		this.punkter.add(p1);
		
		Point p2 = new Point();
		p2.x = 300;
		p2.y = 300;
		this.punkter.add(p2);
		
		Point p3 = new Point();
		p3.x = 400;
		p3.y = 400;
		this.punkter.add(p3);
		*/
		
		for (int i=0;i<100;i=i+1)
		{	
			
			Point p = new Point();
			int tall = rg.nextInt(1000);
			p.x = tall;
			int tall1 = rg.nextInt(1000);
			p.y = tall1;
			this.punkter.add(p);
		}
	}
	
	@Override
	public void paint(Graphics g){
	super.paint(g);
	
	for (int i=0;i<punkter.size();i=i+1)
	{
	Point etpunkt = punkter.get(i);
	g.fillOval(etpunkt.x, etpunkt.y, 10, 10);
	}
	
	for (int i=0;i<punkter.size();i=i+1)
	{
	Point venstrepunkt = punkter.get(i);
	g.fillOval(venstrepunkt.x-10, venstrepunkt.y, 10, 10);
	}
	
	}

}
