//Oppgave 1 og 2
public class Runner{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		DobbelListe liste = new DobbelListe();
		
		DobbelNode n = new DobbelNode(); //Node 1
		DobbelNode n2 = new DobbelNode(); //Node 2

		liste.addFirst(n); //Legger Node 1 i lista
		liste.addFirst(n2); //Legger Node 2 i lista
		System.out.println("Elementer i lista:");
		System.out.println(liste.antall());
	}

}
