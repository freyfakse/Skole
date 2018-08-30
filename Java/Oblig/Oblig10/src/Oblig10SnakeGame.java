import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;

public class Oblig10SnakeGame extends JFrame implements KeyListener,ActionListener{
	
	public Oblig10SnakeElement slange = new Oblig10SnakeElement();

	public Oblig10SnakeGame()
	{
		this.addKeyListener(this);
		FlowLayout f = new FlowLayout();
		this.setSize(600, 600);
		this.setLayout(f);
		this.setTitle("Snake");
		
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void drawStuff()
	{
		Graphics g = this.getGraphics();
		g.clearRect(0, 0, this.getWidth(), this.getHeight());
		this.slange.drawMe(g);
	}

	
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		this.drawStuff();
		
		if(e.getKeyCode()==KeyEvent.VK_UP)
		{
			System.out.println("opp");
			slange.setY(slange.getY()-10);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_DOWN)
		{
			System.out.println("ned");
			slange.setY(slange.getY()+10);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_RIGHT)
		{
			System.out.println("høyre");
			slange.setX(slange.getX()+10);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_LEFT)
		{
			System.out.println("venstre");
			slange.setX(slange.getX()-10);
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

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}
