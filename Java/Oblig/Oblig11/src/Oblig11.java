import java.awt.Dimension;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JTextPane;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class Oblig11 extends JFrame implements DocumentListener{

	JTextPane tekst = new JTextPane();
	JTextPane utenforkortelser = new JTextPane();
	
	public Oblig11()
	{
		FlowLayout f = new FlowLayout();
		this.setLayout(f);
		this.setVisible(true);
		
		this.add(tekst);
		this.add(utenforkortelser);
		this.tekst.setPreferredSize(new Dimension (400,400));
		this.utenforkortelser.setPreferredSize(new Dimension(400,400));
		tekst.getDocument().addDocumentListener(this);
		this.utenforkortelser.setContentType("text/html");
	}

	public String fjernForkortelser(String input)
	{
		input = input.replace("jeg", "<font color=\"Green\">"+"eg"+ "</font>");
		input = input.replace("dere", "<font color=\"Green\">"+"dykk"+ "</font>");
		input = input.replace("ikke","<font color=\"Green\">"+"ikkje"+ "</font>");
		return input;
	}
	
	@Override
	public void changedUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void insertUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		String fratekst = this.tekst.getText();
		String nytekst =this.fjernForkortelser(fratekst);
		this.utenforkortelser.setText(nytekst);
	}

	@Override
	public void removeUpdate(DocumentEvent e) {
		// TODO Auto-generated method stub
		
	}
}
