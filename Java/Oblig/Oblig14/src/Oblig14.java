import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;

public class Oblig14 extends JFrame implements ActionListener,Serializable{

	JButton knapp = new JButton("RNGesus");
	ArrayList<Integer> AL = new ArrayList<Integer>();
	public HashSet<Integer> LHS = new HashSet<Integer>();
	public TreeSet<Integer> TS = new TreeSet<Integer>();
	Random rg =new Random();
	
	JList list1 = new JList();
	JList list2 = new JList();
	JList list3 = new JList();
	
	JLabel tekst1 = new JLabel("Her er " +AL.size() +" tilfeldige tall.");
	JLabel tekst2 = new JLabel("Her er " +LHS.size() +" unike tall.");
	JLabel tekst3 = new JLabel("Her er " +TS.size() +" unike sorterte tall.");
	
	DefaultListModel DLM = new DefaultListModel();
	
	public Oblig14()
	{
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		
		this.add(knapp);
		knapp.addActionListener(this);
		
		this.add(tekst1);
		this.add(list1);
		this.add(tekst2);
		this.add(list2);
		this.add(tekst3);
		this.add(list3);
	}

	//ACTIONPERFORMED start
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(knapp))
		{
			String toInt = JOptionPane.showInputDialog("Skriv in antall tall som skal genereres.");
			int RNG = Integer.parseInt(toInt);
			
			AL.clear();
			LHS.clear();
			TS.clear();
			
			for(int i = 0;i<RNG;i++)
			{
				int tall=rg.nextInt(20)+1;
				AL.add(tall);
				LHS.add(tall);
				TS.add(tall);
			}
			
			this.oppdaterGUI(list1, AL.toArray());
			this.oppdaterGUI(list2, LHS.toArray());
			this.oppdaterGUI(list3, TS.toArray());
			
			tekst1.setText("Her er " +AL.size() +" tilfeldige tall.");
			tekst2.setText("Her er " +LHS.size() +" unike tall.");
			tekst3.setText("Her er " +TS.size() +" unike sorterte tall.");
			
			String svar = JOptionPane.showInputDialog("Vil du lagre?");
		    if (svar.equals("ja"))
		    {
		    	try {
		    		FileWriter f = new FileWriter("tall.txt");
		    		BufferedWriter bf = new BufferedWriter(f);
					bf.write(AL +"\r\n");
					bf.write(LHS +"\r\n");
					bf.write(TS +"\r\n");
					bf.close();
					f.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
		    }
		}
	}
	//ACTIONPERFORMED slutt
	
	public void oppdaterGUI(JList enliste,Object[] data)
	{
		DefaultListModel m = new DefaultListModel();
		for(Object s:data)
		{
			m.addElement(s);
		}
		enliste.setModel(m);
	}
	
}
		    