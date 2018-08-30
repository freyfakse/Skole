import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;

public class GUI extends JFrame implements Runnable,ActionListener{

	DefaultListModel<Integer> m = new DefaultListModel<Integer>();
	JList liste = new JList();
	JButton knapp = new JButton();
	
	public GUI()
	{
		this.setLayout(new FlowLayout());
		this.add(liste);
		this.add(knapp);
		knapp.addActionListener(this);
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true)
		{
			Random rg = new Random();
			int tall = rg.nextInt(10);
			m.addElement(tall);
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}


}
