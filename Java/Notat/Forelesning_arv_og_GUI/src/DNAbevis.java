import javax.swing.JOptionPane;

public class DNAbevis extends Bevis {

	public int kvalitet;
	
	public DNAbevis()
	{
		String kvalitet_tekst = JOptionPane.showInputDialog(null, "Kvalitet?");
		this.kvalitet = Integer.parseInt(kvalitet_tekst);
	}
}
