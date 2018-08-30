import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextPane;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;



public class GUI extends JFrame implements DocumentListener,ActionListener{
	JTextPane tekst = new JTextPane();
	JTextPane utenforkortelser = new JTextPane();
	JButton knapp = new JButton("Søk");
	
	public GUI(){
		FlowLayout f = new FlowLayout();
		this.setLayout(f);
		this.add(tekst);
		this.tekst.setPreferredSize(new Dimension(400,400));
		this.tekst.getDocument().addDocumentListener(this);
		this.tekst.setContentType("text/html");
		this.utenforkortelser.setPreferredSize(new Dimension(400,400));
		this.add(utenforkortelser);
		this.add(knapp);
		this.knapp.addActionListener(this);
		this.setVisible(true);
	}
	
	public String fjernForkortelser(String input){
		input = input.replace("osv.", "og så videre");
		input = input.replace("mm.", "med mer");
		return input;
	}
	
	public String leetSpeak(String input){
		input = input.replace("nybegynner", "n00b");
		input = input.replace("eid", "pwnd");
		return input;
	}
	
	public String markerOrd(String sokeOrd,String tekst){
		String nytekst = tekst.replace(sokeOrd,"<font color=\"red\">" + 
	           sokeOrd + "</font>");
		return nytekst;
	}

	@Override
	public void insertUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		String fratekst = this.tekst.getText();
		String nytekst = this.fjernForkortelser(fratekst);
		nytekst = this.leetSpeak(nytekst);
		this.utenforkortelser.setText(nytekst);
	}

	@Override
	public void removeUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void changedUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String ord = JOptionPane.showInputDialog(this,"Hvilket ord søker du etter?");
		String gammeltekst = this.tekst.getText();
		String nytekst = this.markerOrd(ord, gammeltekst);
		this.tekst.setText(nytekst);
	}
}