import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.Timer;

public class MittVindu extends JFrame implements ActionListener{
	
	public Fyrverkeri pew_pew = new Fyrverkeri();
	public Eksplosjon Boom = new Eksplosjon();
	
	public MittVindu()
	{
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		FlowLayout Flow = new FlowLayout();
		this.setLayout(Flow);
		this.setSize(1000, 1000);
		this.setBackground(Color.BLACK);
		
		Timer t = new Timer(1000,this);
		t.start();
	}

	public void drawStuff()
	{
		Graphics g =this.getGraphics();
		this.pew_pew.drawSquare(g);
		this.Boom.drawOval(g);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		pew_pew.setY(pew_pew.getY()-1);
	}

}
