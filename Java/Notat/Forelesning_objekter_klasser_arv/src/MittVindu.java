import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class MittVindu extends JFrame implements ActionListener{

	public String svar = "Jordbær"; //Offentlig variabel
	JButton knapp = new JButton();
	JButton knapp2 = new JButton();
	JButton Superknappen = new JButton();
	
	public MittVindu()
	{
		this.setVisible(true);
		FlowLayout f = new FlowLayout();
		this.setLayout(f);
		
		knapp.setText("Trykk her");
		this.add(knapp);
		knapp.addActionListener(this);
		
		knapp2.setText("Fasit");
		this.add(knapp2);
		knapp2.addActionListener(this);
		
		Superknappen.setText("Superknappen");
		this.add(Superknappen);
		Superknappen.addActionListener(this);
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent e)
	{
		// TODO Auto-generated method stub
		if(e.getSource().equals(knapp))
		{
		String brukersvar = JOptionPane.showInputDialog(this,"Gjett bær"); //Lokal variabel
		if(brukersvar.equals(this.svar))
		{
			JOptionPane.showMessageDialog(this, "Riktig");
		}
		JOptionPane.showMessageDialog(this,"Hei på deg");
		}
		if(e.getSource().equals(knapp2))
		{
			JOptionPane.showMessageDialog(this,this.svar);
		}
		if(e.getSource().equals(Superknappen))
		{
			JOptionPane.showMessageDialog(this, "Du har trykket på superknappen");
		}
		
	}
}
