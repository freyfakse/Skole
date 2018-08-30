import java.net.MalformedURLException;
import java.net.URL;
 
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
 
 
public class Boller extends JFrame {
 
    public Boller(){
 
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(798, 471);
        URL u = null;
        try {
            u = new URL("http://www.morshjemmebakte.no/var/ezflow_site/storage/images/selskaper/orkla-food-ingredient/idun-sites/mors-hjemmebakte/oppskrifter/mors-beste-boller/1755579-1-nor-NO/Mors-beste-boller_article_image_723.jpg");
        } catch (MalformedURLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        if(u!=null){
            ImageIcon i = new ImageIcon(u);
            System.out.println(i.getIconWidth());
            System.out.println(i.getIconHeight());
            JLabel l = new JLabel(i);
            this.add(l);
        }
        this.setVisible(true);
 
    }
 
}