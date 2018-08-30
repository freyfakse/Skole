import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Oblig12GUI extends JFrame implements ActionListener{

	ArrayList<JTextField> kryssordbrett = new ArrayList<JTextField>();
	JMenuBar Menubar = new JMenuBar();
	JMenu fil = new JMenu("Fil");
	JMenuItem nyttspill = new JMenuItem("Nytt spill");
	JMenuItem slett = new JMenuItem("Slett");
	
	
	
	public Oblig12GUI()
	{
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new GridLayout(9,9));
		
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0;j < 9;j++)
			{
				JTextField f = new JTextField();
				this.add(f);
				this.kryssordbrett.add(f);
			}
		}
		
		this.setJMenuBar(Menubar);
		this.Menubar.add(fil);
		this.fil.add(nyttspill);
		this.fil.add(slett);
		
		nyttspill.addActionListener(this);
		slett.addActionListener(this);
		
	}
	
	public void hverAndreBlank()
	{
		Random rg = new Random();
		for(JTextField felt:this.kryssordbrett)
		{
			if(rg.nextInt(2)==0)
			{
				felt.setText("");
				felt.setEditable(false);
			}
		}
	}
	
	public void hverTredjeBlank()
	{
		Random rg = new Random();
		for(JTextField felt:this.kryssordbrett)
		{
			if(rg.nextInt(3)==0)
			{
				felt.setText("");
				felt.setEditable(false);
			}
		}
	}
	
	public void hverFjerdeBlank()
	{
		Random rg = new Random();
		for(JTextField felt:this.kryssordbrett)
		{
			if(rg.nextInt(4)==0)
			{
				felt.setText("");
				felt.setEditable(false);
			}
		}
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(nyttspill))
		{
			String vanskelighetsgrad = JOptionPane.showInputDialog("1-3");
			int level = Integer.parseInt(vanskelighetsgrad);
			
			Random rg = new Random();
			for(JTextField felt:this.kryssordbrett)
			{
				felt.setText(Integer.toString(1+rg.nextInt(9)));
			}
			if(level == 1)
			{
				hverAndreBlank();
			}
			
			
			if(level == 2)
			{
				hverTredjeBlank();
			}
			
			if(level == 3)
			{
				hverFjerdeBlank();
			}
			
		}
		
		if(e.getSource().equals(slett))
		{
			for(JTextField felt:this.kryssordbrett)
			{
				felt.setText("");
			}
		}
	}
	
}
