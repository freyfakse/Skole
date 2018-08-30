import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JOptionPane;

public class Oblig13GUI extends JFrame implements ActionListener{

	JButton lagre = new JButton("Lagre");
	JButton aapne = new JButton("Åpne");
	JButton legg_til = new JButton("Legg til");
	JButton selg = new JButton("Selg");
	DefaultListModel m = new DefaultListModel();
	JList liste = new JList(m);
	
	public Oblig13GUI()
	{
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		
		this.add(lagre);
		lagre.addActionListener(this);
		this.add(aapne);
		aapne.addActionListener(this);
		this.add(legg_til);
		legg_til.addActionListener(this);
		this.add(selg);
		selg.addActionListener(this);
		
		this.add(liste);
		
		try {
			FileInputStream f = new FileInputStream("Vareliste.txt");
			ObjectInputStream o = new ObjectInputStream(f);
			this.m = (DefaultListModel) o.readObject();
			liste.setModel(m);
			
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

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(legg_til))
		{
			Oblig13Vare t = new Oblig13Vare();
			
			t.setType(JOptionPane.showInputDialog(null,"Type?"));
			if(t.getType().equals(""))
			{
				t.setType("N/A");
			}
			t.setNavn(JOptionPane.showInputDialog(null,"Navn?"));
			if(t.getNavn().equals(""))
			{
				t.setNavn("N/A");
			}
			t.setPris(JOptionPane.showInputDialog(null,"pris?"));
			if(t.getPris().equals(""))
			{
				t.setPris("N/A");
			}
			m.addElement(t);
		}
		
		if(e.getSource().equals(selg))
		{
			int index = liste.getSelectedIndex();
		    if(index >= 0)
		    {
		        m.removeElementAt(index);
		    }
		}
		
		if(e.getSource().equals(aapne))
		{
			try {
				FileInputStream f = new FileInputStream("Vareliste.txt");
				ObjectInputStream o = new ObjectInputStream(f);
				this.m = (DefaultListModel) o.readObject();
				liste.setModel(m);
				
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
		
		if(e.getSource().equals(lagre))
		{
			try {
				FileOutputStream f = new FileOutputStream("Vareliste.txt");
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
		
	}
}
