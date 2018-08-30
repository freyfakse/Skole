
public class Student {
	public int studentnummer;
	public String fornavn;
	public String etternavn;
	public String utdannelse = "Videregående";

	public int plussto(int x, int y)
	{
		int n = x+y;
		return n;
	}

	public String getFulltnavn()
	{
		String fulltnavn = this.fornavn + this.etternavn;
		return fulltnavn;
	}

}
