import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

import javax.swing.JTextField;

public abstract class kryssordFelt extends JTextField implements MouseMotionListener{

	public kryssordFelt()
	{
		this.addMouseMotionListener(this);
	}
	
	abstract public void start();
	
	@Override
	public void mouseDragged(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub
		this.start();
	}

}
