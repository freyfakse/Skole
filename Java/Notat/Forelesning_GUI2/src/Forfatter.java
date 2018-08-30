
public class Forfatter {

	private String navn;
	private int bibliografi;
	
	public String getNavn()
	{
		return navn;
	}
	
	public void setNavn(String navn)
	{
		this.navn = navn;
	}
	
	public int getBibliografi()
	{
		return bibliografi;
	}
	
	public void setBibliografi(int bibliografi)
	{
		this.bibliografi = bibliografi;
	}

	@Override
	public String toString() {
		return "Forfatter [navn=" + navn + ", bibliografi=" + bibliografi + "]";
	}

}
