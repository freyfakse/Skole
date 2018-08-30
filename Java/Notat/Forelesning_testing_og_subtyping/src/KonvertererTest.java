import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class KonvertererTest {

	
	Konverterer k =  new Konverterer();
	@Before
	public void setup()
	{
		k =  new Konverterer();
	}
	
	@Test
	public void test() {
		//Konverterer k =  new Konverterer();
		if(k.kmTilm(1)!=1000)
		{
		fail("Not yet implemented");
		}
	}
	
	@Test
	public void test2()
	{
		//Konverterer k = new Konverterer();
		assertTrue(1000==k.kmTilm(1));
	}

	@Test
	public void test3()
	{
		//Konverterer k = new Konverterer();
		assertEquals(1000,k.kmTilm(1),0);
	}
	
	@Test
	public void test4()
	{
		//Konverterer k = new Konverterer();
		assertEquals(0,k.utslipp(100, "elbil"),0.01);
		assertEquals(12,k.utslipp(100, "bensin"),0.01);
	}
	
	@Test
	public void testvaluta()
	{
		//Konverterer k = new Konverterer();
		double kurs = 7.0;
		double kroner = 100;
		double dollar = k.konverterValuta(kroner,kurs);
		assertEquals(14.28,dollar,0.1);
	}
	
	@Test(timeout=1000)
	public void testevigloop()
	{
		//Konverterer k = new Konverterer();
		if(!k.evigloop())
		{
			fail();
		}
	}
	
	@After
	public void finished()
	{
		System.out.println("Ferdig med testing.");
	}
	
}
