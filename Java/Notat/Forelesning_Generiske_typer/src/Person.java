
public class Person implements Comparable<Person>{

	private String navn;
	private String handle;
	
	public Person(String navn, String handle) {
		super();
		this.navn = navn;
		this.handle = handle;
	}

	@Override
	public String toString() {
		return navn +handle;
	}

	@Override
	public int compareTo(Person o) {
		// TODO Auto-generated method stub
		if(this.handle.equals(o.handle)&&this.navn.equals(o.navn))
		{
			return 0;
		}
		else
		{
			return 1;
		}
		
	}
	
	
}
