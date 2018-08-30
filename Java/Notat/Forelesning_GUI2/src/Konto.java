import javax.swing.JOptionPane;

public class Konto {

	private int saldo = 0;
	public void setSaldo(int saldo)
	{
		if(saldo>0)
		{
			this.saldo = saldo;
		}
		
		else
		{
			JOptionPane.showMessageDialog(null, "Skaff mer penger.");
		}
	}
	public int getSaldo()
	{
		return this.saldo;
	}
}
