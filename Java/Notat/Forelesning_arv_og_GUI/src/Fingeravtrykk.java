import javax.swing.JOptionPane;

public class Fingeravtrykk extends Bevis {

	public String finger;
	
	public Fingeravtrykk()
	{
		this.finger = JOptionPane.showInputDialog("Velg finger:");
	}
}
