
public class Hero {

	private String fornavn;
	private String etternavn;
	
	public String getFornavn()
	{
		return fornavn;
	}
	public void setFornavn(String fornavn)
	{
		this.fornavn = fornavn;
	}
	public String getEtternavn()
	{
		return etternavn;
	}
	public void setEtternavn(String etternavn)
	{
		this.etternavn = etternavn;
	}
	
	@Override
	public String toString() {
		return "Hero [fornavn=" + fornavn + ", etternavn=" + etternavn + "]";
	}
	
	
	
}
