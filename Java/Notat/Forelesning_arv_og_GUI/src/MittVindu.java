import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class MittVindu extends JFrame {

	public MittVindu()
	{
		JOptionPane.showMessageDialog(null, "Nå lager vi vindu");
		this.setVisible(true);
		this.setTitle("Mitt supre fine vindu");
		
		//FlowLayout f = new FlowLayout();
		//this.setLayout(f);
		
		GridLayout g = new GridLayout(2,2);
		this.setLayout(g);
		
		JButton knapp1 = new JButton();
		knapp1.setText("Trykk på meg");
		this.add(knapp1);
		
		JButton knapp2 = new JButton();
		knapp2.setText("Nei, trykk på meg");
		this.add(knapp2);
		
		JLabel tekst = new JLabel();
		tekst.setText("Overskrift");
		this.add(tekst);
		
		ImageIcon i = new ImageIcon("kilde her");
		JLabel l2 = new JLabel();
		l2.setIcon(i);
		this.add(l2);
	}
	
}
