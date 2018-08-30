
public class Singleton {

	public String entekst = "";
	
	private static final Singleton s = new Singleton();
	
	public static Singleton getInstance()
	{
		return s;
	}
}
