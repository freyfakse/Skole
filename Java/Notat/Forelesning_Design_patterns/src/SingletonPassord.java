
public class SingletonPassord {

	private static final SingletonPassord s = new SingletonPassord();
	public static SingletonPassord getInstance()
	{
		return s;
	}
	
	private String passord = "hemmelig";
	//ufullstendig
}
