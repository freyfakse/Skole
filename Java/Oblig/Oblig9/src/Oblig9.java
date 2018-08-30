import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;

public class Oblig9 extends JFrame implements ActionListener { 
	
	
	DefaultListModel<Oblig9Brus> BrusModel = new DefaultListModel<Oblig9Brus>();
	
	JButton leggTil = new JButton();
	
	JButton sok = new JButton();
	
	JButton best = new JButton();
	
	JLabel toppPoeng = new JLabel();
		
	 public Oblig9(){
     this.setVisible(true);
	
	 FlowLayout F = new FlowLayout();
	 this.setLayout(F);
	 this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	 JList liste = new JList(BrusModel);
	 this.add(liste);
	 this.setVisible(true);
	 
	 leggTil.setText("Legg til julebrus");
		this.add(leggTil);
		leggTil.addActionListener(this);
		
		
     sok.setText("Søk");
	     this.add(sok);
		 sok.addActionListener(this);
	 
	 best.setText("Beste brus");
	     this.add(best);
	     best.addActionListener(this);
	     
	 this.add(toppPoeng);
		
	
 }


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
       
		int topp = -1;
		int poengsjekk = -0;
		
		if(e.getSource().equals(leggTil)){
		
			
    	String leggTil = JOptionPane.showInputDialog(this, "Legg til brusmerke");
    	String poengsomtekst = JOptionPane.showInputDialog(this, "Poengsum");
    	int poeng = Integer.parseInt(poengsomtekst);
        
    	Oblig9Brus b = new Oblig9Brus();
        b.setBrus(leggTil);
        b.setPoeng(poeng);
        BrusModel.addElement(b);
		
        
		}

    	
		
		if(e.getSource().equals(sok)){
         String sokTekst = JOptionPane.showInputDialog(null, "Hvilken brus vil du sÃ¸ke etter?" );
        
         for(int i=0;i<BrusModel.getSize();i++){
         Oblig9Brus enBrus = BrusModel.getElementAt(i);
         
         
         if (sokTekst.equalsIgnoreCase(enBrus.getBrus())){
        	 JOptionPane.showMessageDialog(this, enBrus.getBrus() + "Poeng" +enBrus.getPoeng() + " er en veldig god brus");
         }
         
         }
    	 }
        
        if(e.getSource().equals(best)){
        for(int i=0;i<BrusModel.size();i++)	{
        	
        if(poengsjekk<BrusModel.get(i).getPoeng()){
        	poengsjekk=BrusModel.get(i).getPoeng();
        	topp = i;
        }
        }
        toppPoeng.setText(BrusModel.get(topp)+".");
        }
	}
}