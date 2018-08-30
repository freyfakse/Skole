//Oppgave 1 og 2
public class DobbelListe{
	
	private DobbelNode head = new DobbelNode();
	//private DobbelNode tail = new DobbelNode();
	
	public DobbelListe()
	{
		head.setNext(head);
		head.setPrev(head);
	}
	
	public void addFirst(DobbelNode n)
	{
		n.setPrev(head);
		
		if(head.getNext() == head)//Det finnes ingen elementer i lista
		{
			n.setNext(null);
			head.setNext(n);
		}
		
		else if(head.getNext() != head)//Det finnes elementer i lista
		{
			n.setNext(head.getNext());
			head.setNext(n);
			n.getNext().setPrev(n);
		}
	}
	
	public int antall()
	{
		int antall=0;
		DobbelNode mani = new DobbelNode();//Brukes for å manipulere lista
		
		mani = head;
		
		while(mani.getNext() != null)
		{
			if(head.getNext() == head)
			{
				return 0;
			}
			
			mani.setNext(mani.getNext().getNext());
			antall ++;
		}
		
		return antall;
	}
}
