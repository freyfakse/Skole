
public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//Konverterer k = new Konverterer();
		//int tall = k.kilometerTilMeter(10);
		
		//int tall = Konverterer.kilometerTilMeter(10);
		//System.out.println(tall);
		
		/*
		Vanlig forste = new Vanlig();
		Vanlig andre = new Vanlig();
		
		forste.entekst = "hei";
		
		System.out.println("Første " +forste.entekst);
		System.out.println("Andre " +andre.entekst);
		*/
		Singleton forste = Singleton.getInstance();
		Singleton andre = Singleton.getInstance();
		
		forste.entekst = "hei";
		System.out.println("Første " +forste.entekst);
		System.out.println("Andre " +andre.entekst);
	}

}
