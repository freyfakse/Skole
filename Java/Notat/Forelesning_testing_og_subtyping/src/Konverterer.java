
public class Konverterer {

	public int kmTilm(int km)
	{
		return km*1000;
	}
	
	public double utslipp(double km,String type)
	{
		if(type.equals("elbil"))
		{
			return 0;
		}
		
		if(type.equals("bensin"))
		{
			return km*0.12;
		}
		
		if(type.equals("diesel"))
		{
			return km*0.09;
		}
		
		return 0;
		
	}
	
	public double konverterValuta (double nok,double kurs)
	{
		
		return nok/kurs;
	}
	
	public boolean evigloop()
	{
		boolean sann = true;
		while(sann)
		{
			System.out.println("blabla");
		}
		return true;
	}
	
	/**
	 * Funksjon som oversetter fra dollar til kroner
	 * @deprecated bruk dollarTilKroner()
	 * @param dollar antall
	 * @return antall kroner
	 */
	
}
