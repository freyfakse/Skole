import javax.swing.JOptionPane;

public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/*MittVindu m = new MittVindu();
		
		String entekst = JOptionPane.showInputDialog(null,"Skriv et tall");
		
		try
		{
			int ettall = Integer.parseInt(entekst);
			JOptionPane.showMessageDialog(null, ettall);
		}
		catch(NumberFormatException e)
		{
			JOptionPane.showMessageDialog(null, "ugyldig tall");
		}
		
		int[] tall = new int[10];
		try
		{
		tall[13] = 12;
		}
		
		catch(ArrayIndexOutOfBoundsException e)
		{
			JOptionPane.showMessageDialog(null, "Utenfor array");
		}
		
		try {
			tall[123]=123;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		*/
		
		Bankkonto b = new Bankkonto();
		try {
			b.setSaldo(-222);
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			JOptionPane.showMessageDialog(null, "Ugyldig saldo");
		}
		
	}

}
