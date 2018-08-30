//Oppgave 9 og 10
public class Bintree {

	Node root = new Node();
	
	public boolean settInnVenstre(Node n,Node x)//n=forelder x=barn
	{
		if(n != null)
		{
			if(x != null)
			{
				if(x.getLeft() == null)
				{
					
					return true;
				}
			}
		}
		return false;
	}
	
	public void add(Node n)
	{
		
	}
}
