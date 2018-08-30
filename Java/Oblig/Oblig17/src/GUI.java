import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.Timer;

public class GUI extends JFrame implements KeyListener,ActionListener{

	//Offentlige variabler
	public KurvElement kurv = new KurvElement();
	public FintEpleElement finteple = new FintEpleElement();
	public EkkeltEpleElement ekkelteple = new EkkeltEpleElement();
	public ArrayList<FintEpleElement> FintEpleArray = new ArrayList<FintEpleElement>();
	public ArrayList<EkkeltEpleElement> EkkeltEpleArray = new ArrayList<EkkeltEpleElement>();
	
	public int hjelp1 = 0;
	public int hjelp2 = 0;
	public int teller = 10;
	
	public int score = 0;
	public DefaultListModel m = new DefaultListModel();
	public JList HS = new JList(m);
	public JTextField poeng = new JTextField(score);
	public HiScore t = new HiScore();
	
	public Timer Render = new Timer(10,null);
	public Timer Forflytter = new Timer(50, null);
	public Timer Spawner = new Timer(800, null);
	
	public Random rg = new Random();
	
	//Vindu
	public GUI()
	{
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		this.setTitle("Kurwa");
		this.setSize(1920,1080);
		
		this.add(poeng);
		load();
		
		Render.start();
		Render.addActionListener(this);
		Forflytter.start();
		Forflytter.addActionListener(this);
		Spawner.start();
		Spawner.addActionListener(this);
		
		this.addKeyListener(this);
	}
	
	public void game_over()
	{
		JOptionPane.showMessageDialog(null, "Game Over");
		save();
		Spawner.stop();
	}
	
	//Laste HS
	public void load()
	{
		try {
			FileInputStream f = new FileInputStream("High Score.txt");
			ObjectInputStream o = new ObjectInputStream(f);
			this.m = (DefaultListModel) o.readObject();
			HS.setModel(m);
			
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (ClassNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	//Lagre HS
	public void save()
	{
		try {
			FileOutputStream f = new FileOutputStream("High Score.txt");
			ObjectOutputStream o = new ObjectOutputStream(f);
			o.writeObject(this.m);
			o.close();
			f.close();
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	//Sjekker for kollisjon
	public void sjekkKollisjon()
	{
		Rectangle r1 = new Rectangle(kurv.getX(),kurv.getY(),kurv.getBredde(),kurv.getHoyde());
		
		for(int i=0; i<FintEpleArray.size();i++)
		{
			
			Rectangle r2 = new Rectangle(FintEpleArray.get(i).getX(),FintEpleArray.get(i).getY(),FintEpleArray.get(i).getBredde(),FintEpleArray.get(i).getHoyde());
			
			if(r2.intersects(r1))
			{
				score = score + 2;
				FintEpleArray.remove(i);
			}
		}
		
		for(int i=0;i<EkkeltEpleArray.size();i++)
		{
			Rectangle r3 = new Rectangle(EkkeltEpleArray.get(i).getX(),EkkeltEpleArray.get(i).getY(),EkkeltEpleArray.get(i).getBredde(),EkkeltEpleArray.get(i).getHoyde());
			
			if(r3.intersects(r1))
			{
				score = score - 1;
				EkkeltEpleArray.remove(i);
			}
		}
	}
	
	//Tegner elementene. Kobler sammen HiScore og GUI
	public void drawStuff()
	{
		Graphics g = this.getGraphics();
		g.clearRect(0, 0, this.getWidth(), this.getHeight());
		
		for(FintEpleElement fintepler:FintEpleArray)
		{
			fintepler.drawMe(g);
			
		}
		
		for(EkkeltEpleElement ekkeltepler:EkkeltEpleArray)
		{
			ekkeltepler.drawMe(g);
		}
		
		this.kurv.drawMe(g);
		
		if(hjelp1 == 0)
		{
			hjelp1 = 1;
			t.setNavn(JOptionPane.showInputDialog("Navn"));
			if(t.getNavn().equals(""))
			{
				t.setNavn("Ingvar Cognito");
			}
		}
		
		t.setPoengsum(score);
		m.addElement(t);
		
		g.drawString("Navn: " +t.getNavn(), 10, 50);
		g.drawString("Poeng: " +Integer.toString(score), 10, 60);
		g.drawString("Epler" +Integer.toString(teller), 10, 70);
	}
	
	//Forflytter eplene nedover
	public void beveger()
	{
		for (int i = 0; i <	FintEpleArray.size(); i++)
		{
			FintEpleArray.get(i).setY(FintEpleArray.get(i).getY()+10);
		}
		
		for (int i = 0; i < EkkeltEpleArray.size(); i++)
		{
			EkkeltEpleArray.get(i).setY(EkkeltEpleArray.get(i).getY()+10);
		}
	}
	
	//Setter ut nye epler
	public void spawner()
	{
		if(rg.nextInt(10)<5)
		{
			FintEpleElement fe = new FintEpleElement();
			fe.setX(rg.nextInt(1700)+100);
			FintEpleArray.add(fe);
			teller --;
		}
		
		if(rg.nextInt(10)>=5)
		{
			EkkeltEpleElement ee = new EkkeltEpleElement();
			ee.setX(rg.nextInt(1700)+100);
			EkkeltEpleArray.add(ee);
		}
		
		if(teller==0)
		{
			game_over();
		}
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(Forflytter))
		{
			beveger();
		}
		
		if(e.getSource().equals(Spawner))
		{
			spawner();
		}
		
		if(e.getSource().equals(Render))
		{
			drawStuff();
			sjekkKollisjon();
		}
	}
	
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub

		if(e.getKeyCode()==KeyEvent.VK_LEFT)
		{
			kurv.setX(kurv.getX()-20);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_RIGHT)
		{
			kurv.setX(kurv.getX()+20);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_UP)
		{
			kurv.setY(kurv.getY()-20);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_DOWN)
		{
			kurv.setY(kurv.getY()+20);
		}
		
		if(e.getKeyCode()==KeyEvent.VK_H)
		{
			HiScoreGUI h = new HiScoreGUI();
			
			if(hjelp2 == 0)
			{
				
				hjelp2 = 1;
			}
			
			if(hjelp2 == 1)
			{
				
				hjelp2 = 0;
			}
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
	
	//Slutt
}
