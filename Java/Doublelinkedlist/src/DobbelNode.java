//Oppgave 1 og 2
public class DobbelNode {

	private int value = 0;
	private DobbelNode next = null;
	private DobbelNode prev = null;
	
	public DobbelNode()
	{
		//cons
	}
	
	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

	public DobbelNode getNext() {
		return next;
	}

	public void setNext(DobbelNode next) {
		this.next = next;
	}

	public DobbelNode getPrev() {
		return prev;
	}

	public void setPrev(DobbelNode prev) {
		this.prev = prev;
	}
}
