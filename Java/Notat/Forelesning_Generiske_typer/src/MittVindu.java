import java.awt.FlowLayout;
import java.util.TreeSet;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;

public class MittVindu extends JFrame{

	JList listen = new JList();
	TreeSet<Person> a = new TreeSet<person>();
	
	public MittVindu()
	{
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		/*
		a.add(20);
		a.add(40);
		a.add(60);
		a.add(39);
		*/
		Person p1 = new Person("Morten","@mortis");
		Person p2 = new Person("Nissen","@Nissen");
		
		a.add(p1);
		a.add(p2);
		
		this.oppdaterGUI(listen, a.toArray());
	}
	
	public void oppdaterGUI(JList enliste,Object[] data)
	{
		DefaultListModel m = new DefaultListModel();
		for(Object s:data)
		{
			m.addElement(s);
		}
		enliste.setModel(m);
	}
}
