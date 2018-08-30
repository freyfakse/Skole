import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.Timer;

public class tetris extends JFrame implements ActionListener{

	boks b = new boks();
	
	public tetris()
	{
		this.setVisible(true);
		Timer t = new Timer(10,this);
		t.start();
	}
	
	public void tegnAlt()
	{
		Graphics g = this.getGraphics();
		g.clearRect(0, 0, 500, 500);
		this.b.tegnMeg(g);
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		this.b.setY(this.b.getY()+1);
		this.tegnAlt();
	}
}
