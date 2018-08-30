import javax.swing.JOptionPane;

public class Oblig2 {
	public static void main(String[] args) {
		//Oppgave 1
String passord = JOptionPane.showInputDialog(null,"Tast inn passord: ");
JOptionPane.showMessageDialog(null,"Du har skrevet inn: "+passord);

		//Oppgave 2
String utlaan_tekst = JOptionPane.showInputDialog(null,"Hvor lenge har du lånt boken?");
int utlaan = Integer.parseInt(utlaan_tekst);

if(utlaan>4)
{
System.out.println("Lever boken tilbake.");
	}

if(utlaan<4)
{
System.out.println("Du kan låne boken lenger.");
	}

if(utlaan == 4)
{
System.out.println("Lever idag.");
	}

		//Oppgave 3
String sosmed_tekst = JOptionPane.showInputDialog(null,"Hvor lenge bruker du på sosiale medier daglig?");
int sosmed = Integer.parseInt(sosmed_tekst);

if(sosmed>2)
{
System.out.println("For mye.");
	}

if(sosmed<2)
{
System.out.println("For lite.");
	}

if(sosmed==2)
{
System.out.println("Akkurat passe.");
	}
	
}

}
