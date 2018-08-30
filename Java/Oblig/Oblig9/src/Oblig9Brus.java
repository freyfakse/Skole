import javax.swing.DefaultListModel;
import javax.swing.JButton;

public class Oblig9Brus {
	private String brus;
	private int poeng;
	public String getBrus() {
		return brus;
	}
	public void setBrus(String brus) {
		this.brus = brus;
	}
	public int getPoeng() {
		return poeng;
	}
	public void setPoeng(int poeng) {
		this.poeng = poeng;
	}
	@Override
	public String toString() {
		return brus + ":  " + poeng + " Poeng ";
	}
}