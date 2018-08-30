import java.util.HashMap;

import javax.swing.JOptionPane;

public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/*
		ArrayList<Integer> l = new ArrayList<Integer>();
		l.add(20);
		System.out.println(l.get(0)); //O(1)
		
		l.add(12);
		l.add(59);
		for(int i = 0;i<l.size();i++) //O(n)
		{
			if(l.get(i)<20)
			{System.out.println(l.get(i));}
		}
		
		int[] minliste = new int[10];
		minliste[0] = 12;
		minliste[1] = 14;
		System.out.println(minliste[0]);
		
		for(int i = 0;i<minliste.length;i++)
		{
			System.out.println(minliste[i]);
		}
		
		
		LinkedList<Integer> minlinkedlist = new LinkedList<Integer>();
		minlinkedlist.add(10);
		minlinkedlist.add(50);
		minlinkedlist.add(20);
		
		for(Integer integer : minlinkedlist)
		{
			System.out.println(integer);
		}
		
		
		ArrayList a = new ArrayList();
		a.add(20);
		a.add("hei");
		int i = (int) a.get(1);//Går ikke, hei er String
		
		System.out.println(i);
		*/
		
		//new MittVindu();
		
		/*
		//HashSet<Integer> mittsett = new HashSet<Integer>();
		//LinkedHashSet<Integer> mittsett = new LinkedHashSet<Integer>();
		TreeSet<Integer> mittsett = new TreeSet<Integer>();
		mittsett.add(10);
		mittsett.add(50);
		mittsett.add(20);
		mittsett.add(10);
		
		System.out.println("HashSet");
		for(Integer i2:mittsett)
		{
			System.out.println(i2);
		}
		*/
		
		HashMap<String,String> brukernavnpassord = new HashMap<String,String>();
		brukernavnpassord.put("kylo", "ben");
		brukernavnpassord.put("Snoke", "plagueis");
		
		String brukernavn = JOptionPane.showInputDialog(null,"brukernavn?");
		String passord = JOptionPane.showInputDialog(null,"passord?");
		if(brukernavnpassord.get(brukernavn).equals(passord))
		{
			System.out.println("riktig");
		}
		else
		{
			System.out.println("feil");
		}
		
	}}
