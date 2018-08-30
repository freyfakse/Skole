import java.io.Serializable;

public class HiScore implements Serializable{

	private String Navn;
	private int poengsum;
	
	public String getNavn() {
		return Navn;
	}
	
	public void setNavn(String navn) {
		Navn = navn;
	}
	
	public int getPoengsum() {
		return poengsum;
	}
	
	public void setPoengsum(int poengsum) {
		this.poengsum = poengsum;
	}

	@Override
	public String toString() {
		return "HiScore [Navn=" + Navn + ", poengsum=" + poengsum + "]";
	}
	
	
	
}
