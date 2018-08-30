import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPopupMenu;

public class MittVindu extends JFrame implements ActionListener,MouseListener{

	JPopupMenu Menubar = new JPopupMenu();
	//JMenuBar Menubar = new JMenuBar();
	JMenu fil = new JMenu("Fil");
	JMenuItem aapne = new JMenuItem("Åpne");
	JMenuItem lagre = new JMenuItem("Lagre");
	JMenu rediger = new JMenu("Rediger");
	JMenuItem angreL = new JMenuItem("Angre litt");
	JMenuItem angreM = new JMenuItem("Angre mye");
	
	public MittVindu()
	{
		//FlowLayout f = new FlowLayout();
		//GridLayout g = new GridLayout(2,2);
		BorderLayout b = new BorderLayout();
		this.setLayout(b);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(1000, 1000);
		
		//this.setJMenuBar(Menubar);
		this.Menubar.add(fil);
		this.fil.add(aapne);
		this.fil.add(lagre);
		this.Menubar.add(rediger);
		this.rediger.add(angreL);
		this.rediger.add(angreM);
		
		JButton Leonardo = new JButton("Leonardo");
		this.add(Leonardo,b.NORTH);
		JButton Donatello = new JButton("Donatello");
		this.add(Donatello,b.SOUTH);
		JButton Raphael = new JButton("Raphael");
		this.add(Raphael,b.EAST);
		JButton Michelangelo = new JButton("Michelangelo");
		this.add(Michelangelo,b.WEST);
		
		this.addMouseListener(this);
		lagre.addActionListener(this);
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource().equals(lagre));
		JOptionPane.showMessageDialog(this, "Du trykket lagre");
	}


	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		if(e.getButton()==e.BUTTON3 && e.getClickCount()==5)
		{
			this.Menubar.show(this, e.getX(), e.getY());
		}
	}


	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
