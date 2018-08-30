import javax.swing.JOptionPane;

public class Oblig3Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/*Oppgave 1, 2, 3 og 4
		Oblig3Funksjoner f = new Oblig3Funksjoner();
		
		String kroner = JOptionPane.showInputDialog(null,"Oppgi NOK:");
		double nok= Double.parseDouble(kroner);
		double EUR = f.kronerTilEuro(nok);
		JOptionPane.showMessageDialog(null,EUR); */
		
		//Oppgave 5 og 6
		Oblig3Funksjoner f = new Oblig3Funksjoner();
		
		String kroner = JOptionPane.showInputDialog(null,"Oppgi NOK:");
		double nok= Double.parseDouble(kroner);
		
		double EUR = f.kronerTilEuro(nok);
		JOptionPane.showMessageDialog(null,EUR +" eur ");
		
		Double YEN = f.kronerTilYen(nok);
		JOptionPane.showMessageDialog(null,YEN +" yen");
		
		
	}

}
