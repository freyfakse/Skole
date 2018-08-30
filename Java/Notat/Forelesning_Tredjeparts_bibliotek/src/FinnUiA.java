import java.awt.FlowLayout;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;

import twitter4j.GeoLocation;
import twitter4j.IDs;
import twitter4j.Query;
import twitter4j.QueryResult;
import twitter4j.Status;
import twitter4j.Twitter;
import twitter4j.TwitterException;
import twitter4j.TwitterFactory;
import twitter4j.User;
import twitter4j.conf.ConfigurationBuilder;


public class FinnUiA extends JFrame{
	public FinnUiA(){
		JTextArea tekst = new JTextArea();
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		this.add(tekst);
		this.setVisible(true);
		ConfigurationBuilder cb = new ConfigurationBuilder();
		
		cb.setOAuthConsumerKey("xMHpFFhCUgiffiUTf1RlZQ");
		cb.setOAuthConsumerSecret("LnrvRmG6VuxZpB0mVq4IzAd0Zj0QBnjwOwTk5oQVUs8");
		cb.setOAuthAccessToken("1057306374-mukHk9K2JWnCJdxVduijZG6azHZ9qpJZi7CxIY3");
		cb.setOAuthAccessTokenSecret("dM7pot5bGf30EqDJjQtCi4pAXkRbIitpyVnFNpISQL4");
		
		TwitterFactory tf = new TwitterFactory(cb.build());
		Twitter twitter = tf.getInstance();
		Query query = new Query();
		GeoLocation geo = new GeoLocation(58.34,8.59);
		query.setGeoCode(geo, 100, Query.KILOMETERS);
		
		try {
			QueryResult result = twitter.search(query);
			for(Status s:result.getTweets()){
				tekst.setText(tekst.getText() + s.getText() + "\n");
			}
		} catch (TwitterException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			IDs s = twitter.getFollowersIDs(-1);
			for(long id:s.getIDs()){
				User bruker = twitter.showUser(id);
				this.leggTilBilde(bruker.getProfileImageURL());
			}
			this.validate();
		} catch (TwitterException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

	public void leggTilBilde(String url){
		try {
			URL u = new URL(url);
			BufferedInputStream b = new BufferedInputStream(u.openStream());
			Image img = ImageIO.read(b);
			ImageIcon ii = new ImageIcon(img);
			JLabel l = new JLabel(ii);
			this.add(l);
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}