import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Oblig16 extends JFrame implements ActionListener{
	
	public JTextField tekst = new JTextField("Skriv valuta.");
	public String[] fraValuta = {"","NOK","USD","YEN"};
	public String[] tilValuta = {"","NOK","USD","YEN"};
	public JComboBox JCBfra = new JComboBox(fraValuta);
	public JComboBox JCBtil = new JComboBox(tilValuta);
	public JTextField resultat = new JTextField("Resultatet kommer her.");
	
	public Oblig16()
	{
		this.setLayout(new FlowLayout());
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(400, 200);
		
		this.add(JCBfra);
		this.add(tekst);
		this.add(JCBtil);
		this.add(resultat);
		
		tekst.setEditable(true);
		tekst.addActionListener(this);
		JCBfra.addActionListener(this);
		JCBtil.addActionListener(this);
	}
	
	public double konverterTilEuro(double innsum,int innvaluta)
	{
		if(innvaluta == 1)//nok
		{
			return innsum*0.10377367;
		}
		
		else if(innvaluta == 2)//usd
		{
			return innsum*0.897424392;
		}
		
		else if(innvaluta == 3)//yen
		{
			return innsum*0.0078255407;
		}
		else
		{
			return 0;
		}
	}	
	
	public double konverterFraEuro(double utsum,int utvaluta)
	{
		if(utvaluta == 1)//nok
		{
			return utsum*9.63635577;
		}
		
		else if(utvaluta == 2)//usd
		{
			return utsum*1.1143;
		}
		
		else if(utvaluta == 3)//yen
		{
			return utsum*127.786697;
		}
		else
		{
			return 0;
		}
	}
	
	public double konverter(double sum,int valuta)
	{
		double innverdi = konverterTilEuro(sum,valuta);
		//System.out.println(innverdi);
		double utverdi = konverterFraEuro(innverdi,JCBtil.getSelectedIndex());
		//System.out.println(utverdi);
		resultat.setText("= " +utverdi);
		
		return 0;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		if(e.getSource().equals(tekst))
		{
			konverter(Double.parseDouble(tekst.getText()), JCBfra.getSelectedIndex());
		}
	}
	
	//STOPP
}
