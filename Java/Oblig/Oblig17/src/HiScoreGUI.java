import java.awt.FlowLayout;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;

public class HiScoreGUI extends JFrame{

	public DefaultListModel m = new DefaultListModel();
	public JList HS = new JList(m);
	
	public HiScoreGUI()
	{
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		this.setTitle("Kurwa");
		this.setSize(100,400);
		
		this.add(HS);
		load();
	}
	
	//Laste HS
		public void load()
		{
			try {
				FileInputStream f = new FileInputStream("High Score.txt");
				ObjectInputStream o = new ObjectInputStream(f);
				this.m = (DefaultListModel) o.readObject();
				HS.setModel(m);
				
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (ClassNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	
}
