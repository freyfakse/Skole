import java.awt.Color;
import java.awt.GridLayout;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class Kryssord extends JFrame{

	final int bredde_i_bokstaver = 20;
	final int hoyde_i_bokstaver = 20;
	ArrayList<JTextField> kryssordbrett = new ArrayList<JTextField>();
	
	public Kryssord()
	{
		this.setLayout(new GridLayout(bredde_i_bokstaver,hoyde_i_bokstaver));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		
		for(int i = 0;i < bredde_i_bokstaver;i++)
		{
			for(int j = 0;j < hoyde_i_bokstaver;j++)
			{
				//JTextField f = new JTextField();
				blinkeKryssordFelt f = new blinkeKryssordFelt();
				this.add(f);
				this.kryssordbrett.add(f);
			}
		}
		
		this.hvertredjesvart();
		this.fyllUt();
		
	}
	
	public void fyllUt()
	{
		for(JTextField felt:this.kryssordbrett)
		{
			felt.setText("a");
		}
	}
	
	public void hvertredjesvart()
	{
		Random rg = new Random();
		for(JTextField felt:this.kryssordbrett)
		{
			if(rg.nextInt(3)==0)
			{
				felt.setBackground(Color.BLACK);
				felt.setEditable(false);
			}
		}
	}
	blinkeKryssordFelt f = new blinkeKryssordFelt();
}
