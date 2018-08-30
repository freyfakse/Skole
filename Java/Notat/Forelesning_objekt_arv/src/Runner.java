import java.util.Random;

import javax.swing.JOptionPane;

public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Random rg = new Random();
		//int tall = rg.nextInt(3); //0,1 eller 2
		//JOptionPane.showMessageDialog(null, "Tallet er: " +tall);
		
		int tall = rg.nextInt(2);
		
		/*
		if(tall == 0)
		{
			JOptionPane.showMessageDialog(null, "Pizza");
		}
		
		else
		{
			JOptionPane.showMessageDialog(null, "Taco");
		}
		
		
		for (int i=0;i<7;i++)
		{
			int lotto = rg.nextInt(37)+1;
			System.out.println(lotto);
		}
		*/
		
		//MittVindu M = new MittVindu();
		tetris t = new tetris();
	}
}
