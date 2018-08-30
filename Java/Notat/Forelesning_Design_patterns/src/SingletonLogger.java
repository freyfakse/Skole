
public class SingletonLogger {

	private static final SingletonLogger s = SingletonLogger();
	public static SingletonLogger getInstance()
	{
		return s;
	}
	
	int tall =0;
	public void logData(String data)
	{
		System.out.println("tall" +data);
	}
}
