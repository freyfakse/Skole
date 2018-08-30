import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Random;

import javax.swing.JFrame;

public class MittVindu extends JFrame implements MouseListener,MouseMotionListener{

	int stor=10;
	boolean opp = true;
	
	public MittVindu()
	{
		this.setVisible(true);
		
		//FlowLayout f = new FlowLayout();
		//this.setLayout(f);
		this.setLayout(new FlowLayout());
		
		this.addMouseListener(this);
		this.addMouseMotionListener(this);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		Graphics g = this.getGraphics();
		//Color c = new Color(255,0,0);
		g.setColor(new Color(255,0,0));
		
		int x = e.getX();
		int y = e.getY();
		//g.drawString("Jeg var her", x, y);
		g.fillOval(x, y, 100, 100);
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		Graphics g = this.getGraphics();
		
		Random rg = new Random();
		
		g.setColor(new Color(rg.nextInt(255),rg.nextInt(255),rg.nextInt(255)));
		g.fillOval(e.getX(), e.getY(), this.stor, this.stor);
		
		if(this.stor==50)
		{
			this.opp = false;
		}
		
		if(this.stor==10)
		{
			this.opp = true;
		}
		
		
		if(this.opp==true)
		{
			this.stor++;
		}
		else
		{
			this.stor--;
		}
		
	}

	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
