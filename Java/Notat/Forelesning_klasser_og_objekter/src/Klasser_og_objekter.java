import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Klasser_og_objekter {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		/*
		Boller mineboller = new Boller();
		
		for (int i = 1;i<=10;i=i+1)
		{
			Boller mineboller2 = new Boller();
		}
		
		JFrame mittvindu = new JFrame();
		mittvindu.setVisible(true);
		mittvindu.setSize(400, 400);
		mittvindu.setTitle("Tittel");
		
		JButton minknapp = new JButton();
		minknapp.setText("Trykk her");
		
		mittvindu.add(minknapp);
		
		
		Student student1 = new Student();
		student1.etternavn = "Vader";
		student1.fornavn = "Darth";
		student1.studentnummer = 12345;
		JOptionPane.showMessageDialog(null,student1.fornavn);
		
		Student student2 = new Student();
		student2.fornavn = "Luke";
		student2.etternavn = "Skywalker";
		student2.studentnummer = 54321;
		JOptionPane.showMessageDialog(null,student2.fornavn);
		JOptionPane.showMessageDialog(null,student2.utdannelse);
		
		String helenavnet = student2.getFulltnavn();
		JOptionPane.showMessageDialog(null,helenavnet);
		*/
		
		Bankkonto minkonto = new Bankkonto();
		minkonto.saldo = 1000;
		minkonto.eier = "Jonas";
		JOptionPane.showMessageDialog(null,minkonto.eier);
		
		String minkontoinfo = minkonto.getKontoinfo();
		JOptionPane.showMessageDialog(null,minkontoinfo);
		
	}

}
