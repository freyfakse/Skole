import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.Timer;

public class MittVindu extends JFrame implements ActionListener,KeyListener{

	int ypos = 0;
	
	public MittVindu()
	{
		
		FlowLayout f = new FlowLayout();
		this.setLayout(f);
		this.setVisible(true);
		
		/*
		JButton knapp = new JButton();
		knapp.setText("Trykk på meg.");
		this.add(knapp);
		knapp.addActionListener(this);
		*/
		Timer t = new Timer(10,this);
		t.start();
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.addKeyListener(this);
	}

	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		this.ypos = this.ypos +1;
		Random rg = new Random();
		Graphics g = this.getGraphics();
		/*
		for(int i = 500;i>0;i=i-10)
		{
			Color c = new Color(rg.nextInt(255),rg.nextInt(255),rg.nextInt(255));
			g.setColor(c);
			g.fillOval(300-i/2, 300-i/2, i, i);
		}
		*/
		//Graphics t = this.getGraphics();
		//Color c = new Color(rg.nextInt(255),rg.nextInt(255),rg.nextInt(255));
		Color c2 = new Color(0,0,0);
		g.setColor(c2);
		//g.fillOval(rg.nextInt(500), rg.nextInt(500), 100, 100);
		//t.setColor(c2);
		g.clearRect(0, 0, 5000, 5000);
		g.fillRect(200, ypos, 50, 50);
		
	}


	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		//JOptionPane.showMessageDialog(this, "Du trykket på en knapp");
		if(e.getKeyCode()==KeyEvent.VK_UP)
		{
			JOptionPane.showMessageDialog(this, "Du trykket på oppoverpil");
		}
	}


	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
