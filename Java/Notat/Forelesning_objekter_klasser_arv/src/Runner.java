import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/* public class klassenavn
		 * {
		 * kode;
		 * metoder;
		 * }
		 */
		
		/*public interface interfacenavn
		 * {
		 * regler;
		 * }
		 */
		
		/*		Hund porthos = new Hund();
		//porthos.snakk();
		
		Katt lurifaks = new Katt();
		//lurifaks.snakk();
		
		ArrayList<Snakking> a = new ArrayList<Snakking>();
		a.add(lurifaks);
		a.add(porthos);
		Snakking etdyr = a.get(0);
		//Snakking etannetdyr = new Snakking 	FEIL ikke lov å lage objekt av interface.
		
		for (int i = 0; i < a.size(); i++) 
		{
			Snakking noe = a.get(i);
			noe.snakk();
		}
		
		
		MittVindu m = new MittVindu();
		*/
		
		boolean kjennerEier = true;
		int alder = 18;
		boolean harPeneSko = true;
		
		if (alder>=18 || kjennerEier == true)
		{
			JOptionPane.showMessageDialog(null, "Du kan komme inn");
		}
		
		if (alder>18 && harPeneSko==true)
		{
			JOptionPane.showMessageDialog(null, "Du kan komme inn");
		}
	}

}
