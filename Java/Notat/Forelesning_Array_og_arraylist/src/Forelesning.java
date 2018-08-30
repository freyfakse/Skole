import java.awt.Point;
import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Forelesning {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/*array
		//variabeltype[] navn = new variabeltype[størrelse];
		double[] tid  = new double[3];
		tid[0] = 10.21;
		tid[1] = 10.30;
		tid[2] = 10.25;
		
		JOptionPane.showMessageDialog(null, "Første løp på: " +tid[0]);
		
		String[] sw = new String[3];
		sw[0] = "Luke";
		sw[1] = "Leia";
		sw[2] = "Anakin";
		
		String[] sw2 = {"Luke","Leia","Anakin"};
		
		 int svar = JOptionPane.showOptionDialog (null,"Slemmest?","Star Wars",0,0,null,sw,sw[0]);
		 JOptionPane.showMessageDialog(null, "Du svarte: " +sw[svar]);
		 
		 //Arraylist
		 //ArrayList<variabeltype> navn = new ArrayList<variabeltype>();
		 ArrayList<String> navneliste = new ArrayList<String>();
		 navneliste.add("Luke");
		 navneliste.add("Leia");
		 navneliste.add("Han Solo");
		 navneliste.remove("Leia");
		 String s = JOptionPane.showInputDialog(null,"Skriv navn:");
		 navneliste.add(s);
		 
		 for(int i=0;i<navneliste.size();i=i+1)
		 {
			 //String d = navneliste.get(i);
			 //JOptionPane.showMessageDialog(null, d);
			 JOptionPane.showMessageDialog(null, navneliste.get(i));
		 }
		 
		 System.out.println(navneliste);
		 
		 ArrayList<String> Handleliste = new ArrayList<String>();
		 String vare = JOptionPane.showInputDialog(null,"Skriv inn vare:");
		 Handleliste.add(vare);
		 System.out.println(Handleliste);
		 
		 String forstevare = Handleliste.get(0);
		 System.out.println(forstevare);
		 
		 double[] loep  = new double[3];
			loep[0] = 10.21;
			loep[1] = 10.30;
			loep[2] = 10.25;
			
			for(int i=0; i<loep.length ; i = i+1)
			{
				JOptionPane.showMessageDialog(null, loep[i]);
			}
			
			double minste = Integer.MAX_VALUE;
			for (int i=0;i<loep.length;i=i+1)
			{
				if(loep[i]<minste)
				{
					minste = loep[i];
				}
			}
			JOptionPane.showMessageDialog(null, "Minste er: " +minste);
			
			
			double meste = 0;
			for (int i=0;i<loep.length;i=i+1)
			{
				if(loep[i]>meste)
				{
					meste = loep[i];
				}
			}
			JOptionPane.showMessageDialog(null, "Største tallet er: " +meste);
				
			Point p = new Point();
			p.x =13;
			p.y =29;
			
			ArrayList<Point> punkter = new ArrayList<Point>();
			Point p1 = new Point();
			p1.x = 14;
			p1.y = 30;
			
			*/
			Vindu v = new Vindu();

	}

}
