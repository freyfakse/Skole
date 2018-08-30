import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.imageio.ImageIO;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;


public class MittVindu extends JFrame implements ActionListener{
	
	JButton knapp = new JButton("Last inn bilde");
	JButton leggtil = new JButton("Legg til");
	JButton lagre = new JButton("Lagre");
	JButton aapne = new JButton("Åpne");
	DefaultListModel m = new DefaultListModel();
	JList liste = new JList(m);

	public MittVindu(){
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		this.add(knapp);
		this.add(leggtil);
		this.add(lagre);

		this.add(aapne);
		this.add(liste);
		knapp.addActionListener(this);
		leggtil.addActionListener(this);
		lagre.addActionListener(this);
		aapne.addActionListener(this);
		
		this.setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(aapne)){
			try {
				FileInputStream f = new FileInputStream("timelist.txt");
				ObjectInputStream o = new ObjectInputStream(f);
				this.m = (DefaultListModel) o.readObject();
				liste.setModel(m);
				
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
		if(e.getSource().equals(lagre)){
			try {
				FileOutputStream f = new FileOutputStream("timelist.txt");
				ObjectOutputStream o = new ObjectOutputStream(f);
				o.writeObject(this.m);
				o.close();
				f.close();
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		if(e.getSource().equals(leggtil)){
			Ansatt t = new Ansatt();
			t.setNavn("Morten");
			t.setTimer(100);
			m.addElement(t);
		}
		if(e.getSource().equals(knapp)){
			try {
				FileInputStream f = new FileInputStream("bb8.jpg");
				BufferedInputStream bf = new BufferedInputStream(f);
				Image img = ImageIO.read(bf);
				ImageIcon ii = new ImageIcon(img);
				JLabel l = new JLabel(ii);
				this.add(l);
				this.validate();
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}

}