import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JOptionPane;

public class MittVindu extends JFrame implements ActionListener{
JButton leggtil = new JButton();
DefaultListModel<Forfatter> forfattermodel = new DefaultListModel<Forfatter>();
DefaultListModel<Bok> bokmodel = new DefaultListModel<Bok>();

	public MittVindu()
	{
		FlowLayout f = new FlowLayout();
		this.setLayout(f);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		/*
		String[] valg = new String[3];
		valg[0] = "Americano";
		valg[1] = "Espresso";
		valg[2] = "Latte";
		
		JList liste = new JList(valg);
		
		this.add(liste);
		*/
		
		
		leggtil.setText("legg til forfatter");
		this.add(leggtil);
		leggtil.addActionListener(this);
		
		
		
		JList liste = new JList(forfattermodel);
		this.add(liste);
		
		JList liste2 = new JList(bokmodel);
		this.add(liste2);
		
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(leggtil))
		{
			Forfatter f = new Forfatter();
			String navn = JOptionPane.showInputDialog(this,"Skriv forfatter");
			String antall = JOptionPane.showInputDialog(this,"Skriv antall bøker");
			int antallbok = Integer.parseInt(antall);
			String navnBok = JOptionPane.showInputDialog(this,"Skriv tittel");
			f.setNavn(navn);
			f.setBibliografi(antallbok);
			forfattermodel.addElement(f);
			
			Bok b = new Bok();
			b.setTittel(navnBok);
			bokmodel.addElement(b);
		}
	}
}
