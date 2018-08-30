
public class Bankkonto {
	public int kontonr;
	public String eier;
	public String kontotype;
	public int saldo;
	
	
	/**
	 * Gir tilbake informasjon om konto
	 * @return kontoinfo
	 */
	
	public String getKontoinfo()
	{
		String kontoinfo = this.eier +" " +this.kontotype;
		return kontoinfo;
	}
}
