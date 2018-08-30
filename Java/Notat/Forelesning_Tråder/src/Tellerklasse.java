
public class Tellerklasse implements Runnable{

	String navn;
	public Tellerklasse(String navn)
	{
		this.navn = navn;
	}
	
	public void tellOppover()
	{
		for(int i=0;i<100;i++)
		{
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(navn +" " +i);
		}
	}
	

	@Override
	public void run() {
		// TODO Auto-generated method stub
		this.tellOppover();
	}
}
