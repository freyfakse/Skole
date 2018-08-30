import javax.swing.JOptionPane;

public class RopNavn implements Runnable{

	private String Navn;
	
	public RopNavn(String Navn)
	{
		this.Navn = Navn;
	}
	
	public void ropNavn()
	{
		for(int i=0;i<10;i++)
		{
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			JOptionPane.showMessageDialog(null, (Navn +" " +i));
		}
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		this.ropNavn();
	}
}
