import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class Oblig16Test {

	Oblig16 k =  new Oblig16();
	@Before
	public void setup()
	{
		k =  new Oblig16();
	}
	
	@Test
	public void TestkonverterTilEuro()
	{
		assertEquals(1.0377367,k.konverterTilEuro(10, 1),0);
		assertEquals(8.97424392,k.konverterTilEuro(10, 2),0.1);
		assertEquals(0.078255407,k.konverterTilEuro(10, 3),0.1);
		
		assertTrue(1.0377367 == k.konverterTilEuro(10, 1));
		assertTrue(8.97424392 == k.konverterTilEuro(10, 2));
		assertTrue(0.078255407 == k.konverterTilEuro(10, 3));
	}
	
	@Test
	public void TestkonverterFraEuro()
	{
		assertEquals(96.3635577,k.konverterFraEuro(10, 1),0.1);
		assertEquals(11.14300,k.konverterFraEuro(10, 2),0.1);
		assertEquals(1277.86697,k.konverterFraEuro(10, 3),0.1);
		
		assertTrue(96.3635577 == k.konverterFraEuro(10, 1));
		assertTrue(11.14300 == k.konverterFraEuro(10, 2));
		assertTrue(1277.86697 == k.konverterFraEuro(10, 3));
	}
	
	@Test
	public void Testkonverter()
	{
		assertEquals(0,k.konverter(10, 1),0.1);
		assertEquals(0,k.konverter(10, 2),0.1);
		assertEquals(0,k.konverter(10, 3),0.1);
	}
	
	@After
	public void finished()
	{
		System.out.println("Ferdig med testing.");
	}
	
}
