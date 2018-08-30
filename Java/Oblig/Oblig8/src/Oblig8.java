import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;


public class Oblig8 extends JFrame implements ActionListener{

	JButton knapp1 = new JButton();
	JButton knapp2 = new JButton();
	int svar1 = 4;
	int svar2 = 5;
	
	public Oblig8()
	{
		this.setVisible(true);
		GridLayout g = new GridLayout(1,2);
		this.setLayout(g);
		
		knapp1.setText("Spiller 1");
		this.add(knapp1);
		knapp1.addActionListener(this);
		
		knapp2.setText("Spiller 2");
		this.add(knapp2);
		knapp2.addActionListener(this);
	}
	
	@Override
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource().equals(knapp1))
		{
			JOptionPane.showMessageDialog(this, "Spiller 1 har trykket");
			
			String[] spill = new String[3];
			spill[0] = "Stein";
			spill[1] = "Saks";
			spill[2] = "Papir";
			
			svar1 = JOptionPane.showOptionDialog (null,"Velg","Stein, saks, papir",0,0,null,spill,spill[0]);
		}
		
		if(e.getSource().equals(knapp2))
		{
			JOptionPane.showMessageDialog(this, "Spiller 2 har trykket");
			
			String[] spill = new String[3];
			spill[0] = "Stein";
			spill[1] = "Saks";
			spill[2] = "Papir";
			
			svar2 = JOptionPane.showOptionDialog (null,"Velg","Stein, saks, papir",0,0,null,spill,spill[0]);
		}
		
		if(svar1==svar2)
		{
			JOptionPane.showMessageDialog(null, "Uavgjort");
		}
		
		else if(svar1==0 && svar2==1 || svar1==1 && svar2==2 || svar1==2 && svar2==0)
		{
			JOptionPane.showMessageDialog(null, "Spiller 1 vinner.");
		}
		
		else if(svar1==1 && svar2==0 || svar1==2 && svar2==1 || svar1==0 && svar2==2)
		{
			JOptionPane.showMessageDialog(null, "Spiller 2 vinner.");
		}
	}
}
