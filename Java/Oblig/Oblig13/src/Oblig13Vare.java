import java.io.Serializable;

public class Oblig13Vare implements Serializable{

	private String type;
	private String navn;
	private String pris;
	
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getNavn() {
		return navn;
	}
	public void setNavn(String navn) {
		this.navn = navn;
	}
	public String getPris() {
		return pris;
	}
	public void setPris(String pris) {
		this.pris = pris;
	}
	
	@Override
	public String toString() {
		return "type=" + type + ", navn=" + navn + ", pris=" + pris;
	}
	
	
}
