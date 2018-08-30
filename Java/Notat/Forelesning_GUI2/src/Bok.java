
public class Bok {

	private String tittel;
	public String getTittel()
	{
		return tittel;
	}
	
	public void setTittel(String tittel)
	{
		this.tittel = tittel;
	}

	@Override
	public String toString() {
		return "Bok [tittel=" + tittel + "]";
	}
}
